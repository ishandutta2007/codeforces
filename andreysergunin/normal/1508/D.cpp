#pragma GCC optimize("Ofast", "unroll-loops", "no-stack-protector")
 
#include <bits/stdc++.h>
 
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using ll = long long;
using ld = long double; 
// using ld = __float128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using uint = unsigned int;
using ull = unsigned long long;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
// default_random_engine generator;

void solve();

int main() {
#ifdef LOCAL
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); 
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(10) << fixed;
    cerr << setprecision(10) << fixed;

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
    int x, y, i, j;
};

Point operator-(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}

ll cross(const Point &a, const Point &b) {
    return ll(a.x) * b.y - ll(a.y) * b.x;
}

bool operator<(const Point &a, const Point &b) {
    return tie(a.x, a.y) < tie(b.x, b.y);
}

Point origin;
bool cmp(const Point &a, const Point &b) {
    return cross(a - origin, b - origin) > 0;
}

void solve() {
    int n;
    cin >> n;

    vector<Point> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y >> p[i].j;
        --p[i].j;
        p[i].i = i;
    }

    for (int i = n - 1; i >= 0; --i) {
        if (p[i].i == p[i].j) {
            p.erase(p.begin() + i);
        }
    }

    int m = sz(p);

    if (m == 0) {
        cout << 0 << endl;
        return;
    }

    sort(all(p));
    origin = p[0];
    sort(1 + all(p), cmp);

    vector<pii> res;
    auto f = [&](int i, int j) {
        res.emplace_back(p[i].i, p[j].i);
        swap(p[i].j, p[j].j);
    };

    while (true) {
        vector<int> to(n, -1);
        for (int i = 0; i < m; ++i) {
            to[p[i].i] = p[i].j;
        }
            
        int t = 0;
        vector<int> cycle(n, -1);
        for (int i = 0; i < n; ++i) {
            if (cycle[i] != -1 || to[i] == -1) {
                continue;
            }

            int v = i;  
            for (; cycle[v] == -1; v = to[v]) {
                cycle[v] = t;
            }
            ++t;
        }

        if (t <= 1) {
            break;
        }

        for (int i = 1; i + 1 < m; ++i) {
            if (cycle[p[i].i] != cycle[p[i + 1].i]) {
                f(i, i + 1);
                break;
            }
        }
    }

    vector<int> pos(n, -1);
    for (int i = 0; i < m; ++i) {
        pos[p[i].i] = i;
    }

    for (int i = 0; i < m - 1; ++i) {
        int j = pos[p[0].j];
        f(0, j);
    }

    cout << sz(res) << endl;
    for (auto [x, y] : res) {
        cout << x + 1 << " " << y + 1 << endl;
    }
}