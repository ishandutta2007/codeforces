#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = (int)2e5 + 10;
const ll inf = 2e18;
int n, m;
int a[maxn], b[maxn];
int dp[maxn];
const int mod = 998244353;
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> pos;
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        pos[b[i]] = i + 1;
    }
    int mx = a[n-1];
    for(int i = n-1; i >= 0; i--) {
        mx = min(a[i], mx);
        if(mx == b[m-1]) {
            dp[m] = (dp[m] + 1) % mod;
        } else if(pos.count(mx)){
            int cur=pos[mx];
            dp[cur] = (dp[cur] + dp[cur+1]) % mod;
        }
    }
    if(mx == b[0]) {
        if(m == 1) cout << 1 << "\n";
        else cout << dp[2] << "\n";
    } else {
        cout << 0 << "\n";
    }
}
int main () {
    int t=1;
    //cin >> t;
    for(int i=1; i <= t; i++) {
        solve();
    }
    return 0;
}