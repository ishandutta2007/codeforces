#include <bits/stdc++.h>

using namespace std;

string s, t;
string v = "aeiou";

int main(){
    cin >> s >> t;
    if(s.size() != t.size()){
        cout << "No" << endl;
        return 0;
    }
    for(int i = 0; i<s.size(); i++){
        bool b = (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u');
        bool c = (t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u');
        if(b != c){
            cout << "No" << endl;
            return 0 ;
        }
    }
    cout << "Yes" << endl;
}