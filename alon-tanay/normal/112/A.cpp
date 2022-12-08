#include <iostream>
#include <string>

using namespace std;

int main() {
    string str1, str2;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> str1;
    cin >> str2;
    int len = str1.length();

    for(int i = 0; i < len; i ++) {
        char chr1 = tolower(str1[i]);
        char chr2 = tolower(str2[i]);
        if(chr1 < chr2) {
            cout << "-1";
            return 0;
        }
        if(chr1 > chr2) {
            cout << "1";
            return 0;
        }
    }
    cout << "0";
    return 0;
}