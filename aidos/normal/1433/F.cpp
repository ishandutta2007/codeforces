#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxm = (int)1e7 + 100;
const int maxn = (int) 5e5 + 100;
const int mod = (int)998244353 ;
int n, m, k;
int dp[77][77][77][77];
int a[77][77];
int get(int i, int j, int cnt, int sum) {
    if(cnt > m/2) return -mod;
    if(j == m) {
        i++;
        j = 0;
        cnt = 0;
    }
    if(i == n) {
        if(sum == 0) return 0;
        return -mod;
    }
    int &res = dp[i][j][cnt][sum];
    if(res != -1) return res;
    res = get(i, j+1, cnt, sum);
    res = max(get(i, j+1, cnt+1, (sum + a[i][j]) % k) + a[i][j], res);
    return res;
}
void solve() {
    cin  >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    cout << get(0, 0, 0, 0) << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for(int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}