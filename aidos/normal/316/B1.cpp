#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9;
const int inf = (1<<30) - 1;

int p[maxn];
int a[maxn];
int n;
int x;
int dp[maxn];
int u[maxn];

int dfs(int v) {
    u[v] = 1;
    if(a[v] == 0) return 1;
    return dfs(a[v]) + 1;
}
int rdfs(int v) {
    u[v] = 1;
    if(p[v] == 0) return 1;
    return rdfs(p[v])+1;
}

void solve() {
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        p[a[i]] = i;
    }
    int sz1 = dfs(x);
    int sz2 = rdfs(x);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        if(u[i]) continue;
        int y = dfs(i) + rdfs(i) - 1;
        for(int j = n; j >= y; j--) {
            dp[j] |= dp[j-y];
        }
    }
    for(int i = 0; i<=n; i++) {
        if(dp[i]) cout << i + sz1 << "\n";
    }
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