#pragma optimize("", on)
#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int) 998244353;
const int inf = (1<<30) - 1;
int n, m;
int d[2][maxn];
int dis[maxn];
vector<int> g[maxn];
void dfs(int v, int pa) {
    dis[v] = dis[pa] + 1;
    for(int to: g[v]) {
        if(to != pa) dfs(to, v);
    }
}
int st, en;
vector<int> path;
int u[maxn];
bool dfs2(int v, int pa) {
    if(v == en) {
        path.emplace_back(v);
        u[v] = 1;
        return true;
    }
    for(int to: g[v]) {
        if(to != pa) {
            if(dfs2(to, v)) {
                u[v] = 1;
                path.emplace_back(v);
                return true;
            }
        }
    }
    return false;
}
void solve() {
    cin >> n;
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    dis[0] = -1;
    dfs(1, 0);
    en = max_element(dis+1, dis + n + 1) - dis;
    dfs(en, 0);
    st = max_element(dis + 1, dis + n + 1) - dis;
    for(int i = 1; i <= n; i++) {
        d[0][i] = dis[i];
    }
    dfs(st, 0);
    for(int i = 1; i <= n; i++) {
        d[1][i] = dis[i];
    }
    dfs2(st, 0);
    ll ans = 0;
    vector<pair<int, pair<int, int> > > A;
    for(int i = 1; i <= n; i++) {
        if(!u[i]) {
            if(d[0][i] > d[1][i]) {
                ans += d[0][i];
                A.emplace_back(make_pair(d[0][i], make_pair(en, i)));
            } else {
                ans += d[1][i];
                A.emplace_back(make_pair(d[1][i], make_pair(st, i)));
            }
        }
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    for(int i = 0; i + 1< path.size(); i++) {
        ans += path.size() - i - 1;
        A.emplace_back(make_pair(path.size() - i - 1, make_pair(path.back(), path[i])));
    }
    cout << ans << "\n";
    for(auto x: A) {
        cout << x.second.first << " "<<x.second.second << " " << x.second.second << "\n";
    }

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