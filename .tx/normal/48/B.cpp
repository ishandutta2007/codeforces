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
};

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

int f[55][55];
int n, m;

int ans(int a, int b) {
    if (a > n || b > m) {
        return 1e9;
    }

    int res = 1e9;

    for (int i = a - 1; i < n; i++) {
        for (int j = b - 1; j < m; j++) {
            int cur = 0;
            for (int x = 0; x < a; x++) {
                for (int y = 0; y < b; y++) {
                    cur += f[i - x][j - y];
                }
            }
            res = min(res, cur);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    sci(n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sci(f[i][j]);
        }
    }

    scid(a, b);

    cout << min(ans(a, b), ans(b, a));


    return 0;
}