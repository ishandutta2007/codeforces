/// Alexandr_TS

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr(i, n) for (int i = 0; i < (int)n; i++)
#define frab(i, a, b) for (int i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef long double ld;

const ld PI = acos(-1);
const ld EPS = 1e-8;
const ll MOD = 1e9 + 7;
const int M = 1005;
const ll INF = 1e9 + 10;
const int N = 4e5 + 10;

int color[N];
vector <pair <int, int> > g[N];

vector <int> ans;
bool used[N];
int st;

void dfs(int v, int edge, int last) {
    used[v] = true;
    for (auto t: g[v]) {
        int u = t.first;
        if (!used[u])
            dfs(u, t.second, v);
    }
    if (color[v] == 1) {
        assert(last != -1);
        ans.pb(edge);
        if (color[last] == 1)
            color[last] = 0;
        else if (color[last] == 0)
            color[last] = 1;
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    int n, m;
    cin >> n >> m;
    st = -1;
    int ones = 0;
    fr(i, n) {
        cin >> color[i];
        if (color[i] == -1)
            st = i;
        if (color[i] == 1)
            ones++;
    }
    fr(i, m) {
        int v, u;
        cin >> v >> u;
        g[--v].pb(mp(--u, i));
        g[u].pb(mp(v, i));
    }

    if (st == -1 && ones % 2 == 1) {
        cout << -1;
        return 0;
    }

    if (st == -1)
        st = 0;
    dfs(st, -1, -1);
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (auto t: ans)
        cout << t + 1 << " ";
}