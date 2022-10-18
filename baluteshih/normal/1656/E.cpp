#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int C = 100000;
vector<int> G[100005];
int w[100005];

void dfs(int u, int f, int p) {
    int deg = SZ(G[u]) - 1;
    if (p == 0)
        w[u] = 1 + deg;
    else
        w[u] = -1 - deg;
    for (int i : G[u])
        if (i != f)
            dfs(i, u, p ^ 1);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            G[i].clear();
        for (int i = 1; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            G[a].pb(b);
            G[b].pb(a);
        }
        dfs(1, 1, 0);
        for (int i = 1; i <= n; ++i)
            cout << w[i] << " \n"[i == n];
    }
}