#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")
#endif

using namespace std;

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1000'000'000;
const ll llinf = 1e18, mod = 1000'000'007;
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

const int N = 80;
int d[N][N];
int n, k;
vector<pair<pair<int, int>, int>> a;
void solve(int q) {
    forn(i, N) forn(j, N) d[i][j] = -inf;
    forn(i, N) d[i][0] = 0;
    forn(i, n) {
        firn(j, k + 1) {
            d[i + 1][j] = d[i][j];
            if (i != q)
                uax(d[i + 1][j], d[i][j - 1] + a[i].x.y - a[i].x.x * (k + 1 - j));
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        k--;
        a.resize(n);
        forn(i, n) {
            cin >> a[i].x.y >> a[i].x.x;
            a[i].y = i + 1;
        }
        sort(all(a));
        int ans = -inf, p = -1;
        forn(q, n) {
            solve(q);
            int tmp = a[q].x.y + d[n][k];
            if (uax(ans, tmp)) {
                p = q;
            }
        }
        solve(p);
        vector<bool> used(n, false);
        for (int i = n - 1, j = k; i >= 0 && j > 0; i--) {
            if (i == p) continue;
            if (d[i + 1][j] == d[i][j - 1] + a[i].x.y - a[i].x.x * (k + 1 - j)) {
                used[i] = true;
                j--;
            }
        }
        cout << n + n - k - 1 << el;
        forn(i, n) {
            if (used[i]) cout << a[i].y << ' ';
        }
        forn(i, n) {
            if (i == p || used[i]) continue;
            cout << a[i].y << ' ';
            cout << -a[i].y << ' ';
        }
        cout << a[p].y << el;
    }
    return 0;
}