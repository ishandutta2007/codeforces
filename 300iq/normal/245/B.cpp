#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    bool h = false;
    if(s[0] == 'f'){
        cout << "ftp://";
    }
    else {
        cout << "http://";
        h = true;
    }
    if(h) {
        cout << s[4];
        int i = 5;
        while(s[i] != 'r' || s[i + 1] != 'u') {
            cout << s[i];
            i++;
        }
        cout << ".ru";
        for(int j = i + 2; j < s.length(); j++) {
            if(j == i + 2){
                cout << "/";
            }
            cout << s[j];
        }
    }
    else {
        cout << s[3];
        int i = 4;
        while(s[i] != 'r' || s[i + 1] != 'u') {
            cout << s[i];
            i++;
        }
        cout << ".ru";
        for(int j = i + 2; j < s.length(); j++) {
            if(j == i + 2){
                cout << "/";
            }
            cout << s[j];
        }
    }


}