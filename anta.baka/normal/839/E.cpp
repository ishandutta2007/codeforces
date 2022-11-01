#include <bits/stdc++.h>
using namespace std;

int n, k, g[40][40], dp[1 << 20], opt;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    if(n == 1) return cout << 0, 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> g[i][j];
    for(int m = 1; m < (1 << (n / 2)); m++) {
        int v = 0, e = 0;
        for(int i = 0; i < n / 2; i++)
            if(m & (1 << i)) {
                v++;
                for(int j = 0; j < n / 2; j++)
                    if(m & (1 << j))
                        e += g[i][j];
            }
        if(e == v * (v - 1)) { dp[m] = v; continue; }
        for(int i = 0; i < n / 2; i++)
            if(m & (1 << i))
                dp[m] = max(dp[m], dp[m - (1 << i)]);
    }
    opt = dp[(1 << (n / 2)) - 1];
    for(int m = 1; m < (1 << ((n + 1) / 2)); m++) {
        int v = 0, e = 0;
        for(int i = 0; i < (n + 1) / 2; i++)
            if(m & (1 << i)) {
                v++;
                for(int j = 0; j < (n + 1) / 2; j++)
                    if(m & (1 << j))
                        e += g[i + n / 2][j + n / 2];
            }
        if(e != v * (v - 1)) continue;
        vector<bool> v2(n, false);
        for(int i = 0; i < n; i++)
            if(m & (1 << i))
                v2[i + n / 2] = true;
        int m2 = 0;
        for(int i = 0; i < n / 2; i++) {
            bool all = true;
            for(int j = n / 2; j < n; j++)
                if(v2[j])
                    all &= g[i][j];
            if(all) m2 += (1 << i);
        }
        opt = max(opt, v + dp[m2]);
    }
    cout.precision(10);
    cout << fixed << (opt - 1) * k * k / 2.0 / opt;
}