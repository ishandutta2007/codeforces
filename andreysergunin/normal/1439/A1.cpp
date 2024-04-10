#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
// using ld = __float128;
using pii = pair<int, int>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;

    int tests = 1;
    cin >> tests;

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
    int x, y;
};

void solve() {  
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<array<Point, 3>> res;

    auto flip = [&](int i, int j) {
        s[i][j] = '0' + '1' - s[i][j];
    };

    for (int i = 0; i < n - 2; ++i) {
        if (s[i][0] == '1') {
            flip(i, 0);
            flip(i, 1);
            flip(i + 1, 0);
            array<Point, 3> cur = {Point{i, 0}, Point{i, 1}, Point{i + 1, 0}};
            res.push_back(cur);
        }
        for (int j = 1; j < m; ++j) {
            if (s[i][j] == '1') {
                flip(i, j);
                flip(i + 1, j - 1);
                flip(i + 1, j);
                array<Point, 3> cur = {Point{i, j}, Point{i + 1, j - 1}, Point{i + 1, j}};
                res.push_back(cur);
            }
        }
    }

    for (int j = 0; j < m - 2; ++j) {
        for (int i = n - 2; i < n; ++i) {
            if (s[i][j] == '1') {
                flip(i, j);
                flip(n - 2, j + 1);
                flip(n - 1, j + 1);
                array<Point, 3> cur = {Point{i, j}, Point{n - 2, j + 1}, Point{n - 1, j + 1}};
                res.push_back(cur);
            }
        }
    }


    if (s[n - 2][m - 2] == '1') {
        flip(n - 2, m - 2);
        flip(n - 2, m - 1);
        flip(n - 1, m - 2);
        array<Point, 3> cur = {Point{n - 2, m - 2}, Point{n - 2, m - 1}, Point{n - 1, m - 2}};
        res.push_back(cur);
    }

    vector<Point> bad;

    for (int i = n - 2; i < n; ++i) {
        for (int j = m - 2; j < m; ++j) {
            if (s[i][j] == '1') {
                bad.push_back({i, j});
            }
        }
    }

    if (sz(bad) & 1) {
        flip(n - 1, m - 1);
        flip(n - 2, m - 1);
        flip(n - 1, m - 2);
        array<Point, 3> cur = {Point{n - 1, m - 1}, Point{n - 2, m - 1}, Point{n - 1, m - 2}};
        res.push_back(cur);
    }

    vector<Point> good;
    bad.clear();
    for (int i = n - 2; i < n; ++i) {
        for (int j = m - 2; j < m; ++j) {
            if (s[i][j] == '1') {
                bad.push_back({i, j});
            } else {
                good.push_back({i, j});
            }
        }
    }

    if (sz(bad) == 2) {
        {
            flip(good[0].x, good[0].y);
            flip(good[1].x, good[1].y);
            flip(bad[0].x, bad[0].y);
            array<Point, 3> cur = {Point{good[0].x, good[0].y}, Point{good[1].x, good[1].y}, Point{bad[0].x, bad[0].y}};
            res.push_back(cur);            
        }
        {
            flip(good[0].x, good[0].y);
            flip(good[1].x, good[1].y);
            flip(bad[1].x, bad[1].y);
            array<Point, 3> cur = {Point{good[0].x, good[0].y}, Point{good[1].x, good[1].y}, Point{bad[1].x, bad[1].y}};
            res.push_back(cur);    
        }
    }


    for (int i = 0; i < n; ++i) {
        cerr << s[i] << endl;
    }

    cout << sz(res) << endl;
    for (auto arr : res) {
        for (auto p : arr) {
            cout << p.x + 1 << " " << p.y + 1 << " ";
        }
        cout << endl;
    }
}