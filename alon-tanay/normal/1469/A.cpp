#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    string input;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for(int i = 0; i < t; i ++) {
        bool failed = false;
        bool before = true;
        
        cin >> input;
        int len = input.length();
        if(len%2) {
            cout << "NO" << endl;
            continue;
        }
        for(int j = 0; j < len; j ++) {
            if(input[j] != '?') {
                if(before) {
                    if(input[j] == '(') {break;}
                    before = false;
                    if(j == 0) {
                        failed = true;
                        break;
                    }
                    continue;
                }
                if(len-j-1 == 0) {
                    failed = true;
                    break;
                }
            }
        }
        cout << (failed ? "NO" : "YES") << endl;
    }
    return 0;
}