#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
void solve() {
    int n;
    string s;
    cin >> n >> s;
    if(n%2==1 || s[0]==')' || s.back()=='(') {
        cout << ":(\n";
        return;
    }
    s[0]='(';
    s[s.size()-1]=')';
    int ile=n/2-1;
    rep(i, n-2) if(s[i+1]=='(') --ile;
    if(ile<0) {
        cout << ":(\n";
        return;
    }
    rep(i, n-2) if(s[i+1]=='?' && ile) {
        s[i+1]='(';
        --ile;
    }
    rep(i, n) if(s[i]=='?') s[i]=')';
    int akt=0;
    rep(i, n-2) {
        if(s[i+1]=='(') ++akt; else --akt;
        if(akt<0) {
            cout << ":(\n";
            return;
        }
    }
    cout << s << '\n';
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int _=1;
    //cin >> _;
    while(_--) solve();
}