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
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout); 
#endif 

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(12) << fixed;
    cerr << setprecision(12) << fixed;

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
    Point() {}
    Point(ll x, ll y) : x(x), y(y) {}

    ll x, y;

    Point operator+=(const Point &other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Point operator-=(const Point &other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
};

Point operator+(const Point &a, const Point &b) {
    return {a.x + b.x, a.y + b.y};
}

Point operator-(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}

istream &operator>>(istream &stream, Point &a) {
    stream >> a.x >> a.y;
    return stream;
}

ostream &operator<<(ostream &stream, const Point &a) {
    stream << a.x << " " << a.y;
    return stream;
}

ll dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
} 

ll cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

const int MAXN = 6006;

void solve() {  
    int n = 6000;
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        // p[i] = Point(rnd() % int(1e7), rnd() %  int(1e7));
    }

    vector<bitset<MAXN>> x(n);

    auto check = [&](vector<pii> p) {
        bool ok = true;
        for (int i = 0; i < 3; ++i) {
            for (int j = i + 1; j < 3; ++j) {
                auto [x, y] = p[i];
                auto [u, v] = p[j];
                ok ^= (x ^ u) | (y ^ v);
            }
        }
        return ok;
    };

    map<pii, ll> cnt;

    for (int i = 0; i < n; ++i) {
        int u = (((p[i].x % 4) + 4) % 4) / 2;
        int v = (((p[i].y % 4) + 4) % 4) / 2;
        ++cnt[{u, v}];
    }

    vector<pii> q;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            q.push_back({i, j});
        }
    }

    ll res = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            for (int k = j + 1; k < 4; ++k) {
                if (check({q[i], q[j], q[k]})) {
                    res += cnt[q[i]] * cnt[q[j]] * cnt[q[k]];
                }
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        if (check({q[i], q[i], q[i]})) {
            res += cnt[q[i]] * (cnt[q[i]] - 1) * (cnt[q[i]] - 2) / 6;
        }
        for (int j = 0; j < 4; ++j) {
            if (i != j) {
                res += cnt[q[i]] * (cnt[q[i]] - 1) * cnt[q[j]] / 2;
            }
        }
    }

    cout << res << endl;

}