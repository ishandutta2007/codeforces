#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 5005;
const int MOD = 998244353;

int n, m, k;
int fac[N], ifac[N];
int cn[N];
int p[N][N];

int mult(int x, int y) {
    return 1LL * x * y % MOD;
}

int add(int x, int y) {
    return (x + y) % MOD;
}

int sub(int x, int y) {
    int res = x - y;
    res += (res < 0) * MOD;
    return res;
}

int power(int x, int y) {
    if (!y) return 1;
    int tmp = power(x, y / 2);
    tmp = mult(tmp, tmp);
    if (y % 2) tmp = mult(x, tmp);
    return tmp;
}

int inv(int x) {
    return power(x, MOD - 2);
}

int C(int x, int y) {
    return mult(fac[y], mult(ifac[x], ifac[y - x]));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    fac[0] = 1; ifac[0] = 1;
    cn[0] = 1;
    for (int i = 1; i <= k; i++) {
        fac[i] = mult(fac[i - 1], i);
        ifac[i] = inv(fac[i]);
        cn[i] = mult(cn[i - 1], mult(inv(i), n - i + 1));
    }
    for (int i = 1; i <= k; i++) {
        p[i][0] = 1;
        for (int j = 1; j <= k; j++) {
            p[i][j] = mult(p[i][j - 1], i);
        }
    }
    int ans = 0;
    for (int i = 1; i <= k; i++) {
        int temp = 0;
        int sign = 1;
        for (int j = i; j > 0; j--) {
            temp = add(temp, mult(sign, mult(C(j, i), p[j][k])));
            sign = MOD - sign;
        }
        temp = mult(temp, cn[i]);
        temp = mult(temp, power(inv(m), i));
        ans = add(ans, temp);
    }
    cout << ans;
    return 0;
}