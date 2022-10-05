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
int ask(int x, int y) {
    cout << "SCAN " << x << ' ' << y << endl;
    int a;
    cin >> a;
    return a;
}
int dist(int x1, int y1, int x2, int y2, int xx, int yy) {
    return abs(x1 - xx) + abs(y1 - yy) + abs(x2 - xx) + abs(y2 - yy);
}
void solve(int TC) {
    // cin >> n;
    // for(int i = 1; i <= n; i++) cin >> arr[i]; // 1 BASED!!
    int n, m;
    cin >> n >> m;
    int tl = ask(1, 1);
    int tr = ask(1, m);
    int avd = (tl + tr - (m - 1) * 2) / 2;
    int mm = (tl - avd) / 2;
    avd /= 2;
    avd++; mm++;
    int tm = ask(avd, mm);
    int mmm = m;
    int tmm = ask(avd, mmm);
    set<pair<pair<int, int>, pair<int, int>>> poss;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int ii = 1; ii <= n; ii++) {
                for(int jj = 1; jj <= m; jj++) {
                    if(ii == i && jj == j) continue;
                    if(tl != dist(i, j, ii, jj, 1, 1)) continue;
                    if(tr != dist(i, j, ii, jj, 1, m)) continue;
                    if(tm != dist(i, j, ii, jj, avd, mm)) continue;
                    if(tmm != dist(i, j, ii, jj, avd, mmm)) continue;
                    poss.insert(mp(mp(ii, jj), mp(i, j)));
                }
            }
        }
    }
    // assert(poss.size() <= 4);
    int lef = 2;
    for(auto x: poss) {
        cout << "DIG " << x.fi.fi << ' ' << x.fi.se << endl;
        int a;
        cin >> a;
        if(a == 0) continue;
        lef -= a;
        cout << "DIG " << x.se.fi << ' ' << x.se.se << endl;
        cin >> a;
        if(a == 0) continue;
        lef -= a;
        if(lef == 0) return;
    }
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;  
    cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    for(int i = 1; i <= t; i++) solve(i);
}