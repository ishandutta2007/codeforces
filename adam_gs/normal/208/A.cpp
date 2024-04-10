#include<bits/stdc++.h>
using namespace std;
#define rep(a, b) for(int a = 0; a < (b); ++a)
int main() {
    string x;
    cin >> x;
    string s="";
    rep(i, x.size()) {
        if(x[i]=='W' && x[i+1]=='U' && x[i+2]=='B') {
            i+=2;
            if(s.size()!=0) { cout << s << " "; s=""; }
        } else s+=x[i];
    }
    cout << s << " ";
}