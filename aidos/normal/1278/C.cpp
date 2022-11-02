#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)4e5 + 10;
const int mod = (int)998244353;
const int inf = (1<<30) - 1;
int n, m;
int a[maxn];
int dp[maxn];
void solve() {
    cin >> n;
    for(int i = 0; i < n * 2; i++) {
        scanf("%d", &a[i]);
    }
    int cur = n;
    for(int i = 0; i <= 2 * n; i++) dp[i] = -1;
    dp[cur] = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) cur++;
        else cur--;
        dp[cur] = i + 1;
    }
    int ans = dp[n];
    cur = n;
    for(int i = 2 * n-1; i >= n; i--) {
        if(a[i] == 2) cur++;
        else cur--;
        if(dp[cur] != -1) ans = max(ans, dp[cur] + 2 * n - i);
    }
    cout << 2 * n - ans << "\n";
}


int main() {
    int t = 1;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}