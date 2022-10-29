#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("vpt")

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1000'000'000, mod = 1000'000'007, mod2 = 998'244'353;
const ll llinf = 1e18;
const ld pi = 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define x first
#define y second
#define debug(x) cout << #x << ": " << x << el

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return true; } return false; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return true; } return false; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(nullptr));

const int N = 1000'002;
vector<int> a;
vector<ll> pref;
vector<ll> part_sums;
void solve(int l, int r) {
    if (!a[l]) {
        int tl = l, tr = r;
        while(tr - tl > 1) {
            int tm = (tl + tr) >> 1;
            if (pref[tm] > pref[l]) tr = tm;
            else tl = tm;
        }
        l = tr;
    }
    if (!a[r]) {
        int tl = l, tr = r;
        while(tr - tl > 1) {
            int tm = (tl + tr) >> 1;
            if (pref[tm - 1] < pref[r]) tl = tm;
            else tr = tm;
        }
        r = tl;
    }
    part_sums.push_back(pref[r] - pref[l - 1]);
    if (l < r) {
        int m = (l + r) >> 1;
        solve(l, m);
        solve(m + 1, r);
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        a.assign(N, 0);
        pref.assign(N, 0);
        int n, q;
        cin >> n >> q;
        forn(i, n) {
            int c;
            cin >> c;
            a[c]++;
        }
        firn(i, N) {
            pref[i] = pref[i - 1] + a[i] * 1ll * i;
        }
        part_sums.clear();
        solve(0, N - 1);
        sort(all(part_sums));
        forn(i, q) {
            int x;
            cin >> x;
            auto j = lower_bound(all(part_sums), x);
            if (j != part_sums.end() && *j == x) cout << "Yes" << el;
            else cout << "No" << el;
        }
    }
    return 0;
}