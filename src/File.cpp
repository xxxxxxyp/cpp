#include "File.h"

File::File(const string& name, const string& type, const string& owner, const uint64_t& inode, FileObj* parent)
    :FileObj(name, (parent ? parent->getPath() + name + "/" : "/"), type, owner, inode, parent), content("") {
}

// read and write
string File::read() const {
    // TODO: return file content
    // note 1: you can choose to printf content into stdout in this function or not (Optional)
    return content;
}

bool File::write(const string &data) { 
    //TODO: write data into file content, return true if write successfully, otherwise false
    // note 1: replace "\\n" into new line "\n"
    // for example, when you wrote "Hello PA-1\n" in command line, data will be "Hello PA-1\\n"
   string processed;
    size_t pos = 0;
    while (pos < data.size()) {
        // 匹配 \\n 转义字符
        if (data[pos] == '\\' && pos + 1 < data.size() && data[pos+1] == 'n') {
            processed += '\n';
            pos += 2;  // 跳过 \\ 和 n
        } else {
            processed += data[pos];
            pos += 1;
        }
    }
    content += processed;  // 追加模式
    return true;
}

string File::getContent() const {
    // TODO: retun file content
    fprintf(stderr, "Error: File::getContent() is not implemented yet!\n");
    assert(0);  
    return "";
}

// helper function
void File::display() const {
    std::cout << "[File: " << getName() << "] Size: " << content.length() << " bytes" << std::endl;
}
