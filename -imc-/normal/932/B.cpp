#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int modpow(int x, int p) {
    int ans = 1;
    while (p) {
        if (p % 2)
            ans = ans * (li)x % MOD;
        p /= 2;
        x = x * (li)x % MOD;
    }
    return ans;
}

const int maxN = 1e6 + 100;
int g[maxN];
int cnt[maxN][10];

void solve(bool __attribute__((unused)) read) {
    for (int i = 1; i <= maxN; ++i) {
        int cur = i;
        int p = 1;
        while (cur) {
            int d = cur % 10;
            if (d) p *= d;
            cur /= 10;
        }
        
        if (i < 10)
            g[i] = i;
        else
            g[i] = g[p];
        
        for (int t = 0; t < 10; ++t)
            cnt[i][t] = cnt[i - 1][t] + (g[i] == t ? 1 : 0);
    }
    
    int nq;
    cin >> nq;
    
    for (int i = 0; i < nq; ++i) {
        int l, r, k;
        cin >> l >> r >> k;
        
        cout << (cnt[r][k] - cnt[l - 1][k]) << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    //while (true) solve(false);
    
    return 0;
}