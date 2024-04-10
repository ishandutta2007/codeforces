#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(a, b) for(ll a = 0; a < (b); ++a)
#define pb push_back
#define st first
#define nd second
#define all(a) a.begin(), a.end()
#define lg(a) (31-__builtin_clz(a))
void solve() {
        int n;
        cin >> n;
        ll T[n];
        rep(i, n) cin >> T[i];
        sort(T, T+n);
        ll ans=0, odejmij=0;
        rep(i, n-1) ans+=T[i+1]-T[i];
        rep(i, n) {
                ans-=i*T[i]-odejmij;
                odejmij+=T[i];
        }
        cout << ans << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}