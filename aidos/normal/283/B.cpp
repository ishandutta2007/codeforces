#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n, k;
ll dp[maxn][2];
int u[maxn][2];
int a[maxn];
ll dfs(int v, int id) {
    if(v > n || v < 1) return 0;
    if(v == 1) {
        return -1;
    }
    if(u[v][id]) return dp[v][id];
    int h = v;
    if(id) h -= a[v];
    else h += a[v];
    u[v][id] = 1;
    dp[v][id] = -1;
    ll res = dfs(h, id^1);
    if(res != -1) {
        dp[v][id] = res + a[v];
    }
    return dp[v][id];
}
void solve() {
    cin >> n;
    for(int i = 2; i <= n; i++) cin >> a[i];
    for(int i = 2; i <= n; i++) {
        ll res = dfs(i, 1);
        if(res >= 0) res += i-1;
        cout << res << "\n";
    }
}


int main() {
    ios_base::sync_with_stdio(false);
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