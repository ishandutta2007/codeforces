#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

template <typename T, typename Cmp=std::greater<int>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

int x[66666];
int v[66666];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        sci(x[i]);
    }
    for (int i = 0; i < n; i++) {
        sci(v[i]);
    }

    double l = 0, r = 1e9;
    for (int it = 0; it < 200; it++) {
        double m = (l + r) / 2;
        vector<pair<double, int> > ps;
        for (int i = 0; i < n; i++) {
            ps.push_back({x[i] - v[i] * m, -1});
            ps.push_back({x[i] + v[i] * m, 1});
        }
        sort(ps.begin(), ps.end());
        int c = 0;
        bool ok = false;
        for (auto p : ps) {
            c -= p.second;
            if (c == n) {
                ok = true;
                break;
            }
        }
        if (ok) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << setprecision(11) << fixed << l;

    return 0;
}