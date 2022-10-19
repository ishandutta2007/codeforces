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
const int INF=1e9+7;
void solve() {
        ll n;
        cin >> n;
        ll k=1;
        ll ans=INF;
        vector<int>V;
        while(n) {
                V.pb(n%10);
                n/=10;
        }
        reverse(all(V));
        rep(i, 60) {
                ll x=k;
                vector<int>T;
                while(x) {
                        T.pb(x%10);
                        x/=10;
                }
                reverse(all(T));
                ll l=0;
                for(auto i : V) {
                        if(l<T.size() && i==T[l]) {
                                ++l;
                        }
                }
                k*=2;
                ans=min(int(ans), int(V.size()+T.size()-2*l));
        }
        cout << ans << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}