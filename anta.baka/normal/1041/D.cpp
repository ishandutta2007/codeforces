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

const int maxn = 2e5;
const int mod = 998244353;
const int M = 1e9 + 7;
const int inf = 1e9;
const ll inf64 = 1e18L;
const ld pi = acos((ld)-1.0);
const ld eps = (ld)1e-6;

struct fen {
    int n; vi t;
    fen(int n) : n(n), t(n, 0) {}
    void upd(int v, int x) {
        for(int i = v; i < n; i |= i + 1) t[i] += x;
    }
    int get(int v) {
        int ret = 0;
        for(int i = v; i >= 0; i = (i & (i + 1)) - 1) ret += t[i];
        return ret;
    }
};

int n, h;
int x1[maxn], x2[maxn];

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
    cin >> n >> h;
    for(int i = 0; i < n; i++) cin >> x1[i] >> x2[i];
    fen t1(2 * n), t2(2 * n);
    for(int i = 0; i < n; i++) {
        t1.upd(2 * i, x2[i] - x1[i]);
        t2.upd(2 * i + 1, (i != n - 1 ? x1[i + 1] - x2[i] : inf));
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int lf = i, rg = n - 1;
        int cmp = h + t2.get(2 * i);
        while(lf < rg) {
            int md = (lf + rg) >> 1;
            if(t2.get(2 * md + 1) < cmp) lf = md + 1;
            else rg = md;
        }
        ans = max(ans, t1.get(2 * lf + 1) - t1.get(2 * i - 1));
    }
    cout << ans + h;
}