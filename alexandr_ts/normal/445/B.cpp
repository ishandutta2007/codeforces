#include <bits/stdc++.h>
#define fr(i, n) for (ll i = 0; i < n; i++)
#define frab(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair <long long, long long> pr;
typedef long long ll;
typedef long double ld;

const ll MOD = 1e6 + 3;
const ll INF = 2e9;
const ll N = 1e6 + 2;
const ll MAX = 2e5 + 2;
const ld EPS = 1e-8;

vector <int> g[N];
bool used[N];

void dfs(int v) {
    used[v] = true;
    fr(i, g[v].size())
        if (!used[g[v][i]])
            dfs(g[v][i]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    fr(i, m) {
        int v, u;
        cin >> v >> u;
        g[--v].pb(--u);
        g[u].pb(v);
    }
    int cnt = 0;
    fr(i, n)
        if (!used[i])
            dfs(i), cnt++;
    cout << (1ll << ((ll)(n - cnt)));
}