#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;

vector<pair<int, int> > g[333333];
int d[333333];
int deg[333333];
bool used[333333];
vector<int> ans;

int dfs(int v) {
    used[v] = true;
    for (auto p : g[v]) {
        int i = p.first;
        int x = p.second;
        if (!used[i]) {
            dfs(i);
            if (d[i] != -1 && d[i] != deg[i] % 2) {
                deg[i]++;
                deg[v]++;
                ans.push_back(x);
            }
        }
    }
}

void solve(istream& cin, ostream& cout) {
    int n, m;
    cin >> n >> m;
    int st = 0;
    rep(i, 0, n) {
        cin >> d[i];
        if (d[i] == -1) {
            st = i;
        }
    }
    rep(i, 0, m) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back({y, i});
        g[y].push_back({x, i});
    }

    dfs(st);
    if (d[st] != -1 && d[st] != deg[st] % 2) {
        cout << -1;
        return;
    }
    cout << ans.size() << "\n";
    for (int i : ans) {
        cout << i + 1 << "\n";
    }
}

int main() {
#if !defined(JLOCAL) || !STRESS
#ifdef JLOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve(cin, cout);
#else
    srand();
    for (int ti = 0; ti < 100; ti++) {
        stress::gen();
        stress::stupid();
        ifstream in("input.txt");
        ofstream out("output.txt");
        solve(in, out);
        out.flush();
        stress::check();
    }
    cout << "ok" << endl;
#endif
    return 0;
}//ovlyea