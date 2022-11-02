#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)3e3 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, k;
int dp[maxn][maxn];
int get(int n, int k) {
    if(n == 0) return 1;
    int &res = dp[n][k];
    if(res != -1) return res;
    res = 0;
    for(int i = 1; i * i <= k; i++) {
        if(k % i == 0) {
            res = (res + get(n-1, i)) % mod;
            if(k != i * i) res = (res + get(n-1, k/i)) % mod;
        }
    }
    return res;
}
void solve() {
    memset(dp, -1, sizeof dp);
    cin >> n >> k;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = (ans + get(k-1, i)) % mod;
    }
    cout << ans << "\n";
}


int main() {
    //srand(time(0));
    int t = 1;
    //scanf("%d", &t);
    //cin >> t;
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}