#pragma GCC optimize("Ofast,unroll-loops,fast-math,inline,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

int M;

int add(int a, int b) {
    return (a + b) % M;
}

int sub(int a, int b) {
    return (a - b + M) % M;
}

int mul(int a, int b) {
    return 1LL * a * b % M;
}

struct pairhash {
public:
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const
  {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};

int cc[410][410];

void prepare2() {
    for (int i = 0; i < 410; i++) {
        cc[i][0] = 1;
        cc[i][i] = 1;
    }
    for (int i = 1; i < 410; i++) {
        for (int j = 1; j < i; j++) {
            cc[i][j] = add(cc[i - 1][j - 1], cc[i - 1][j]);
        }
    }
}

int C(int n, int k) {
    return cc[n][k];
}

unordered_map<int, int> memo2;

int get2(int n) {
    if (memo2.count(n))
        return memo2[n];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = add(ans, C(n - 1, i - 1));
    }
    return memo2[n] = ans;
}

int dp[410][410];

int get(int n, int k) {
    if (n == 0) {
        if (k != 0)
            return dp[n][k] = 0;
        return dp[n][k] = 1;
    }
    if (n == 1) {
        if (k != 1) {
            return dp[n][k] = 0;
        }
        return dp[n][k] = 1;
    }
    if (n == k) {
        return dp[n][k] = get2(n);
    }
    int ans = 0;
    for (int empt = 2; empt < n && empt - 1 <= k; empt++) {
        if (k - empt + 1 >= 0) {
            int cnt = mul(get2(empt - 1), C(k, empt - 1));
            cnt = mul(cnt, dp[n - empt][k - empt + 1]);
            ans = add(ans, cnt);

        }
    }
    dp[n][k] = ans;
    return ans;
}

void prepare() {
    for (int n = 0; n <= 400; n++) {
        for (int k = (n + 1) / 2; k <= n; k++) {
            get(n, k);
        }
    }
}

void solve() {
    int n;
    cin >> n >> M;
    prepare2();
    prepare();
    int ans = 0;
    for (int i = (n + 1) / 2; i <= n; i++) {
        ans = add(ans, dp[n][i]);
    }
    cout << ans << endl;
}

signed main() {
    int t = 1;
    while (t--) {
        solve();
    }
}