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

vector<int> G[300005], H[300005];
int pa[300005], in[300005], out[300005], dft;
pii edge[300005];

void build_tree(int u) {
    in[u] = ++dft;
    for (int i : G[u])
        if (!in[i])
            pa[i] = u, build_tree(i);
    out[u] = dft;
}

bool ancestor(int u, int v) {
    return in[u] <= in[v] && out[u] >= out[v];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].pb(b);
        G[b].pb(a);
    }
    build_tree(1), pa[1] = 1;
    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        cin >> edge[i].X >> edge[i].Y;
        H[edge[i].X].pb(i);
        H[edge[i].Y].pb(i);
    }
    for (int i = 1; i <= n; ++i)    
        if (SZ(H[i]) & 1)
            ++cnt;
    if (cnt > 0) {
        cout << "NO\n";
        cout << cnt / 2 << "\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 1; i <= q; ++i) {
        vector<int> L, R;
        int a = edge[i].X, b = edge[i].Y;
        while (!ancestor(a, b))
            L.pb(a), a = pa[a];
        L.pb(a);
        while (!ancestor(b, a))
            R.pb(b), b = pa[b];
        reverse(ALL(R));
        cout << SZ(L) + SZ(R) << "\n";
        for (int j : L)
            cout << j << " ";
        for (int j : R)
            cout << j << " ";
        cout << "\n";
    }
}