#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)
#define sz(s) ((int) (s).size())

const int N = 2000005;
const int M = 2005;
const int MOD = 1000000007;

int h, w, m;
int fac[N], ifac[N], inv[N];
int dp[M];

int C(int k, int n) {
    return (1LL * fac[n] * ifac[k] % MOD * ifac[n - k] % MOD);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> h >> w >> m;
    fac[0] = ifac[0] = inv[1] = fac[1] = ifac[1] = 1;
    for (int i = 2; i <= h + w + 5; i++) {
        inv[i] = 1LL * (MOD - MOD / i) * inv[MOD % i] % MOD;
        fac[i] = 1LL * fac[i - 1] * i % MOD;
        ifac[i] = 1LL * ifac[i - 1] * inv[i] % MOD;
    }
    vector<ii> p;
    p.pb({1, 1});
    p.pb({h, w});
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        p.push_back({u, v});
    }
    sort(all(p));
    for (int i = 0; i < sz(p); i++) {
        dp[i] = C(p[i].x - 1, p[i].x + p[i].y - 2);
        for (int j = 1; j < i; j++) {
            if (p[j].y <= p[i].y) {
                int temp = 0;
                temp = 1LL * dp[j] * C(p[i].y - p[j].y, p[i].x + p[i].y - p[j].x - p[j].y) % MOD; 
                dp[i] = (dp[i] - temp + MOD) % MOD;
            }
        }
    }
    cout << dp[m + 1];
    return 0;
}