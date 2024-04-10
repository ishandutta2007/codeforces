#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int INF = 1e9;
vector<int> G[200005];
int clr[200005], dis[200005];

void dfs(int u, int f, int prv) {
    for (int i : G[u])
        if (i != f) {
            if (clr[i] == 2) {
                dis[i] = dis[u];
                dfs(i, u, prv);
            }
            else if (clr[i] + prv == 1) {
                dis[i] = dis[u] + 1;
                dfs(i, u, clr[i]); 
            }   
            else {
                dis[i] = dis[u];
                dfs(i, u, clr[i]);
            }
        }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> clr[i], G[i].clear();
            clr[i] = (clr[i] + 2) % 3;
        }
        for (int i = 1; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            G[a].pb(b);
            G[b].pb(a);
        }
        dis[1] = 1, dfs(1, 1, clr[1]);
        int mx = max_element(dis + 1, dis + n + 1) - dis;
        for (int i = 1; i <= n; ++i)
            if (clr[i] != 2 && dis[mx] == dis[i]) {
                mx = i;
                break;
            }
        dis[mx] = 1, dfs(mx, mx, clr[mx]);
        cout << *max_element(dis + 1, dis + n + 1) / 2 + 1 << "\n";
    }
}