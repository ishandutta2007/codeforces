#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int M = 1e9 + 7;

int ad(int x, int y) {
    return (x + y) % M;
}
int dif(int x, int y) {
    return (x - y + M) % M;
}

using ll = long long;

int mul(int x, int y) {
    return (x * (ll)y) % M;
}

int inv(int x) {
    int y = M - 2;
    int z = 1;
    while (y) {
        if (y & 1)
            z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}

int ifa(int k) {
    int w = 1;
    for (int i = 2; i <= k; i++)
        w = mul(w, i);
    w = inv(w);
    return w;
}

int fa(int k) {
    int w = 1;
    for (int i = 2; i <= k; i++)
        w = mul(w, i);
    return w;
}

int C(int n, int k) {
    if (n < k)
        return 0;
    int w = 1;
    for (int i = 0; i < k; i++)
        w = mul(w, n - i);
    return mul(w, ifa(k));
}

int A(int n, int k) {
    if (n < k)
        return 0;
    int w = 1;
    for (int i = 0; i < k; i++)
        w = mul(w, n - i);
    return w;
}

int q[210][500];

int main() {
#ifdef BZ
    freopen("../a.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    n = 1e9;
    k = 200;
    cin >> n >> k;

    q[0][0] = 1;
    for (int s = 0; s <= k; s++)
        for (int i = 0; i <= 2 * k; i++)
        if (q[s][i] != 0) {
            for (int z = 2; z <= k + 1; z++)
            if (s + z - 1 <= k && i + z <= 2 * k) {
                int &x = q[s + z - 1][i + z];
                x = ad(x, mul(q[s][i], A(i + z - 1, z - 1)));
            }
        }

    vector<int> dp(2 * k + 1);
    dp[0] = 1;
    dp[1] = C(n, 2);
    for (int i = 2; i <= k; i++) {
        dp[i] = dp[i - 2];
        for (int j = 0; j <= 2 * i; j++)
            dp[i] = ad(dp[i], mul(q[i][j], C(n, j)));
    }
    for (int i = 1; i <= k; i++)
        cout << dp[i] << ' ';
}