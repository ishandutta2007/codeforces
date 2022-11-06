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

template <typename T, typename Cmp=std::greater<T>>
using heap = priority_queue<T, std::vector<T>, Cmp>;

typedef long long lint;

int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cout << setprecision(11) << fixed;

    scidd(a, v, l, d, w);
    w = min(w, v);

    double ans = 0;
    double t1 = v / a;
    double s1 = a * t1 * t1 / 2;
    double t2 = (v - w) / a;
    double s2 = v * t2 - a * t2 * t2 / 2;
    double x = w * w / a / 2;
    if (s1 + s2 <= d) {
        ans = t1 + t2 + (d - s1 - s2) / v;
    } else if (x >= d) {
        if (v * v / a / 2 >= l) {
            cout << sqrt(2 * l / a);
        } else {
            cout << v / a + (l - v * v / a / 2) / v;
        }
        return 0;
    } else {
        double l = w / a;
        double r = 1e9;
        for (int i = 0; i < 1000; i++) {
            double t1 = (l + r) / 2;
            double t2 = t1 - w / a;
            if (a * t1 * t1 / 2 + a * t1 * t2 - a * t2 * t2 / 2 <= d) {
                l = t1;
            } else {
                r = t1;
            }
        }
        ans = l + l - w / a;
    }

    {
        l -= d;
        double t = (v - w) / a;
        double s = w * t + a * t * t / 2;
        if (s >= l) {
            double bl = 0;
            double br = 1e9;
            for (int i = 0; i < 1000; i++) {
                double t = (bl + br) / 2;
                if (w * t + a * t * t / 2 <= l) {
                    bl = t;
                } else {
                    br = t;
                }
            }
            ans += bl;
        } else {
            ans += t;
            l -= s;
            ans += l / v;
        }
    }

    cout << ans;

    return 0;
}