#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    string s, t;
    cin >> s;
    bool f = false;
    for(int i=0;i<5;i++){
        cin >> t;
        if(t[0] == s[0] || t[1] == s[1]) f = true;
    }
    if(f) cout << "YES";
    else cout << "NO";
}