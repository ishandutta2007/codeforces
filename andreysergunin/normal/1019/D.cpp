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
typedef unsigned int uint;

mt19937 rnd(random_device{}());

struct Point {
    Point() : x(0), y(0) {};
    Point(ll x, ll y) : x(x), y(y) {};

    ll x, y;
};

istream &operator >> (std::istream &stream, Point &a) {
    stream >> a.x >> a.y;
    return stream;
}

ostream &operator << (std::ostream &stream, const Point &a) {
    stream << a.x << " " << a.y;
    return stream;
}

Point operator+(const Point &a, const Point &b) {
    return {a.x + b.x, a.y + b.y};
}

Point operator-(const Point &a, const Point &b) {
    return {a.x - b.x, a.y - b.y};
}

bool operator==(const Point &a, const Point &b) {
    return a.x == b.x && a.y == b.y;
}

bool operator!=(const Point &a, const Point &b) {
    return !(a == b);
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

bool neg(const Point &a) {
    return (a.y < 0 || (a.y == 0 && a.x > 0));
}

bool operator < (const Point &a, const Point &b) {
    if (neg(a) && !neg(b))
        return true;
    if (!neg(a) && neg(b))
        return false;
    return cross(a, b) < 0;
}

struct Event {
    Event() {};
    Event(const Point &angle, const vector<int> &v) : angle(angle), v(v) {};
    Point angle;
    vector<int> v;
};

bool comp(const Point &a, const Point &b) {
    if (cross(a, b) == 0) {
        if (neg(a) && !neg(b))
            return true;
        if (!neg(a) && neg(b))
            return false;
    }

    Point u = a, v = b;
    if (neg(a)) {
        u = {-a.x, -a.y};
    }
    if (neg(b)) {
        v = {-b.x, -b.y};
    }
    return cross(u, v) < 0;
}

typedef pair<Point, int> ppi;

ll square(const Point &a, const Point &b, const Point &c) {
    return abs(cross(a - b, a - c));
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    ll s;
    cin >> s;
    s *= 2;

    vector<Point> a(n); 
    for (int i = 0; i < n; ++i) {
        // a[i] = {rnd() % 1000000000, rnd() % 1000000000};
        cin >> a[i];
    }

    sort(all(a), [](const Point &p, const Point &q){return p.y < q.y || (p.y == q.y && (p.x > q.x)); });

    vector<Event> q;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            q.push_back(Event(a[j] - a[i], {i, j}));
        }
    }

    sort(all(q), [](const Event &a, const Event &b){return a.angle < b.angle; });

    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        pos[i] = i;
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = i;
    }

    // cout << sz(q) << endl;

    // for (auto e : q) {
    //     for (auto el : e.v) {
    //         cout << el << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < sz(q); ++i) {
        // for (int j = 0; j < n; ++j)
        //     cout << pos[j] << " ";

        // cout << endl;

        int l = n;
        int r = -1;

        for (int j = 0; j < sz(q[i].v); ++j) {
            l = min(l, pos[q[i].v[j]]);
            r = max(r, pos[q[i].v[j]]);
        }

        // cout << l << " " << r << endl;
        for (int j = l; j <= (l + r) / 2; ++j) {
            swap(a[j], a[r + l - j]);
            swap(b[j], b[r + l - j]);
        }

        // cout << "------------> " << l << " " << r << endl;  

        for (int j = l; j <= r; ++j) {
            for (int k = j + 1; k <= r; ++k) {
                int lf = r;
                int rg = n;
                while (rg - lf > 1) {
                    int mid = (lf + rg) / 2;
                    if (square(a[j], a[k], a[mid]) <= s) {
                        lf = mid;
                    } else {
                        rg = mid;
                    }
                }

                // cout << "!" << endl;
                // cout << a[j] << endl;
                // cout << a[k] << endl;
                // cout << a[lf] << endl;
                // cout << square(a[j], a[k], a[lf]) << endl;


                if (square(a[j], a[k], a[lf]) == s) {
                    cout << "Yes" << endl;
                    cout << a[j] << endl;
                    cout << a[k] << endl;
                    cout << a[lf] << endl;
                    return 0;
                }

                lf = -1;
                rg = l;

                while (rg - lf > 1) {
                    int mid = (lf + rg) / 2;
                    if (square(a[j], a[k], a[mid]) <= s) {
                        rg = mid;
                    } else {
                        lf = mid;
                    }
                }

                if (square(a[j], a[k], a[rg]) == s) {
                    cout << "Yes" << endl;
                    cout << a[j] << endl;
                    cout << a[k] << endl;
                    cout << a[rg] << endl;
                    return 0;
                }
            }
        }

        // for (int j = 0; j < n; ++j)
        //     cout << b[j] << " ";
        // cout << endl;

        for (int j = l; j <= r; ++j) {
            pos[b[j]] = j;
        }
    }

    cout << "No" << endl;
}