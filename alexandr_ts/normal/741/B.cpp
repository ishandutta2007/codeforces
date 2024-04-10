#include <bits/stdc++.h>
#define fr(i, n) for (int i = 0; i < n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e3 + 10;
const int M = 101;
const ll INF = 2e9 + 10;
const ll MOD = 1e9 + 7;
const ld EPS = 1e-13;

int w[N], b[N];

vector <int> gr[N], g[N];
int used[N];

void dfs(int v, int cur) {
    used[v] = cur;
    fr(i, g[v].size())
        if (!used[g[v][i]])
            dfs(g[v][i], cur);
}

int sw[N], sb[N];

int d[N][N];

int main() {
    //freopen("a.in", "r", stdin);
    int n, m, w1;
    cin >> n >> m >> w1;
    fr(i, n)
        cin >> w[i];
    fr(i, n)
        cin >> b[i];
    fr(i, m) {
        int x, y;
        cin >> x >> y;
        g[--x].pb(--y);
        g[y].pb(x);
    }
    int cur = 1;
    fr(i, n)
        if (!used[i]) {
            dfs(i, cur++);
            fr(j, n)
                if (used[j] == cur - 1)
                    gr[cur - 1].pb(j);
        }
    cur--;
    //cout << cur;
    frab(i, 1, 1 + cur)
        fr(j, gr[i].size())
            sw[i] += w[gr[i][j]], sb[i] += b[gr[i][j]];

    fr(i, n + 2)
        fr(j, w1 + 1)
            d[i][j] = -INF;
    d[1][0] = 0;

    //cout << sw[2] << endl;

    frab(i, 1, 1 + cur)
        fr(j, w1 + 1)
            if (d[i][j] == -INF) continue;
            else {
                d[i + 1][j] = max(d[i + 1][j], d[i][j]);
                int nw = j + sw[i];
                int na = d[i][j] + sb[i];
                if (nw <= w1 && na > d[i + 1][nw])
                    d[i + 1][nw] = na;
                fr(i1, gr[i].size()) {
                    int nw = j + w[gr[i][i1]];
                    int na = d[i][j] + b[gr[i][i1]];
                    if (nw <= w1 && na > d[i + 1][nw])
                        d[i + 1][nw] = na;
                }
            }
    int ans = 0;
    fr(i, cur + 2)
        fr(j, w1 + 1)
        ans = max(ans, d[i][j]);
    cout << ans;
    return 0;
}