#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long lint;

int pow(int a, int p, int m) {
    if (p == 0) {
        return 1;
    }
    lint t = pow(a, p / 2, m);
    t = (t * t) % m;
    if (p % 2 == 1) {
        t = (t * a) % m;
    }
    return t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int mod = 1e9 + 9;
    int ans = 0;
    int t = max(0, n / k - n + m);
    ans = (pow(2, t + 1, mod) - 2 + mod) % mod * 1LL * k % mod;
    ans = ((ans + m - 1LL * t * k) % mod + mod) % mod;
    cout << ans;

    return 0;
}