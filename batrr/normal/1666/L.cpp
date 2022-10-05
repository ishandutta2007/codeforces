#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
int n, m;
int s;
const int maxN = 2e5 + 10;
int par[maxN];
vector<int> g[maxN];
bool nused[maxN];
vector<int> cur;
int npar[maxN];
bool used[maxN];
void dfs(int v) {
    nused[v] = true;
    cur.emplace_back(v);
    if (used[v]) {
        vector<int> t1;
        int x = v;
        while (x != -1) {
            t1.emplace_back(x);
            x = par[x];
        }
        t1.emplace_back(s);
        reverse(t1.begin(), t1.end());
        x = v;
        vector<int> t2;
        while (x != -1) {
            t2.emplace_back(x);
            x = npar[x];
        }
        t2.emplace_back(s);
        reverse(t2.begin(), t2.end());
        cout << "Possible\n";
        cout << t1.size() << '\n';
        for (int c : t1) cout << c << " ";
        cout << '\n';
        cout << t2.size() << '\n';
        for (int c : t2) cout << c << " ";
        cout << '\n';
        exit(0);
    }
    for (int to : g[v]) {
        if (!nused[to]) {
            npar[to] = v;
            dfs(to);
        }
    }
}
void solve()
{
    cin >> n >> m >> s;
    memset(par, -1, sizeof par);
    memset(npar, -1, sizeof npar);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (v == s) {
            continue;
        }
        g[u].emplace_back(v);
    }
    for (int c : g[s]) {
        dfs(c);
        for (int x : cur) {
            used[x] = true;
            par[x] = npar[x];
            npar[x] = -1;
            nused[x] = false;
        }
        cur.clear();
    }
    cout << "Impossible\n";

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int t = 1;
    // scanf ("%d", &t);
    while (t--)
        solve();
}