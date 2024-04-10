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
ll nwd(ll a, ll b) {
        if(!a) return b;
        return nwd(b%a, a);
}
void solve() {
        int n;
        string x;
        cin >> n >> x;
        map<pair<int,int>,int>mp;
        int a=0, b=0;
        rep(i, n) {
                if(x[i]=='D') ++a; else ++b;
                if(min(a, b)==0) {
                        cout << i+1 << " ";
                } else {
                        int p=nwd(a, b);
                        ++mp[{a/p, b/p}];
                        cout << mp[{a/p, b/p}] << " ";
                }
        }
        cout << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}