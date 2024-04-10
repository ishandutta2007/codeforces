#include <bits/stdc++.h>

using namespace std;

bool ispalindrom(string s){
    string k = "";
    for(int i = s.length() - 1; i >= 0; i--){
        k += s[i];
    }
    if(s == k){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    string s;
    string m;
    bool ans = true;
    int k;
    cin >> s;
    cin >> k;
    if(s.length() % k == 0){
        for(int i = 0; i < s.length(); i += s.length() / k){
            m = "";
            for(int j = i; j < i + s.length() / k; j++) {
                m += s[j];
            }
            if(!ispalindrom(m)){
                cout << "NO";
                return 0;
            }
        }
    }
    else{
        cout << "NO";
        return 0;
    }
    cout << "YES";
}