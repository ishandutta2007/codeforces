#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define x first
#define y second
//#define int ll
#define NAME ""

using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using ull = unsigned long long;

const int maxn = 1e6;
const int mod = 998244353;
const int M = 1e9 + 7;
const int inf = 1e9;
const ll inf64 = 1e18L;
const ld pi = acos((ld)-1.0);
const ld eps = (ld)1e-6;

int n, a[maxn];
ll s[maxn], S;
vi g[maxn];

void dfs(int v, int p) {
    s[v] = a[v];
    for(int to : g[v]) if(to != p) dfs(to, v), s[v] += s[to];
}

ll pw(ll a, ll b) {
    if(!b) return 1;
    if(b & 1) return a * pw(a, b - 1) % M;
    a = pw(a, b >> 1);
    return a * a % M;
}

ll fac[maxn + 1];

inline ll cnk(ll n, ll k) {
    if(n < k) return 0;
    return fac[n] * pw((fac[k] * fac[n - k]) % M, M - 2) % M;
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
    //freopen("in.txt", "r", stdin);
    fac[0] = 1;
    for(int i = 0; i < maxn; i++) fac[i + 1] = fac[i] * (i + 1) % M;

    int hi = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i], S += a[i], hi = max(hi, a[i]);
    for(int i = 1; i < n; i++) {
        int j; cin >> j; j--;
        g[j].pb(i);
    }
    dfs(0, -1);
    vll d;
    for(ll f = 1; f * f <= S; f++) if(S % f == 0) d.pb(f), d.pb(S / f);
    ll SS = S;
    vector<pll> p;
    for(ll f = 2; f * f <= SS; f++) if(SS % f == 0) {
        p.pb({f, 0});
        while(SS % f == 0) SS /= f, p.back().y++;
    }
    if(SS != 1) p.pb({SS, 1});
    for(int i = 0; i < n; i++) {
        ll nv = 1;
        for(pll r : p) for(int j = 0; j < r.y && s[i] % r.x == 0; j++) nv *= r.x, s[i] /= r.x;
        s[i] = nv;
    }
    sort(s, s + n);
    vector<pll> q = {{s[0], 1}};
    for(int i = 1; i < n; i++) if(q.back().x == s[i]) q.back().y++;
    else q.pb({s[i], 1});
    if(sz(d) > 1 && d[sz(d) - 2] == d[sz(d) - 1]) d.pop_back();
    sort(all(d));
    vi cnt(sz(d), 0);
    for(int j = 0; j < sz(d); j++) for(int i = 0; i < sz(q); i++) if(q[i].x % d[j] == 0) cnt[j] += q[i].y;
    vll dp(sz(d));
    for(int j = 0; j < sz(d); j++) {
        if(d[j] < hi) continue;
        dp[j] = cnk(cnt[j], S / d[j]);
        if(dp[j]) for(int k = 0; k < j; k++) if(d[j] % d[k] == 0) dp[j] = (dp[j] + dp[k]) % M;
    }
    cout << dp[sz(d) - 1];
}