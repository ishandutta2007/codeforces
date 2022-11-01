#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int n, dif, sz;
ll fac[751], dp[751][750], c[751][751];
vector<int> a, val;

bool sqr(ll x) {
    ll y = sqrt(.0 + x);
    return y * y == x;
}

int main() {
    fac[0] = 1;
    for(int i = 1; i <= 750; i++) fac[i] = fac[i - 1] * i % mod;
    c[0][0] = 1;
    for(int i = 0; i <= 750; i++)
        for(int j = 0; j <= i; j++)
            if(i || j)
                c[i][j] = ((i ? c[i - 1][j] : 0) + (i && j ? c[i - 1][j - 1] : 0)) % mod;
    dp[0][0] = 1;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        bool done = false;
        for(int j = 0; j < val.size(); j++)
            if(sqr((ll)x * val[j])) { a[j]++; done = true; break; }
        if(!done) { a.push_back(1); val.push_back(x); }
    }
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j <= sz; j++)
            for(int k = 1; k <= min(a[i], sz + 1); k++)
                for(int l = 0; l <= min(j, k); l++)
                    dp[dif + 1][j - l + a[i] - k] = (dp[dif + 1][j - l + a[i] - k] + dp[dif][j] * c[a[i] - 1][k - 1] % mod * c[j][l] % mod * c[sz + 1 - j][k - l] % mod * fac[a[i]] % mod) % mod;
        dif++;
        sz += a[i];
    }
    cout << dp[a.size()][0];
}