#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 1e9 + 9;

int bpow(int x, int n) {
    return n ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}

int inv(int x) {
    return bpow(x, mod - 2);
}

int geom(int c, int k) {
    if(c == 1) {
        return k + 1;
    } else {
        return (1 - bpow(c, k + 1) + mod) * inv(1 - c + mod) % mod;
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;
    int ans = 0;
    int c = geom(bpow(b * inv(a) % mod, k), n / k);
    for(int i = 0; i < k; i++) {
        int ss = s[i] == '+' ? 1 : mod - 1;
        int t = bpow(b, i) * bpow(a, n - i) % mod * c % mod;
        ans += ss * t % mod;
        ans %= mod;
    }
    cout << ans << endl;
    
}