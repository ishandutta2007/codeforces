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

vector<int> ns[111111];
int n, m;
int d[111111];

int ton(int i, int j) {
    return i * m + j;
}

void solve(istream& cin, ostream& cout) {
    srand(31);
    cin >> n >> m;
    set<pair<int, int>> qq;
    rep(i, 0, n) {
        rep(j, 0, m) {
            int x = ton(i, j);
            if (i) {
                ns[x].push_back(ton(i - 1, j));
            }
            if (i + 1 < n) {
                ns[x].push_back(ton(i + 1, j));
            }
            if (j) {
                ns[x].push_back(ton(i, j - 1));
            }
            if (j + 1 < m) {
                ns[x].push_back(ton(i, j + 1));
            }
            d[x] = n * m;
            qq.insert({d[x], x});
        }
    }

    vector<vector<int>> ans(n, vector<int>(m, -1));
    vector<pair<int, int>> cls;
    rep(i, 0, n) {
        rep(j, 0, m) {
            cls.push_back({i, j});
        }
    }
    rep(itt, 0, int(3e6) / (n * m)) {
        random_shuffle(cls.begin(), cls.end());
        auto q = qq;
        fill(d, d + n * m, n * m);
        bool ok = true;
        for (auto& cc : cls) {
            int i = cc.first;
            int j = cc.second;
            pair<int, int> x = {-1, -1};
            for (auto &p : q) {
                if (i && ans[i - 1][j] != -1 && find(ns[ans[i - 1][j]].begin(), ns[ans[i - 1][j]].end(), p.second) != ns[ans[i - 1][j]].end()) {
                    continue;
                }
                if (j && ans[i][j - 1] != -1 && find(ns[ans[i][j - 1]].begin(), ns[ans[i][j - 1]].end(), p.second) != ns[ans[i][j - 1]].end()) {
                    continue;
                }
                if (i + 1 < n && ans[i + 1][j] != -1 && find(ns[ans[i + 1][j]].begin(), ns[ans[i + 1][j]].end(), p.second) != ns[ans[i + 1][j]].end()) {
                    continue;
                }
                if (j + 1 < m && ans[i][j + 1] != -1 && find(ns[ans[i][j + 1]].begin(), ns[ans[i][j + 1]].end(), p.second) != ns[ans[i][j + 1]].end()) {
                    continue;
                }
                x = p;
                break;
            }
            if (x.second == -1) {
                ok = false;
                break;
            }
            ans[i][j] = x.second;
            q.erase(x);
            for (int t : ns[x.second]) {
                if (q.count({d[t], t})) {
                    q.erase({d[t], t});
                    --d[t];
                    q.insert({d[t], t});
                }
            }
        }
        if (!ok) {
            continue;
        }

        cout << "YES\n";
        rep(i, 0, n) {
            rep(j, 0, m) {
                cout << ans[i][j] + 1 << " ";
            }
            cout << "\n";
        }
        return;
    }
    cout << "NO";
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
}