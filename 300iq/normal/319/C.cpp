#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = (ll) 1e18 + 7;

struct Point {
    double x;
    Point(double x): x(x) {}
    Point() {}
};

struct Line {
    ll k, b;
    Line(ll k, ll b): k(k), b(b) {}
};

bool not_inter(const Line &p, const Line &q) {
    double num = (q.b - p.b), denum = (p.k - q.k);
    return (denum == 0);
}

Point inter(const Line &p, const Line &q) {
    assert(!not_inter(p, q));
    double num = (q.b - p.b), denum = (p.k - q.k);
    return Point(num / denum);
}

bool good(const Point &a, const Point &b) {
    return a.x <= b.x;
}

double f(const Line &a, const Point& p) {
    return a.k * p.x + a.b;
}

struct convex {
    vector <Line> p;
    convex() {}
    void push(const Line &a) {
        while ((int) p.size() > 1) {
            Line b = p[(int) p.size() - 1];
            Line c = p[(int) p.size() - 2];
            if (not_inter(a, b) || good(inter(a, b), inter(b, c))) {
                p.pop_back();
            } else {
                break;
            }
        }
        if (!p.empty() && not_inter(a, p.back())) {
            p.pop_back();
        }
        p.push_back(a);
    }
    double get(const Point &a) {
        assert(!p.empty());
        int l = -1, r = (int) p.size() - 1;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (m == -1 || f(p[m], a) >= f(p[m + 1], a)) {
                l = m;
            } else {
                r = m;
            }
        }
        return f(p[l + 1], a);
    }
};

struct convex_offline {
    deque <Line> p;
    convex_offline() {}
    void push(const Line &a) {
        while ((int) p.size() > 1) {
            Line b = p[(int) p.size() - 1];
            Line c = p[(int) p.size() - 2];
            if (not_inter(a, b) || good(inter(a, b), inter(b, c))) {
                p.pop_back();
            } else {
                break;
            }
        }
        if (!p.empty() && not_inter(a, p.back())) {
            p.pop_back();
        }
        p.push_back(a);
    }
    double get(const Point &a) {
        assert(!p.empty());
        if (p.size() == 1) return f(p[0], a);
        while (p.size() > 1 && f(p[0], a) >= f(p[1], a)) p.pop_front();
        return f(p[0], a);
    }
};

int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    convex_offline h;
    vector <ll> dp(n, INF);
    dp[0] = 0;
    h.push(Line(b[0], dp[0]));
    for (int i = 1; i < n; i++) {
        dp[i] = h.get(Point(a[i]));
        h.push(Line(b[i], dp[i]));
    }
    cout << dp[n - 1] << endl;
}