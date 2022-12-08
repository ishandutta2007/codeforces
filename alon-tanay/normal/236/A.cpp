#include <iostream>
#include <string>

using namespace std;

int main() {
    string name;
    bool appeared[26] = {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false};
    int girl = 1;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> name;
    int len = name.length();
    for(int i = 0; i < len; i ++) {
        if(!appeared[name[i]-97]) {
            appeared[name[i]-97] = true;
            girl = 1 - girl;
        }
    }
    cout << (girl ? "CHAT WITH HER!" : "IGNORE HIM!");
    return 0;
}