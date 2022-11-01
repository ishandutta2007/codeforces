#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define mp make_pair
#define s second
#define f first

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;
const ll INF = 2e12 + 1;
const int MOD = 1e9 + 7;
const ld EPS = 1e-9;

vector <int> g[N];
int color[N];

void dfs(int v, int pr) {
    int cur = 0;
    fr(i, g[v].size())
        if (!color[g[v][i]]) {
            cur++;
            while (cur == color[pr] || cur == color[v])
                cur++;
            color[g[v][i]] = cur;
            dfs(g[v][i], v);
        }
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    fr(i, n - 1) {
        int v, u;
        cin >> v >> u;
        g[--v].pb(--u);
        g[u].pb(v);
    }
    color[0] = 1;
    dfs(0, 0);
    cout << *max_element(color, color + n) << endl;
    fr(i, n)
        cout << color[i] << " ";
}