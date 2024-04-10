#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int bpow(int x, int n, int p) {
    return n ? n % 2 ? x * bpow(x, n - 1, p) % p : bpow(x * x % p, n / 2, p) : 1;
}

int inv(int x, int p) {
    return bpow(x, p - 2, p);
}

const int maxn = 1e6 + 42;
vector<int> pos[maxn];

int calc(int a, int b, int p, int x) {
    // t % p = a
    // t % (p - 1) = b
    int P = p * (p - 1);
    int rem = (a * (p - 1) * (p - 1) + b * p) % P;
    if(x < rem) {
        return 0;
    } else if(rem == 0) {
        return x / P;
    } else {
        return 1 + (x - rem) / P;
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b, p, x;
    cin >> a >> b >> p >> x;
    int ans = 0;
    for(int i = 0; i < p - 1; i++) {
        pos[bpow(a, i, p)].push_back(i);
    }
    for(int n = 1; n < p; n++) {
        for(auto it: pos[b * inv(n, p) % p]) {
            ans += calc(n, it, p, x);
        }
        
    }
    cout << ans << endl;
    return 0;
}