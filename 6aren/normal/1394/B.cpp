#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

const int N = 200005;

vector<ii> g[N];
int n, m, k;
set<ii> out;
set<pair<ii, ii>> out2;
vector<ii> vec[N];

int a[10];
int ans = 0;

bool check() {
    for (int i = 1; i <= k; i++) {
        if (out.count({i, a[i]})) return 0;
    }

    for (int i = 1; i <= k; i++) {
        for (int j = i + 1; j <= k; j++) {
            if (out2.count({{i, a[i]}, {j, a[j]}})) return false;
        }
    }

    return true;

}

void naive(int id) {
    for (int i = 1; i <= id; i++) {
        a[id] = i;
        if (id == k) {
            if (check()) ans++;
        } else naive(id + 1);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb({w, v});
    }
    for (int i = 1; i <= n; i++) {
        sort(all(g[i]));
        for (int j = 0; j < g[i].size(); j++) {
            vec[g[i][j].y].pb({g[i].size(), j + 1});
        }
    }

    for (int i = 1; i <= n; i++) {
        sort(all(vec[i]));
        for (int j = 1; j < vec[i].size(); j++) {
            if (vec[i][j] == vec[i][j - 1]) out.insert(vec[i][j]);
        }
        set<ii> tmp;
        for (auto e : vec[i]) tmp.insert(e);
        vector<ii> tm;
        for (auto e : tmp) tm.pb(e);
        for (int j = 0; j < tm.size(); j++) {
            for (int jj = j + 1; jj < tm.size(); jj++) {
                if (tm[j] > tm[jj]) swap(tm[j], tm[jj]);
                out2.insert({tm[j], tm[jj]});
            }
        }
    }

    naive(1);

    cout << ans;

    return 0;
}