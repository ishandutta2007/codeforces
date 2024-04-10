#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define pbc push_back
#define pob pop_back()
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define vin(a) for (auto& i : a) cin >> i

// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

template<typename T1, typename T2> 
inline void chkmin(T1& x, const T2& y) {
    if (y < x) x = y;
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
    if (x < y) x = y;
}

#define x first
#define y second

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(20), cout.setf(ios::fixed);
    vector<pair<int, int>> v(3);
    for (auto& [x, y] : v) {
        cin >> x >> y;
    }
    sort(all(v));
    vector<pair<pair<int, int>, pair<int, int>>> segments;
    if (v[0].x != v[1].x) {
        segments.push_back({v[0], {v[1].x, v[0].y}});
        v[0].x = v[1].x;
    }
    if (v[1].x != v[2].x) {
        segments.push_back({v[2], {v[1].x, v[2].y}});
        v[2].x = v[1].x;
    }
    sort(all(v));
    if (v[0].y != v[1].y) {
        segments.push_back({v[0], {v[0].x, v[1].y}});
    }
    if (v[1].y != v[2].y) {
        segments.push_back({v[2], {v[0].x, v[1].y}});
    }
    cout << segments.size() << endl;
    for (auto [a, b] : segments) {
        cout << a.first << " " << a.second << " " << b.first << " " << b.second << endl;
    }
    return 0;
}