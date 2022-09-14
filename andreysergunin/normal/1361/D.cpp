#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;
 
void solve();
 
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(16) << fixed;
    cerr << setprecision(16) << fixed;
 
    int tests = 1;
    // cin >> tests;
 
    for (int test = 1; test <= tests; ++test) {
        // cout << "Case #" << test << ": ";
        solve();
    }
 
#ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
}
 
// ----------------------------------------------------------------- 
 
struct Point {
    ll x, y;
};
 
bool operator<(const Point &a, const Point &b) {
    return tie(a.x, a.y) < tie(b.x, b.y);
}
 
bool operator==(const Point &a, const Point &b) {
    return tie(a.x, a.y) == tie(b.x, b.y);
}
 
 
ll dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}
 
ll cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}
 
ll dist2(const Point &a) {
    return dot(a, a);
}
 
ld dist(const Point &a) {
    return hypotl(a.x, a.y);
}
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<Point> p(n);
 
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }
 
    Point origin = {0, 0};
 
    for (int i = 0; i < n; ++i) {
        if (p[i] == origin) {
            swap(p[0], p[i]);
            break;
        }
    }
 
    sort(1 + all(p), [&](const Point &a, const Point &b) {
        if (a < origin && origin < b) {
            return true;
        }
        if (b < origin && origin < a) {
            return false;
        }
        ll c = cross(a, b);
        if (c == 0) {
            return dist2(a) > dist2(b);
        }
        return c > 0;
    });
 
    vector<ld> val;
    val.push_back(0);
 
    vector<vector<ld>> arr;
    arr.push_back({});
 
    int cnt = 0;
    ld sum = 0;
    for (int i = 1; i < n; ++i) {
        if (cross(p[i], p[i - 1]) != 0 || dot(p[i], p[i - 1]) < 0) {
            cnt = 0;
            arr.push_back({});
        }
        arr.back().push_back(dist(p[i]));
        sum += (k - 1 - 2 * cnt) * dist(p[i]);
        if (k - 1 - 2 * cnt >= 0) {
            val.push_back((k - 1 - 2 * cnt) * dist(p[i]));
        }
        ++cnt;
    }
 
    sort(all(val));
    reverse(all(val));
 
    ld res = 0;

    if (sz(val) >= k) {
        for (int i = 0; i < k; ++i) {
            res += val[i];
        }       
    }
 
    for (int i = 0; i < sz(arr); ++i) {
        if (n - sz(arr[i]) > (k + 1) / 2) {
            continue;
        }
 
        ld cur = sum;
        int cnt = 0;
        for (ld d : arr[i]) {
            cur -= (k - 1 - 2 * cnt) * d;
            ++cnt;
        }
 
        cnt = 0;
        for (int j = 0; j < k / 2; ++j) {
            cur += (k - 1 - 2 * cnt) * arr[i][j];
            ++cnt;
        } 
 
        int rem = k - (k / 2 + (n - sz(arr[i])));
 
        for (int j = sz(arr[i]) - rem; j < sz(arr[i]); ++j) {
            cur += (k - 1 - 2 * cnt) * arr[i][j];
            ++cnt;
        } 
 
        res = max(res, cur);
    }
 
 
    cout << res << "\n";
}