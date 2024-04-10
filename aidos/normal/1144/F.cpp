#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int maxn = (int)1e6 + 10;
const int mod = (int)1e9+7;
const int inf = (1<<30) - 1;
int n, m;
vector<int> g[maxn];
int u[maxn];
int col[maxn];
void dfs(int v, int t) {
    u[v] = 1;
    col[v] = t;
    for(const int &to: g[v]) {
        if(!u[to]) {
            dfs(to, 1 - t);
        } else {
            if(col[to] == t) {
                cout << "NO\n";
                exit(0);
            }
        }
    }
}
pii e[maxn];
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        e[i] = make_pair(x, y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    cout << "YES\n";
    for(int i = 1; i <= m; i++) {
        if(col[e[i].first]) cout << 1;
        else cout << 0;
    }
    cout << "\n";
}


int main() {
    int t = 1;
    //scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        //printf("Case %d: ", i);
        solve();
    }
    return 0;
}