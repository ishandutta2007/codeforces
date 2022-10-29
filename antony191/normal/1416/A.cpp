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
const int inf = 1000'000'000, mod = 1000'000'007;
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

const int N = 300'001;
vector<int> g[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        forn(i, n) g[i].clear();
        vector<int> a(n);
        forn(i, n) {
            cin >> a[i];
            a[i]--;
            g[a[i]].push_back(i);
        }
        vector<int> ans(n, n);
        forn(i, n) {
            if (g[i].empty()) continue;
            int cur = 1;
            firn(j, g[i].size()) uax(cur, g[i][j] - g[i][j - 1]);
            uax(cur, g[i][0] + 1);
            uax(cur, n - g[i].back());
            uin(ans[cur - 1], i);
        }
        firn(i, n) uin(ans[i], ans[i - 1]);
        forn(i, n) cout << (ans[i] == n ? -1 : ans[i] + 1) << ' ';
        cout << el;
    }
    return 0;
}