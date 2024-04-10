#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 10;
const int MOD = 998244353;

int a[MAXN];

int power(int a, int b) {
    if (b == 0)
        return 1;
    int ret = power(a, b / 2);
    ret = 1LL * ret * ret % MOD;
    if (b & 1)
        ret = 1LL * ret * a % MOD;
    return ret;
}

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        a[i] += a[i - 1];
    }
    int B = 1LL * n * (n - 1) % MOD * power(2, MOD - 2) % MOD;
    int A = a[n - sum];
    int answer = 0;
    while (A > 0) {
        answer = (answer + 1LL * B * power(1LL * A * A % MOD, MOD - 2)) % MOD;
        A--;
    }
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
}