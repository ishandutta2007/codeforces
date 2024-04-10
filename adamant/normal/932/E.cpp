#include <bits/stdc++.h>
 
using namespace std;

#define link abaaalal

const int mod = 1e9 + 7;

int add(int a, int b) {
    int t = a + b;
    return t >= mod ? t - mod : t;
}

int mul(int a, int b) {
    return 1LL * a * b % mod;
}

int bpow(int x, int n) {
    return n ? n % 2 ? mul(x, bpow(x, n - 1)) : bpow(mul(x, x), n / 2) : 1;
}

const int maxn = 5e3 + 5;
int inv[maxn];

int fact[maxn], rfact[maxn];

int nCr(int n, int r) {
    return mul(fact[n], mul(rfact[r], rfact[n - r]));
}

vector<int> vals;

int eval(int n) {
    int ans = 0;
    for(int i = 0; i < vals.size(); i++) {
        int cur = vals[i];
        for(int j = 0; j < vals.size(); j++) {
            if(i != j) {
                cur = mul(cur, mul(n - j + mod, mod + (i < j ? -inv[j - i] : inv[i - j])));
            }
        }
        ans = add(ans, cur);
    }
    return ans;
}

int pw[maxn];

signed main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    fact[0] = rfact[0] = 1;
    for(int i = 1; i < maxn; i++) {
        inv[i] = bpow(i, mod - 2);
        fact[i] = mul(i, fact[i - 1]);
        rfact[i] = mul(inv[i], rfact[i - 1]);
        pw[i] = bpow(i, k);
    }
    vals.resize(k + 2);
    vals[0] = 0;
    for(int n = 1; n <= k + 1; n++) {
        int X = bpow(2, k - n + (mod - 1));
        for(int i = 0; i <= n; i++) {
            vals[n] = add(vals[n], mul(X, mul(pw[i], nCr(n, i))));
        }
    }
    
    cout << mul(bpow(2, n - k + (mod - 1)), eval(n)) << endl;
    return 0;
}