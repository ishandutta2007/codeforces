#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)2e5 + 10;
const int mod = (int)1e9 + 7;
const int inf = (1<<30) - 1;
const double pi = acos(-1);
int n;
int m;
int was[5050];
vector<int> g[5050];
int p[5050];
int c[5050];
int ans[5050];
int u[5050];
int T;
int par[5050];
bool dfs(int v) {
    if(u[v] == T) return 0;
    u[v] = T;
    for(const int &to: g[v]) {
        if(par[to] == -1 || dfs(par[to])) {
            par[to] = v;
            return 1;
        }
    }
    return 0;
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= n; i++) cin >> c[i];
    int d;
    cin >> d;
    vector<int> a;
    for(int i = 1; i <= m; i++)
        par[i] = -1;
    for(int i = 0; i < d; i++) {
        int x;
        cin >> x;
        a.push_back(x);
        was[x] = 1;
    }
    for(int i = 1; i <= n; i++){
        if(!was[i]) a.push_back(i);
    }
    int cur = 0;
    for(int i = n-1; i >= 0; i--) {
        int ind = a[i];
        T++;
        while(dfs(cur)) {
            cur++;
            T++;
        }
        ans[i] = cur;
        g[p[ind]].push_back(c[ind]);
    }
    for(int i = 0; i < d; i++) {
        cout << ans[i] << "\n";
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