#include <bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pii pair<int, int>
#define puu pair<unsigned, unsigned>
#define ll long long
#define mp make_pair
#define ui unsigned
#define ull unsigned long long
#define ld double
#define pld pair<ld, ld>
#define pll pair<ll, ll>

const int INF = 1e9 + 1;
const ll INFLL = 1e18;

vector<vector<int>> a;
map<int, set<pii>> gist;
vector<set<int>> ind;
vector<vector<char>> ans;

void dfs(int v, int type = 0) {
    if (type == 0) {
        while (gist[v].size()) {
            pii to = *gist[v].begin();
            gist[v].erase(gist[v].begin());
            //cout << 'R' << " " << to.fi << " " << to.se << endl;
            ans[to.fi][to.se] = 'R';
            ind[to.fi].erase(to.se);
            dfs(to.fi, 1);
        }
    } else {
        while (ind[v].size()) {
            int j = *ind[v].begin();
            ind[v].erase(ind[v].begin());
            ans[v][j] = 'L';
            //cout << 'L' << " " << v << " " << j << endl;
            gist[a[v][j]].erase(mp(v, j));
            dfs(a[v][j], 0);
        }
    }
}

int main() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    #endif
    int m;
    cin >> m;
    a.resize(m);
    ind.resize(m);
    ans.resize(m);
    for (int i = 0; i < m; i++) {
        int n;
        cin >> n;
        a[i].resize(n);
        ans[i].resize(n);
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            a[i][j] = x;
            gist[x].insert(mp(i, j));
            ind[i].insert(j);
        }
    }
    for (auto &c : gist) {
        if ((int)c.se.size() % 2 == 1) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    for (auto &c : gist) dfs(c.fi);
    for (int i = 0; i < m; i++) {
        for (auto &c : ans[i]) cout << c;
        cout << "\n";
    }
    return 0;
}