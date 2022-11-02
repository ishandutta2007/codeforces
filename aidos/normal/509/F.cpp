#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = (int)2e5 + 10;
const int mod = (int) 1e9 + 7;
int p[maxn];
int dp[555][555];
int d[555][555];
int n;
int get1(int, int);
int get2(int l, int r) {
    if(l >= r) return 1;
    int &res = d[l][r];
    if(res != -1) return res;
    res = get1(l, r);
    for(int m = l + 1; m <= r; m++) {
        if(p[l] < p[m]) res = (res + get1(l, m-1) * 1ll * get2(m, r)) % mod;
    }
    return res;
}
int get1(int l, int r) {
    if(l >= r) return 1;
    int &res = dp[l][r];
    if(res != -1) return res;
    res = get2(l + 1, r);
    return res;
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    memset(dp, -1, sizeof dp);
    memset(d, -1, sizeof d);
    cout << get1(1, n) << "\n";
}
int main() {
    int t=1;
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        solve();
    }
    return 0;
}