#include<bits/stdc++.h>

using namespace std;

constexpr long long mod = 1000000007;

long long solve(int n, vector<int>& a) {
    int t = 0;
    for (int bit = 0; bit < 32; bit++) {
        int s = 0;
        for (int v : a) {
            s += (v >> bit) & 1;
        }
        if (s == n) {
            t |= 1 << bit;
        }
    }
    long long cnt_t = 0;
    for (int v : a) {
        cnt_t += v == t;
    }
    long long ans = cnt_t * (cnt_t - 1) % mod;
    for (int i = 1; i <= n - 2; ++i) {
        ans = ans * i % mod;
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t --> 0) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << solve(n, a) << '\n';
    }
    return 0;
}