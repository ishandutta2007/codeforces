#include<bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)
#define int int64_t

const int mod = 998244353;

int C[2002][2002];

int nCr(int n, int r) {
    if(!C[n][r]) {
        if(n < r) {
            return 0;
        } else if(r == 0) {
            return 1;
        } else {
            return C[n][r] = (nCr(n - 1, r) + nCr(n - 1, r - 1)) % mod;
        }
    } else {
        return C[n][r];
    }
}

int bpow(int x, int n) {
    return n ? n % 2 ? x * bpow(x, n - 1) % mod : bpow(x * x % mod, n / 2) : 1;
}

signed main(){
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    if(k == 0) {
        cout << m << endl;
    } else {
        cout << nCr(n - 1, k) * m % mod * bpow(m - 1, k) % mod;
    }
    return 0;
}