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
const int inf = 1e9;
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

const int N = 10000'001;
vector<int> d[N];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    forn(i, n) {
        char c;
        cin >> c;
        if (c == 'R') a[i] = 1;
        else a[i] = 0;
    }
    int cur = 0, sum = 0;
    forn(q, inf) {
        assert(q < N);
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == 1 && a[i + 1] == 0) {
                swap(a[i], a[i + 1]);
                d[q].push_back(i);
                i++;
            }
        }
        if (d[q].empty()) break;
        cur++;
        sum += (int)d[q].size();
    }
    if (k < cur || k > sum) {
        cout << -1 << el;
    }
    else {
        for (int i = 0; k > 0; i++) {
            int t = min((int) d[i].size(), k - (cur - i) + 1);
            forn(j, t - 1) {
                cout << 1 << ' ' << d[i][j] + 1 << el;
            }
            cout << (int) d[i].size() - (t - 1) << ' ';
            for (int j = t - 1; j < (int) d[i].size(); j++) cout << d[i][j] + 1 << ' ';
            cout << el;
            k -= t;
        }
    }
    return 0;
}