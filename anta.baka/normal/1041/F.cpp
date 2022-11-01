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

const int maxn = 1000;
const int mod = 998244353;
const int M = 1e9 + 7;
const int inf = 1e9;
const ll inf64 = 1e18L;
const ld pi = acos((ld)-1.0);
const ld eps = (ld)1e-6;

int solve(vi a, vi b) {
    if(sz(a) == 1 && sz(b) == 1 && a[0] == 0 && b[0] == 0) return 2;
    if((a.empty() || sz(a) == 1 && a[0] == 0) && (b.empty() || sz(b) == 1 && b[0] == 0)) return max(sz(a), sz(b));
    int cur1 = 0, cur2 = 0;
    vi a1, a2, b1, b2;
    for(int x : a)
        if(x & 1) {
            cur1++;
            a1.pb(x / 2);
        } else {
            cur2++;
            a2.pb(x / 2);
        }
    for(int x : b)
        if(!(x & 1)) {
            cur1++;
            b1.pb(x / 2);
        } else {
            cur2++;
            b2.pb(x / 2);
        }
    a1.erase(unique(all(a1)), a1.end());
    a2.erase(unique(all(a2)), a2.end());
    b1.erase(unique(all(b1)), b1.end());
    b2.erase(unique(all(b2)), b2.end());
    return max({cur1, cur2, solve(a1, b2), solve(a2, b1)});
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
    int n, m, tmp;
    cin >> n >> tmp;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m >> tmp;
    vi b(m);
    for(int i = 0; i < m; i++) cin >> b[i];
    cout << solve(a, b);
}