#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll def = 0, led = 0, snizh = 0, k;
    string s;
    string defs = "";
    cin >> s >> k;
    for(int i=0;i<s.length();i++) if(s[i] == '*') snizh++; else if(s[i] == '?') led++; else {def++;defs+=s[i];}
    if(def == k) cout << defs;
    else if((def-led-snizh <= k && def > k)){
        string buf = "";
        int todel = def-k;
        for(int i=0;i<s.length();i++){
            if((s[i] == '?' || s[i] == '*') && todel > 0) {buf.erase(buf.length()-1, 1);todel--;}
            if(!(s[i] == '?' || s[i] == '*')) buf+= s[i];
        }
        cout << buf;
    }
    else if((snizh > 0 && def < k)){
        string buf = "";
        int torep = k-def;
        for(int i=0;i<s.length();i++){
            if((s[i] == '*') && torep > 0) {for(int j=0;j<torep;j++) buf+=buf[buf.length()-1]; torep=0;}
            if(!(s[i] == '?' || s[i] == '*')) buf+= s[i];
        }
        cout << buf;
    }
    else cout << "Impossible";
}