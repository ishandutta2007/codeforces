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
    cout << "? 0 1" << endl;
    char x;
    cin >> x;
    if(x=='x') {
        cout << "! 1" << endl;
        return;
    }
    ll akt=1, l, r;
    while(true) {
        cout << "? " << akt << " "  << 2*akt << endl;
        cin >> x;
        if(x=='x') {
            l=akt+1;
            r=2*akt;
            break;
        }
        akt*=2;
    }
    ll p=l, k=r;
    while(p<k) {
        ll sr=(p+k)/2;
        cout << "? " << l-1 << " " << sr << endl;
        cin >> x;
        if(x=='x') k=sr; else p=sr+1;
    }
    cout << "! " << p << endl;
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int _=1;
    //cin >> _;
    //while(_--) solve();
    string s;
    cin >> s;
    while(s=="start") {
        solve();
        cin >> s;
    }
}