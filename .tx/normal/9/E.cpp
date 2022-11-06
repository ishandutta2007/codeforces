#include <bits/stdc++.h>
#ifdef JLOCAL
#include "stress.h"
#endif
using namespace std;

#define rep(i, z, n) for (int i = (z); i < int(n); ++i)
#define repr(i, n, z) for (int i = int(n) - 1; i >= (z); --i)
#define repa(i, a) for (auto& i : a)
#define shl(n) (1 << (n))
#define hbit(n, i) (((n) >> (i)) & 1)

#define STRESS 0
using lint = long long;

vector<int> g[55];
int deg[55];

int used[55];
int utm = 1;
void dfs(int v) {
    used[v] = utm;
    for (int i : g[v]) {
        if (used[i] != utm) {
            dfs(i);
        }
    }
}

bool conn(int u, int v) {
    utm++;
    dfs(u);
    return used[v] == utm;
}

void solve(istream& cin, ostream& cout) {
    int n, m;
    cin >> n >> m;

    if (n == 1) {
        if (m == 0) {
            cout << "YES\n1\n1 1";
        } else if (m == 1) {
            cout << "YES\n0";
        } else {
            cout << "NO";
        }
        return;
    }

    rep(i, 0, m) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
        deg[x]++;
        deg[y]++;
        if (deg[x] > 2 || deg[y] > 2) {
            cout << "NO";
            return;
        }
    }

    vector<pair<int, int>> ans;

    while (true) {
        int p = -1;
        rep(i, 0, n) {
            if (deg[i] < 2) {
                p = i;
                break;
            }
        }
        if (p == -1) {
            break;
        }
        int u = -1;
        rep(i, 0, n) {
            if (deg[i] < 2 && !conn(p, i)) {
                u = i;
                break;
            }
        }

        if (u == -1) {
            rep(i, 0, n) {
                if (i != p && deg[i] < 2) {
                    u = i;
                }
            }
        }

        deg[p]++;
        deg[u]++;
        g[p].push_back(u);
        g[u].push_back(p);
        ans.push_back({min(p, u), max(p, u)});
    }

    utm++;
    dfs(0);
    rep(i, 0, n) {
        if (used[i] != utm) {
            cout << "NO";
            return;
        }
    }

    cout << "YES\n";
    cout << ans.size() << "\n";
    repa(i, ans) {
        cout << i.first + 1 << " " << i.second + 1 << "\n";
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
}//tfmscb