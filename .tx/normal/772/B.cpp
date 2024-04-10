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

lint x[1111];
lint y[1111];

int main() {
#ifdef TOXA31
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        sci(x[i], y[i]);
    }

    double ans = 1e30;

    for (int i = 0; i < n; i++) {
        int cr = i;
        int nx = i + 1;
        if (nx == n) {
            nx = 0;
        }
        lint a = y[nx] - y[cr];
        lint b = x[cr] - x[nx];
        lint c = -(a * x[cr] + b * y[cr]);

        for (int j = 0; j < n; j++) {
            if (j == cr || j == nx) {
                continue;
            }
            double d = abs(a * x[j] + b * y[j] + c) / sqrt(a * a + b * b);
            ans = min(ans, d / 2);
        }
    }

    for (int i = 0; i < n; i++) {
        int cr = i;
        int md = (i + 1) % n;
        int nx = (i + 2) % n;

        lint a = y[nx] - y[cr];
        lint b = x[cr] - x[nx];
        lint c = -(a * x[cr] + b * y[cr]);
        double d = abs(a * x[md] + b * y[md] + c) / sqrt(a * a + b * b);
        ans = min(ans, d / 2);
    }

    cout << setprecision(11) << fixed << ans;


    return 0;
}