#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
void solve() {
        int a, b;
        string x;
        cin >> a >> b >> x;
        int n=a+b;
        rep(i, n) {
                if(x[i]=='?' && x[n-i-1]!='?') {
                        x[i]=x[n-i-1];
                }
        }
        rep(i, n) {
                if(x[i]!=x[n-i-1]) {
                        cout << "-1\n";
                        return;
                }
                if(x[i]=='0') --a;
                else if(x[i]=='1') --b;
        }
        if(a%2==1) {
                if(n%2==1 && x[n/2]=='?') {
                        x[n/2]='0';
                        --a;
                } else {
                        cout << "-1\n";
                        return;
                }
        } else if(b%2==1) {
                if(n%2==1 && x[n/2]=='?') {
                        x[n/2]='1';
                        --b;
                } else {
                        cout << "-1\n";
                        return;
                }
        }
        rep(i, n/2) {
                if(x[i]=='?') {
                        if(a>0) {
                                a-=2;
                                x[i]='0';
                                x[n-i-1]='0';
                        } else {
                                b-=2;
                                x[i]='1';
                                x[n-i-1]='1';
                        }
                }
        }
        string c=x;
        reverse(all(c));
        if(b==0 && a==0 && x==c) {
                cout << x << '\n';
        } else {
                cout << "-1\n";
        }
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}