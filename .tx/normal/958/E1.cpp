#ifndef CONTESTSMTH_HEADER_H
#define CONTESTSMTH_HEADER_H

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

template <typename K, typename V = __gnu_pbds::null_type>
using tree = __gnu_pbds::tree<K, V, less<K>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <typename K, typename V = __gnu_pbds::null_type>
using htable = __gnu_pbds::gp_hash_table<K, V>;
using llong = long long;
auto isz = [](const auto& c) { return int(c.size()); };
#ifdef VSE
mt19937 rng(0);
#else
mt19937 rng((size_t) make_shared<char>().get());
#endif

#endif //CONTESTSMTH_HEADER_H

#ifndef CONTESTSMTH_UTILS_H
#define CONTESTSMTH_UTILS_H



template <typename T, T val = T()>
auto make_vector(size_t d) {
    return vector<T>(d, val);
}

template <typename T, T val = T(), typename ...Ds>
auto make_vector(size_t d, Ds... ds) {
    return vector<decltype(make_vector<T, val>(ds...))>(d, make_vector<T, val>(ds...));
}

llong min(int a, llong b) {
    return min<llong>(a, b);
}

llong min(llong a, int b) {
    return min<llong>(a, b);
}

llong max(int a, llong b) {
    return max<llong>(a, b);
}

llong max(llong a, int b) {
    return max<llong>(a, b);
}

template <typename T>
void relmax(T& a, const T& b) {
    a = max(a, b);
}

template <typename T>
void relmin(T& a, const T& b) {
    a = min(a, b);
}

#endif //CONTESTSMTH_UTILS_H

#define GEOM_INTEGER
#ifndef CONTESTSMTH_GEOM_H
#define CONTESTSMTH_GEOM_H

namespace geom {
#ifdef GEOM_INTEGER
    using dbl = llong;
#else
    using dbl = long double;
#endif
struct point {
    dbl x, y;

    point operator+(point p) {
        return point{x + p.x, y + p.y};
    }

    point operator-(point p) {
        return point{x - p.x, y - p.y};
    }

    dbl operator*(point p) {
        return x * p.y - y * p.x;
    }

    dbl operator%(point p) {
        return x * p.x + y * p.y;
    }

    point operator*(dbl k) {
        return point{x * k, y * k};
    }

    dbl dist2(point p) {
        return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
    }
#ifndef GEOM_INTEGER
    point norm() {
        dbl d = sqrt(x * x + y * y);
        return point{x / d, y / d};
    }

    point rotate(dbl ang) {
        return point{x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang)};
    }

    dbl dist(point p) {
        return sqrt(this->dist2(p));
    }
#endif
};

struct line {
    dbl a, b, c;

    line(point p, point q) {
        a = q.y - p.y;
        b = p.x - q.x;
        c = -(a * p.x + b * p.y);
    }
};
} // namespace geom

#endif //CONTESTSMTH_GEOM_H


struct Solver {
    void solve() {
        using namespace geom;
        int r, b;
        cin >> r >> b;
        vector<point> rs(r), bs(b);
        for (int i = 0; i < r; i++) {
            cin >> rs[i].x >> rs[i].y;
        }
        for (int i = 0; i < b; i++) {
            cin >> bs[i].x >> bs[i].y;
        }

        if (r != b) {
            cout << "No\n";
            return;
        }

        for (int it = 0; it + 1 < r; it++) {
            int rp = -1;
            int bp = -1;

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < b; j++) {
                    point v = rs[i] - bs[j];
                    int neg = 0;
                    int pos = 0;
                    int zer = 0;
                    for (int k = 0; k < r; k++) {
                        if (k == i) {
                            continue;
                        }
                        auto t = v * (rs[k] - bs[j]);
                        if (t < 0) {
                            neg++;
                        } else if (t > 0) {
                            pos++;
                        } else {
                            zer++;
                        }
                    }
                    assert(zer == 0);
                    for (int z = 0; z < b; z++) {
                        if (z == j) {
                            continue;
                        }
                        auto t = v * (bs[z] - bs[j]);
                        if (t < 0) {
                            neg++;
                        } else if (t > 0) {
                            pos++;
                        } else {
                            zer++;
                        }
                    }
                    assert(zer == 0);
                    if (neg + pos + zer != r + b - 2 || !(neg == 0 || pos == 0)) {
                        continue;
                    }
                    rp = i;
                    bp = j;
                }
            }
            if (rp == -1) {
                cout << "No\n";
                return;
            }
            swap(rs.back(), rs[rp]);
            rs.pop_back();
            swap(bs.back(), bs[bp]);
            bs.pop_back();
            --r; --b;
        }
        cout << "Yes\n";
    }
};

int main(int argc, char** argv) {
#ifdef VSE
    if (argc > 1) assert(freopen(argv[1], "r", stdin));
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    for (int it = 1; it <= t; it++) {
        Solver().solve();
    }
    return 0;
}