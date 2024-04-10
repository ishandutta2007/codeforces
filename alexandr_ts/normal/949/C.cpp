#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1);
const int M = 1e3 + 10;
const int N = 2e5 + 10;

int w[N];
vector <int> g[N], revg[N];
vector <int> fordfs;
bool used[N];

void dfs(int v) {
    used[v] = true;
    for (auto u: g[v])
        if (!used[u])
            dfs(u);
    fordfs.pb(v);
}

int comp[N];

void dfs2(int v, int com) {
    comp[v] = com;
    for (auto u: revg[v])
        if (comp[u] == -1)
            dfs2(u, com);
}

int sz[N];
bool ein[N];

int main() {
    //freopen("a.in", "r", stdin);
    int n, m, h;
    scanf("%d %d %d", &n, &m, &h);
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);
    for (int i = 0; i < m; i++) {
        int v, u;
        scanf("%d %d", &v, &u);
        v--, u--;
        if ((w[v] + 1) % h == w[u]) {
            g[v].pb(u);
            revg[u].pb(v);
        }
        if ((w[u] + 1) % h == w[v]) {
            g[u].pb(v);
            revg[v].pb(u);
        }
    }

//    for (int i = 0; i < n; i++)
//        for (auto u: revg[i])
//            cout << i << " " << u << endl;

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfs(i);
    //for (auto t: fordfs) cout << t << " ";cout << endl;

    fill(comp, comp + n, -1);
    int cur = 0;
    reverse(fordfs.begin(), fordfs.end());
    for (auto v: fordfs)
        if (comp[v] == -1)
            dfs2(v, cur++);

    //for (int i = 0; i < n; i++) cout << comp[i] << " ";cout << endl;

    for (int i = 0; i < n; i++)
        sz[comp[i]]++;
    int anscomp = -1, compsz = INF;
    for (int i = 0; i < n; i++)
        for (auto u: g[i])
            if (comp[i] != comp[u])
                ein[comp[i]] = true;
    for (int i = 0; i < cur; i++)
        if (compsz > sz[i] && !ein[i])
            anscomp = i, compsz = sz[i];
    cout << sz[anscomp] << "\n";
    for (int i = 0; i < n; i++)
        if (anscomp == comp[i])
            cout << i + 1 << " ";

}