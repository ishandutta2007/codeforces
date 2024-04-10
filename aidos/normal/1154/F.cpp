#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)5e5 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
int n, m, k;
ll sum[maxn];
int a[maxn];
int b[maxn];
ll dp[6040];
void solve() {
    cin >> n >>m>> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
    ll ans=sum[k];
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if(x > k) {
        } else {
            b[x] = max(b[x], y);
        }
    }

    for(int i = 0; i <= k; i++) dp[i] = ans + 1;
    dp[0] = 0;
    for(int i = 0; i <= k; i++) {
        for(int j = 1; j <= k && i + j <= k; j++) {
            dp[i + j] = min(dp[i] + sum[i + j] - sum[i + b[j]], dp[i + j]);
        }
    }
    cout << min(ans, dp[k]) << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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