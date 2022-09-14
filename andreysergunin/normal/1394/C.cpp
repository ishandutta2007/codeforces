#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
 
using ll = long long;
using ld = double; 
// using ld = __float128;
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

const int INF = 1e9;

struct Point {
    int x, y;
};

void solve() {
    int n;
    cin >> n;
    vector<Point> p(n);

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int a = 0, b = 0;
        for (char c : s) {
            a += c == 'B';
            b += c == 'N';
        }
        p[i] = {a, b};
        // cerr << a << " " << b << endl;
    }

    int minx = INF, maxx = -INF;
    int miny = INF, maxy = -INF;
    int l = INF, r = -INF;

    for (auto [x, y] : p) {
        minx = min(minx, x);
        maxx = max(maxx, x);

        miny = min(miny, y);
        maxy = max(maxy, y);

        l = min(l, x - y);
        r = max(r, x - y);
    }

    int res = 0;
    res = max(res, (maxx - minx + 1) / 2);
    res = max(res, (maxy - miny + 1) / 2);
    res = max(res, (minx - miny) - l);
    res = max(res, r - (minx - miny));

    Point best = {minx + res, miny + res};


    for (int op = 0; op < 2; ++op) {
        int xx = miny + l;
        int yy = miny;
        int cur = 0;
        // cerr << xx << " " << yy << endl;
        cur = max(cur, (maxx - xx + 2) / 3);
        cur = max(cur, (maxy - yy + 1) / 2);
        cur = max(cur, (r - l + 1) / 2);

        if (cur < res && cur <= minx - xx) {
            res = cur;
            best = {xx + 2 * res, yy + res};
            if (op) {
                swap(best.x, best.y);
            }
        }

        for (int i = 0; i < n; ++i) {
            swap(p[i].x, p[i].y);
        }
        swap(minx, miny);
        swap(maxx, maxy);
        r *= -1;
        l *= -1;
        swap(l, r);
    } 


    cout << res << endl;
    // cout << best.x << " " << best.y << endl;
    string ans;
    for (int i = 0; i < best.x; ++i) {
        ans += 'B';
    }
    for (int i = 0; i < best.y; ++i) {
        ans += 'N';
    }
    cout << ans << endl;

}