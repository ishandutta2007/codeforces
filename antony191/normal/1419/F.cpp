#include <iostream>
#include <vector>
#include <algorithm>
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


const int N = 1001;
vector<int> px, py;
vector<pair<int, int>> x[N], y[N];
vector<int> p, h;
int cnt;
void init(int n) {
    h.assign(n, 0);
    p.resize(n);
    cnt = n;
    forn(i, n) p[i] = i;
}
int getp(int a) {
    return a == p[a] ? a : p[a] = getp(p[a]);
}
void unite(int a, int b) {
    a = getp(a); b = getp(b);
    if (a == b) return;
    cnt--;
    if (h[a] < h[b]) swap(a, b);
    p[b] = a;
    if (h[a] == h[b]) h[a]++;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    forn(i, n) {
        cin >> a[i].x >> a[i].y;
        px.push_back(a[i].x);
        py.push_back(a[i].y);
    }
    sort(all(px)); px.resize(distance(px.begin(), unique(all(px))));
    sort(all(py)); py.resize(distance(py.begin(), unique(all(py))));
    forn(i, n) {
        x[lower_bound(all(px), a[i].x) - px.begin()].emplace_back(a[i].y, i);
        y[lower_bound(all(py), a[i].y) - py.begin()].emplace_back(a[i].x, i);
    }
    forn(i, px.size()) sort(all(x[i]));
    forn(i, py.size()) sort(all(y[i]));
    ll l = 0, r = 2100'000'000;
    vector<int> uk(py.size());
    while (r - l > 1) {
        ll m = (l + r) >> 1;
        init(n);
        bool ok = false;
        forn(i, px.size())
            for (int j = 1; j < (int)x[i].size(); j++)
                if (x[i][j].x - x[i][j - 1].x <= m) unite(x[i][j].y, x[i][j - 1].y);
        forn(i, py.size())
            for (int j = 1; j < (int)y[i].size(); j++)
                if (y[i][j].x - y[i][j - 1].x <= m) unite(y[i][j].y, y[i][j - 1].y);
        if (cnt == 1) ok = true;
        else {
            if (cnt == 2) {
                forn(i, px.size()) for (int j = 1; j < (int)x[i].size(); j++)
                        if (x[i][j].x - x[i][j - 1].x <= m + m && getp(x[i][j].y) != getp(x[i][j - 1].y))
                            ok = true;
                forn(i, py.size()) for (int j = 1; j < (int)y[i].size(); j++)
                        if (y[i][j].x - y[i][j - 1].x <= m + m && getp(y[i][j].y) != getp(y[i][j - 1].y))
                            ok = true;
            }
            set<int> q;
            if (!ok) {
                uk.assign(py.size(), 0);
                forn(i, px.size()) {
                    int v = 0;
                    forn(j, py.size()) {
                        while (uk[j] < (int)y[j].size() && y[j][uk[j]].x < px[i]) uk[j]++;
                        while(v < (int)x[i].size() && x[i][v].x < py[j]) v++;
                        if (y[j][uk[j]].x == px[i]) continue;
                        q.clear();
                        if (uk[j] > 0 && px[i] - y[j][uk[j] - 1].x <= m) q.insert(getp(y[j][uk[j] - 1].y));
                        if (uk[j] < (int)y[j].size() && y[j][uk[j]].x - px[i] <= m) q.insert(getp(y[j][uk[j]].y));
                        if (v > 0 && py[j] - x[i][v - 1].x <= m) q.insert(getp(x[i][v - 1].y));
                        if (v < (int)x[i].size() && x[i][v].x - py[j] <= m) q.insert(getp(x[i][v].y));
                        if ((int)q.size() == cnt) {
                            ok = true;
                            break;
                        }
                    }
                    if (ok) break;
                }
            }
        }
        if (ok)
            r = m;
        else l = m;
    }
    cout << (r == 2100'000'000 ? -1 : r) << el;
    return 0;
}