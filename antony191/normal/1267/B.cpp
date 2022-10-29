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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    vector<pair<int, int>> a;
    forn(i, s.size()) {
        if (!i || s[i] != s[i - 1]) a.emplace_back(s[i], 1);
        else a.back().y++;
    }
    bool ok = false;
    int n = (int)a.size();
    if (n & 1) {
        bool tmp = 1;
        if (a[n / 2].y < 2) tmp = 0;
        for (int i = (n / 2) - 1; i >= 0; --i) {
            if (a[i].x != a[n - 1 - i].x || a[i].y + a[n - 1 - i].y < 3) tmp = 0;
        }
        if (tmp) ok = 1;
    }
    cout << (ok ? a[n / 2].y + 1 : 0) << el;
    return 0;
}