#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
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
const ld pi = 3.1415926;

#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
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

vector<vector<int>> solve(int k, int c, int d) {
    vector<vector<int>> ans(k);
    forn(i, k) {
        ans[i].push_back(2);
        ans[i].push_back(3);
        ans[i].push_back(2);
    }
    forn(i, d - k) {
        ans.back().push_back(3);
        ans.back().push_back(2);
    }
    return ans;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > 0) {
        if (b < a - 1) return cout << "NO", 0;
        int e = b - (a - 1);
        int f = c - d;
        if (f < 0 || f > e || f + 2 < e) return cout << "NO", 0;
        if (e == 0 && c > 0) return cout << "NO", 0;
        cout << "YES" << el;
        if (e > f + 1) cout << "1 ";
        forn(i, a - 1) cout << "0 1 ";
        cout << "0 ";
        forn(i, f) {
            cout << "1 2 ";
        }
        if (e > f) cout << "1 ";
        forn(i, d) {
            if (e > f) cout << "2 3 ";
            else cout << "3 2 ";
        }
        return 0;
    }
    if (b > 0) {
        int e = c - d;
        if (e < 0 || e < b - 1 || e > b + 1) return cout << "NO", 0;
        cout << "YES" << el;
        if (e >= b) cout << "2 ";
        forn(i, b - 1) cout << "1 2 ";
        cout << "1 ";
        forn(i, d) cout << "2 3 ";
        if (e >= b + 1) cout << "2 ";
    }
    else {
        if (abs(c - d) > 1) return cout << "NO", 0;
        cout << "YES" << el;
        int s = 2;
        if (d > c) s = 3;
        forn(i, c + d) {
            cout << s << ' ';
            s = 5 - s;
        }
    }
    return 0;
}