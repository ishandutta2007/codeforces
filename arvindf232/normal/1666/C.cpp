#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
using namespace std;
const int maxn = 1000005; // REMEMBER TO CHANGE UPPER BOUND
int mod = 1000000007, mod2 = 998244353, n, fac[maxn + 5], invfac[maxn + 5], arr[maxn + 5];
void mod998() {swap(mod, mod2);}
bool isprime(int k) {
    for(int i = 2; i * i <= k; i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b) {
    if(b == 0) return 1; 
    int t = bm(a, b / 2); 
    return (b % 2 == 1 ? t * t % mod * a % mod : t * t % mod);
}
int inv(int a) {return bm(a, mod - 2);}
int ncr(int n, int r) {
    return (r > n ? 0LL : fac[n] * invfac[r] % mod * invfac[n - r] % mod);
}
void pre_fac(int n) {
    fac[0] = 1; for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
}
void pre_invfac(int n) {
    for(int i = 0; i <= n; i++) invfac[i] = inv(fac[i]);
}
vector<pair<pair<int, int>, pair<int, int>>> segment;
void makesegment(int x, int y, int nx, int ny) {
    if(x == nx && y == ny) return;
    segment.pb(mp(mp(x, y), mp(nx, ny)));
}
void solve(int TC) {
    pair<int, int> pt[3];
    for(int i = 0; i < 3; i++) cin >> pt[i].fi >> pt[i].se;
    int needx = 0, needy = 0;
    for(int i = 0; i < 3; i++) {
        needx += pt[i].fi;
        needy += pt[i].se;
    }
    needx -= min(pt[0].fi, min(pt[1].fi, pt[2].fi));
    needx -= max(pt[0].fi, max(pt[1].fi, pt[2].fi));
    needy -= min(pt[0].se, min(pt[1].se, pt[2].se));
    needy -= max(pt[0].se, max(pt[1].se, pt[2].se));
    for(int i = 0; i < 3; i++) {
        makesegment(pt[i].fi, pt[i].se, pt[i].fi, needy);
        makesegment(pt[i].fi, needy, needx, needy);
    }
    cout << segment.size() << '\n';
    for(auto x: segment) {
        cout << x.fi.fi << ' ' << x.fi.se << ' ' << x.se.fi << ' ' << x.se.se << '\n';
    }
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;  
    // cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    for(int i = 1; i <= t; i++) solve(i);
}