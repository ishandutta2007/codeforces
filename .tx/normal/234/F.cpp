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

typedef long long lint;

int h[222];
int s[222];

int d[222][44444][2];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, a, b);
    for (int i = 0; i < n; i++) {
        sci(h[i]);
        s[i] = h[i];
        if (i) {
            s[i] += s[i - 1];
        }
    }

    for (int i = 0; i < 222; i++) {
        for (int j = 0; j < 44444; j++) {
            for (int t = 0; t < 2; t++) {
                d[i][j][t] = 1e9;
            }
        }
    }

    d[0][h[0]][0] = 0;
    d[0][0][1] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 44444; j++) {
            if (j >= h[i]) {
                d[i][j][0] = min(d[i - 1][j - h[i]][0], d[i - 1][j - h[i]][1] + min(h[i], h[i - 1]));
            }
            d[i][j][1] = min(d[i - 1][j][1], d[i - 1][j][0] + min(h[i], h[i - 1]));
        }
    }

    int fin = s[n - 1];
    int ans = 1e9;

    for (int j = 0; j <= a; j++) {
        int nb = fin - j;
        if (nb >= 0 && nb <= b) {
            ans = min(ans, min(d[n - 1][j][0], d[n - 1][j][1]));
        }
    }

    cout << (ans == 1e9 ? -1 : ans);

    return 0;
}