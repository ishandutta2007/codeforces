#include <bits/stdc++.h> 

using namespace std;

#define int int64_t

const int mod = 1e9 + 7;
int fact[1111], rfact[1111];

int nCr(int n, int r) {
    if(n < 0 || r < 0 || n < r) {
        return r == 0;
    }
    return fact[n] * rfact[r] % mod * rfact[n - r] % mod;
}

int cnt(string s, int k) {
    int n = s.size();
    int ans = 0;
    for(int i = 0; i <= n; i++) {
        if(i == n || s[i] == '1') {
            ans += nCr(n - i - 1, k);
            ans %= mod;
            k--;
        }
    }
    return ans;
}

int bpow(int x, int n) {
    return n ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    fact[0] = rfact[0] = 1;
    for(int i = 1; i <= 1000; i++) {
        fact[i] = fact[i - 1] * i % mod;
        rfact[i] = bpow(fact[i], mod - 2);
    }
    string s;
    int k;
    cin >> s >> k;
    if(k == 0) {
        cout << 1 << endl;
        return 0;
    }
    int lol[1001];
    lol[1] = 0;
    int ans = 0;
    for(int i = 2; i <= 1000; i++) {
        lol[i] = lol[__builtin_popcount(i)] + 1;
    }
    for(int i = 1; i <= 1000; i++) {
        if(lol[i] == k - 1) {
            ans += cnt(s, i);
            ans %= mod;
        }
    }
    if(k == 1) {
        ans = (ans + mod - 1) % mod;
    }
    cout << ans << endl;
    return 0;
}