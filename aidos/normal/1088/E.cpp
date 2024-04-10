#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int) 1e9 + 7;
const int inf = (1<<30) - 1;
int a[maxn];
int n;
vector<int> g[maxn];
ll mx = -(1ll<<60);
ll d[maxn];

void dfs(int v, int pa) {
    for(int to: g[v]){
        if(to!=pa) {
            dfs(to, v);
            d[v] += max(d[to], 0ll);
        }
    }
    d[v] += a[v];
    mx = max(mx, d[v]);
}
int cnt = 0;
void dfs2(int v, int pa) {
    d[v] = a[v];
    for(int to: g[v]) {
        if(to != pa) {
            dfs2(to, v);
            d[v] += max(d[to], 0ll);
        }
    }
    if(mx == d[v]) {
        d[v] = 0;
        cnt++;
    }
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++) {
        int x, y;
        cin>>x>>y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    dfs(1, -1);
    dfs2(1, -1);
    cout << mx * cnt << " " << cnt << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
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