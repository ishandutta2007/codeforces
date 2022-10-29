#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")

using namespace std;

#define x first
#define y second
#define all(v) v.begin(), v.end()
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define firn(i, n) for (int i = 1; i < (int)n; ++i)

typedef long long ll;
typedef long double ld;

const char el = '\n';
const int inf = 1e9;
const ll llinf = 1e18, mod = (ll)(1e9) + 7;
const int NN = 500000;
template<typename T> bool uin(T & a, T b) {if (b < a) {a = b; return 1;} return 0;}
template<typename T> bool uax(T & a, T b) {if (b > a) {a = b; return 1;} return 0;}

mt19937 rnd(time(NULL));
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, k, n, s;
    cin >> m >> k >> n >> s;
    vector<int> a(m), b(s), need1(NN);
    forn(i, m) {
        cin >> a[i];
        a[i]--;
    }
    forn(i, s) {
        cin >> b[i];
        b[i]--;
        need1[b[i]]++;
    }
    vector<int> t[NN];
    forn(i, m) t[a[i]].push_back(i);
    vector<pair<int, int> >need;
    vector<int> biba;
    vector<int> num(NN, -1);
    forn(i, NN) {
        if (need1[i] > 0) {
                forn(j, t[i].size())
                num[i] = (int)need.size();
                need.push_back({i, need1[i]});
        }
    }
    int mn = inf;
    int q = (int)need.size();
    vector<int> r(need.size(), 0);
    int tt = -1;
    forn(i, q)
            if (r[i] + need[i].y > (int)t[need[i].x].size())
                tt = inf;
            else uax(tt, t[need[i].x][r[i] + need[i].y - 1]);
    forn(i, m) {
        if (tt == inf) break;
        if (i > 0 && need1[a[i - 1]]) {
            r[num[a[i - 1]]]++;
            int j = num[a[i - 1]];
            if (r[j] + need[j].y > (int)t[need[j].x].size())
                tt = inf;
            else uax(tt, t[need[j].x][r[j] + need[j].y - 1]);
        }
        int cnt = i / k + (m - max(tt + 1, i + k)) / k + 1;
        if (cnt < n) continue;
        int d = max(0, tt - i + 1 - k);
        cout << d << el;
        for (int j = i; j <= tt && d; ++j) {
            if (need1[a[j]] == 0) {
                cout << j + 1 << ' ';
                d--;
                continue;
            }
            need1[a[j]]--;
        }
        return 0;
    }
    cout << -1;
    return 0;
}