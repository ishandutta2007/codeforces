#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

bool div3(char a, char b, char c){
    if (a == '0')
        return false;
    int x = 0;
    x += a - '0';
    x *= 10;
    x += b - '0';
    x *= 10;
    x += c - '0';
    if (x % 8 == 0)
        return true;
    else
        return false;
}

bool div2(char a, char b){
    if (a == '0')
        return false;
    int x = 0;
    x += a - '0';
    x *= 10;
    x += b - '0';
    if (x % 8 == 0)
        return true;
    else
        return false;
}

bool div1(char a){
    int x = 0;
    x += a - '0';
    if (x % 8 == 0)
        return true;
    else
        return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    if (s.size() >= 3){
        for (int i = 0; i < s.size() - 2; i++){
            for (int j = i + 1; j < s.size() - 1; j++){
                for (int k = j + 1; k < s.size(); k++){
                    if (div3(s[i],s[j],s[k])){
                        cout << "YES" << endl;
                        cout << s[i] << s[j] << s[k] << endl;
                        return 0;
                    }
                }
            }
        }
    }
    if (s.size() >= 2){
        for (int i = 0; i < s.size() - 1; i++){
            for (int j = i + 1; j < s.size(); j++){
                if (div2(s[i], s[j])){
                    cout << "YES" << endl;
                    cout << s[i] << s[j] << endl;
                    return 0;
                }
            }
        }
    }
    if (s.size() >= 1){
        for (int i = 0; i < s.size(); i++){
            if (div1(s[i])){
                cout << "YES" << endl;
                cout << s[i] << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}