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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);  
#endif 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setprecision(14) << fixed;
    cerr << setprecision(14) << fixed;

    int tests = 1;
    // cin >> tests;

    while (tests--) {
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

Point operator-(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}

Point operator+(const Point &a, const Point &b) {
    return {a.x + b.x, a.y + b.y};
}

bool operator==(const Point &a, const Point &b) {
    return tie(a.x, a.y) == tie(b.x, b.y);
}


void solve() {
    int n;
    cin >> n;
    vector<Point> p(n);

    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    if (n & 1) {
        cout << "No" << endl;
        return; 
    }

    Point origin = {0, 0};

    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        int k = (i + n / 2) % n;
        int l = (i + n / 2 + 1) % n;

        Point q = (p[i] - p[j]) + (p[k] - p[l]);

        if (!(q == origin)) {
            cout << "No" << endl;
            return;
        }
    }

    cout << "Yes" << endl;
}