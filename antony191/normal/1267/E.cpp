#include <bits/stdc++.h>

#ifdef ONLINE_JUDJE
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("vpt")
#endif
using namespace std;

typedef long long ll;
typedef long double ld;
const char el = '\n';
const int inf = 1e9, mod = 1000'000'007;
const ll llinf = 1e18;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define x first
#define y second
#define pb push_back
#define debug(x) cout << #x << ": " << x << el
#define left left228
#define right right228
#define prev prev228

template<typename T> bool uin(T &a, T b) { if (b < a) { a = b; return true;} return false; }
template<typename T> bool uax(T &a, T b) { if (b > a) { a = b; return true;} return false; }
template<class iterator> void output(iterator begin, iterator end, char p = ' ', ostream & out = cout) { while (begin != end) { out << (*begin) << p; begin++; } out << el; }
template<class T> void output(T x, char p = ' ', ostream & out = cout) { output(all(x), p, out); }

mt19937 rnd(time(nullptr));

const int N = 100;
int a[N][N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int ans = m;
    vector<int> answ(m);
    forn(i, m) answ[i] = i;
    forn(i, m) {
        forn(j, n)
            cin >> a[i][j];
    }
    forn(k, n - 1) {
        vector<pair<int, int>> q;
        forn(i, m) q.emplace_back(a[i][k] - a[i][n - 1], i);
        sort(q.rbegin(), q.rend());
        int sum = 0, t = 0;
        forn(i, m) {
            if (sum + q[i].x < 0) {
                t = m - i;
                break;
            }
            sum += q[i].x;
        }
        if (uin(ans, t)) {
            answ.clear();
            for (int i = m - t; i < m; ++i)
                answ.push_back(q[i].y);
        }
    }
    cout << ans << el;
    forn(i, ans) cout << answ[i] + 1 << ' ';
    cout << el;
    return 0;
}