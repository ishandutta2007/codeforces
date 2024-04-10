#include <bits/stdc++.h>
 
using namespace std;

#define int int64_t
const int mod = 1e9 + 7;

int bpow(int x, int n) {
    if(n == 0) {
        return 1;
    }
    if(n % 2 == 0) {
        return bpow(x * x % mod, n / 2);
    } else {
        return x * bpow(x, n - 1) % mod;
    }
}

int get(vector<int> a, int n, int z) {
    a[0] = max((int)0, a[0] - z);
    int fact[n + 1], rfact[n + 1];
    fact[0] = rfact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = i * fact[i - 1] % mod;
        rfact[i] = bpow(fact[i], mod - 2);
    }
    vector<int> ans(n + 1);
    ans[0] = 1;
    for(int i = 0; i < 10; i++) {
        vector<int> nans(n + 1);
        for(int k = 0; k <= n; k++) {
            for(int j = a[i]; j + k <= n; j++) {
                nans[j + k] += ans[k] * rfact[j] % mod;
                nans[j + k] %= mod;
            }
        }
        ans = nans;
    }
    return ans[n] * fact[n] % mod;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(10);
    for(int i = 0; i < 10; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += get(a, i, 0) - get(a, i - 1, 1) + mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}