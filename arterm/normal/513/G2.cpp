#include <bits/stdc++.h>

using namespace std;

#define M 239
#define K 33

int rot(int x, int l, int r) {
    if (x < l || r < x)
        return x;
    return l + r - x;
}

int n, k, p[M];
double d[K][K][M];

void read() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
}

void kill() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            d[i][j][0] = 0.0;

    int m = n * (n + 1) / 2;
    double prob = 1.0 / m;

    for (int t = 1; t <= k; ++t)
        for (int l = 1; l <= n; ++l)
            for (int r = l; r <= n; ++r)
                for (int i = 1; i <= n; ++i)
                    for (int j = i + 1; j <= n; ++j) {
                        int it = rot(i, l, r);
                        int jt = rot(j, l, r);
                        if (it < jt)
                            d[i][j][t] += d[it][jt][t - 1] * prob;
                        else
                            d[i][j][t] += (1.0 - d[jt][it][t -1]) * prob;
                    }
    double ans = 0.0;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (p[i] < p[j])
                ans += d[i][j][k];
            else
                ans += 1.0 - d[i][j][k];
    cout << ans << "\n";
}


int main() {
    cout.precision(12);
    cout << fixed;
    read();
    kill();
    return 0;
}