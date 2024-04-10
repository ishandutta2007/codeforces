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
const ll INF=1e9+7;
void solve() {
        int n;
        ll c;
        cin >> n >> c;
        ll a[n];
        rep(i, n) cin >> a[i];
        ll akt=0, dni=0, ans=(c+a[0]-1)/a[0];
        rep(i, n-1) {
                ll koszt, ndni=0;
                cin >> koszt;
                if(akt>=koszt) {
                        akt-=koszt;
                } else {
                        ll x=koszt-akt;
                        ndni=(x+a[i]-1)/a[i];
                        akt+=ndni*a[i]-koszt;
                }
                dni+=ndni+1;
                if(akt>=c) {
                        ans=min(ans, dni);
                } else {
                        ll x=c-akt;
                        ans=min(ans, dni+(x+a[i+1]-1)/a[i+1]);
                }
        }
        cout << ans << '\n';
}
int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        int _=1;
        cin >> _;
        while(_--) solve();
}