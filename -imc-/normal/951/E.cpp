#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

void solve(bool read);

//#define int li

ostream& dbgPrintContainer(ostream& os, const auto& container, const char* brackets = "[]") {
    os << brackets[0] << " ";
    for (auto& elem : container) {
        os << elem << " ";
    }
    os << brackets[1];
    return os;
}

ostream& operator<<(ostream& os, const pair<auto, auto>& p) {
    return os << "(" << p.first << " " << p.second << ")";
}

ostream& operator<<(ostream& os, const vector<auto>& v) { return dbgPrintContainer(os, v, "[]"); }
ostream& operator<<(ostream& os, const set<auto>& v) { return dbgPrintContainer(os, v, "{}"); }
ostream& operator<<(ostream& os, const map<auto, auto>& v) { return dbgPrintContainer(os, v, "{}"); }

signed main() {
    auto t0 = clock();
    cout << fixed << setprecision(12);

#ifdef YA
    assert(freopen("input.txt", "r", stdin));
#else
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#endif

    solve(true);

#if 0
    while (true) {
        solve(false);
    }
#endif

#ifdef YA
    cerr << endl << endl << fixed << setprecision(5) << (clock() - t0) / (double)CLOCKS_PER_SEC << endl;
#endif

    return 0;
}

struct point {
    int x = 0, y = 0;

    point(int x = 0, int y = 0): x(x), y(y) {}

    point operator+(const point& p) const { return point(x + p.x, y + p.y); }
    point operator-(const point& p) const { return point(x - p.x, y - p.y); }

    li sprod(const point& p) const { return x * (li)p.x + y * (li)p.y; }
    li vprod(const point& p) const { return x * (li)p.y - y * (li)p.x; }

    bool half() const {
        if (y) {
            return y < 0;
        } else {
            return x < 0;
        }
    }
};

bool cmpp(point a, point b) {
    if (a.half() != b.half()) {
        return a.half() < b.half();
    } else {
        return a.vprod(b) > 0;
    }
}

unsigned long long ans = 0;

void process(vector<point> p, int index) {
    swap(p[0], p[index]);
    int n = p.size();
    int cnt = 0;
    for (int i = 1; i < n; ++i) {
        if ((p[i] - p[0]).half()) {
            ++cnt;
        }
    }

    vector<pair<point, bool>> q;
    for (int i = 1; i < n; ++i) {
        q.push_back({p[i] - p[0], false});
        if (q.back().first.half()) {
            q.back() = {p[0] - p[i], 1};
        }
    }

    sort(all(q), [&](const auto& a, const auto& b) {
        return cmpp(a.first, b.first);
    });

    for (auto pp : q) {
        if (pp.second) {
            --cnt;
            ans += 1ull * cnt * (cnt - 1) / 2 * (n - 2 - cnt) * (n - 2 - cnt - 1) / 2;
        } else {
            ans += 1ull * cnt * (cnt - 1) / 2 * (n - 2 - cnt) * (n - 2 - cnt - 1) / 2;
            ++cnt;
        }
    }
}

void solve(bool __attribute__((unused)) read) {
    int n;
    cin >> n;

    vector<point> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    for (int i = 0; i < n; ++i) {
        process(p, i);
    }
    assert(ans % 2 == 0);
    cout << ans / 2 << "\n";
}