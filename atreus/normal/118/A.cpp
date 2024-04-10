#include <bits/stdc++.h>

using namespace std;

string smalize(string a){
    for (int i = 0; i < a.size(); i++){
        if (a[i] - 'Z' <= 0)
            a[i] = a[i] - 'A' + 'a';
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    s = smalize(s);
    for (int i = 0; i < s.size(); i++){
        if (s[i] != 'a' && s[i] != 'u' && s[i] != 'e' && s[i] != 'o' && s[i] != 'i' && s[i] != 'y')
            cout << "." << s[i];
    }
}