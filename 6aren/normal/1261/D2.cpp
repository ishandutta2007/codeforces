#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int MOD = 998244353;
const int N = 200005;

int fac[N], ifac[N], h[N];

int power(int x, int y) {
    if (y == 0) return 1;
    int temp = power(x, y / 2);
    temp = 1LL * temp * temp % MOD;
    if (y % 2) temp = 1LL * temp * x % MOD;
    return temp;
}

int inv(int x) {
    return power(x, MOD - 2);
}

int C(int x, int y) {
    return 1LL * fac[y] * (1LL * ifac[x] * ifac[y - x] % MOD) % MOD;
}

int calc(int k, int choose, int from) {
    int u = (choose % 2 == 0) ? C(choose / 2, choose) : 0;
    return 1LL * power(k - 2, from - choose) * C(choose, from) % MOD * (1LL * (power(2, choose) - u + MOD) * inv(2) % MOD) % MOD;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = (1LL * fac[i - 1] * i) % MOD;
    }
    for (int i = 0; i < N; i++) {
        ifac[i] = inv(fac[i]);
    }
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    if (k == 1) return cout << 0, 0;
    h[n + 1] = h[1];
    int cntEqual = 0;
    for (int i = 1; i <= n; i++) {
        if (h[i] == h[i + 1]) {
            cntEqual++;
        }
    }
    int res = 0;
    int cntDiff = n - cntEqual;
    for (int i = 1; i <= cntDiff; i++) {
        res = (res + calc(k, i, cntDiff)) % MOD;
    }
    res = (1LL * res * power(k, cntEqual)) % MOD;
    cout << res;
    return 0;
}