#include <iostream>
#include <algorithm>

using namespace std;

#define A 20
#define M 1111000
#define mod 1000000007ll

int f[A + 1][M], p[M];

void read() {
    int n;
    cin >> n;
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        f[0][x]++;
    }
}

void din() {
    for (int k = 0; k < A; ++k)
        for (int i = 0; i < (1 << A); ++i)
            if (i & (1 << k))
                f[k + 1][i] = f[k][i];
            else
                f[k + 1][i] = f[k][i] + f[k][i | (1 << k)];
}

void kill() {
    p[0] = 1;
    for (int i = 1; i < M; ++i) {
        p[i] = 2 * p[i - 1];
        if (p[i] >= mod)
            p[i] -= mod;
    }
    int ans = 0;
    for (int i = 0; i < (1 << A); ++i) {
        int t = __builtin_popcount(i);
        if (t & 1) {
            ans -= p[f[A][i]];
            if (ans < 0)
                ans += mod;
        } else {
            ans += p[f[A][i]];
            if (ans >= mod)
                ans -= mod;
        }
    }

    cout << ans << "\n";
}

int main() {
#ifdef TROLL
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout); 
#endif
    ios_base::sync_with_stdio(0);

    read();
    din();
    kill();

    return 0;
}