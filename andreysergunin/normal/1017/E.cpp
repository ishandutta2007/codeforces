#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <fstream>
#include <random>
#include <cstring>
#include <bitset>
#include <functional>
#include <tuple>
#include <complex>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

mt19937 rnd(random_device{}());


struct Point {
    Point() {};
    Point(ll x, ll y): x(x), y(y) {}
    ll x;
    ll y;

    Point operator += (const Point &other) {
        x = x + other.x;
        y = y + other.y;
        return *this;
    }

    Point operator + (const Point &other) const {
        Point temp = *this;
        return temp += other;
    }

    Point operator -= (const Point &other) {
        x = x - other.x;
        y = y - other.y;
        return *this;
    }
    
    Point operator - (const Point &other) const {
        Point temp = *this;
        return temp -= other;
    }
    
    Point operator * (ll c) const{
        return Point{x * c, y * c};
    }
        
    bool operator == (const Point &other) const {
        return x == other.x && y == other.y;
    }

    bool operator < (const Point &other) const {
        if (x == other.x)
            return y < other.y;
        return x < other.x;
    }

    bool operator > (const Point &other) const {
        if (x == other.x)
            return y > other.y;
        return x > other.x;
    }
};

istream &operator >> (std::istream &stream, Point &a) {
    stream >> a.x >> a.y;
    return stream;
}

ostream &operator << (std::ostream &stream, const Point &a) {
    stream << a.x << " " << a.y;
    return stream;
}

ll cross(const Point &a, const Point &b) {
    return a.x * b.y - a.y * b.x;
}

ll dot(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y;
}

ll dist2(const Point &a) {
    return dot(a, a);
}

ll dist2(const Point &a, const Point &b) {
    return dist2(a - b);
}


bool pointComp(const Point &a, const Point &b) {
    double c = cross(a, b);
    if (c == 0) {
        return dist2(a) < dist2(b);
    }
    return c > 0;
}

vector<Point> convexHull(vector<Point> p) {
    int n = sz(p);
    int s = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i] < p[s]) {
            s = i;
        }
    }
    
    swap(p[s], p[0]);
    Point leftest = p[0];
    for (int i = 0; i < n; ++i) {
        p[i] -= leftest;
    }
    sort(p.begin() + 1, p.end(), pointComp);
    for (int i = 0; i < n; ++i) {
        p[i] += leftest;
    }

    vector<Point> hull;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        while (k > 1 && cross(hull[k - 1] - hull[k - 2], p[i] - hull[k - 1]) <= 0) {
            --k;
            hull.pop_back();
        }
        ++k;
        hull.push_back(p[i]);
    }
    return hull;
}

vector<int> prefixFunction(vector<ll> &str) {
    int size = sz(str);
    vector<int> prefix_function(size);
    int cur = 0;
    for (int i = 1; i < size; ++i) {
        for (; cur > 0 && str[cur] != str[i]; cur = prefix_function[cur - 1]) {}
        if (str[cur] == str[i]) {
            ++cur;
        }
        prefix_function[i] = cur;
    }
    return prefix_function;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<Point> q(m);
    for (int i = 0; i < m; ++i) {
        cin >> q[i];
    }

    p = convexHull(p);
    q = convexHull(q);

    if (sz(p) != sz(q)) {
        cout << "NO" << endl;
        return 0;
    }

    if (sz(p) == 2) {
        cout << (dist2(p[0], p[1]) == dist2(q[0], q[1]) ? "YES" : "NO") << endl;
        return 0;
    }

    int k = sz(p);

    vector<ll> s(2 * k), t(2 * k);

    for (int i = 0; i < k; ++i) {
        s[2 * i] = dist2(p[i], p[(i + 1) % k]);
        s[2 * i + 1] = dist2(p[i], p[(i + 2) % k]);
        t[2 * i] = dist2(q[i], q[(i + 1) % k]);
        t[2 * i + 1] = dist2(q[i], q[(i + 2) % k]);
    }

    vector<ll> u;
    for (ll el : s) {
        u.push_back(el);
    }
    u.push_back(-1);
    for (ll el : t) {
        u.push_back(el);
    }
    vector<int> prefu = prefixFunction(u);

    vector<ll> v;
    for (ll el : t) {
        v.push_back(el);
    }
    v.push_back(-1);
    for (ll el : s) {
        v.push_back(el);
    }
    vector<int> prefv = prefixFunction(v);


    // for (int el : u) {
    //     cout << el << " ";
    // }
    // cout << endl;
    
    // for (int el : v) {
    //     cout << el << " ";
    // }
    // cout << endl;

    vector<int> f;
    int cur = sz(prefu) - 1;
    while (cur > 0) {
        f.push_back(prefu[cur]);
        cur = prefu[cur] - 1;
    }
    reverse(all(f));

    vector<int> g;
    cur = sz(prefv) - 1;
    while (cur > 0) {
        g.push_back(prefv[cur]);
        cur = prefv[cur] - 1;
    }
    reverse(all(g));

    // for (int i = 0; i < sz(f); ++i) {
    //     cout << f[i] << " ";
    // }
    // cout << endl;

    // for (int i = 0; i < sz(g); ++i) {
    //     cout << g[i] << " ";
    // }
    // cout << endl;

    int it = 0;

    for (int i = sz(f) - 1; i >= 0; --i) {
        while (it < sz(g) && f[i] + g[it] < 2 * k) {
            ++it;
        }

        if (it < sz(g) && f[i] + g[it] == 2 * k && f[i] % 2 == 0 && g[i] % 2 == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}