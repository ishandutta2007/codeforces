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
const ll MOD=1e9+7;
ll pot(ll a, ll b) {
        ll ans=1;
        while(b) {
                if(b&1) ans=(ans*a)%MOD;
                a=(a*a)%MOD;
                b/=2;
        }
        return ans;
}
void solve() {
        int n, m;
        cin >> n >> m;
        int ile=0;
        rep(i, n) rep(j, m) {
                char x;
                cin >> x;
                if(x=='#') ++ile;
        }
        if(ile==0) {
                cout << "1\n";
                return;
        }
        ll ans=pot(2, ile);
        if(n*m==ile) {
                ans=(ans+MOD-1)%MOD;
        }
        cout << ans << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}