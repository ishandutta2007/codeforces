#include <bits/stdc++.h>
using namespace std;

const int N = 2000005;
const int MOD = 998244353;

int cnt[N];
int dp[N], pref[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) cnt[j]++;
    }
    
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        dp[i] = (cnt[i] + pref[i - 1]) % MOD;
        pref[i] = (pref[i - 1] + dp[i]) % MOD;
    }
    cout << dp[n] << endl;

    return 0;
}