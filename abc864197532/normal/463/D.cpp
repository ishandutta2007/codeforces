#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int> 
#define X first
#define Y second
const int N = 1000;
vector <int> adj[N];
int dp[N];

int dfs (int v) {
    if (dp[v] != -1) return dp[v];
    int ans = 0;
    for (int u : adj[v]) {
        ans = max(ans, dfs(u) + 1);
    }
    return dp[v] = ans;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int count[n][n];
    fop (i,0,n) fop (j,0,n) count[i][j] = 0;
    fop (i,0,k) {
        int a[n];
        fop (i,0,n) cin >> a[i], a[i]--;
        fop (i,0,n) {
            fop (j,i+1,n) {
                count[a[i]][a[j]]++;
            }
        }
    }
    fop (i,0,n) dp[i] = -1;
    fop (i,0,n) fop (j,0,n) if (count[i][j] == k) adj[i].pb(j);
    fop (i,0,n) if (dp[i] == -1) dfs(i);
    int ans = 0;
    fop (i,0,n) ans = max(ans, dp[i]);
    cout << ans + 1 << endl;
}