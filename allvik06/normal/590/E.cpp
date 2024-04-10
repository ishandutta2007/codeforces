#pragma GCC optimize("O3,no-stack-protector")
#pragma GCC target("avx2")

#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cassert>
#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <random>
#include <iomanip>
#include <chrono>
#include <bitset>

using namespace std;
bool DEBUG = true;
const int MAXN = 1e7 + 10;
int cur = 0;
int to[MAXN][2];
int suf[MAXN];
int pr[MAXN];
int sym[MAXN];
int ssuf[MAXN];
int ind[MAXN];

inline int add_vertex() {
    to[cur][0] = to[cur][1] = suf[cur] = pr[cur] = sym[cur] = ssuf[cur] = ind[cur] = -1;
    return cur++;
}

inline void add_string(const string& s, int i) {
    int now = 0;
    for (char c : s) {
        int cc = c - 'a';
        if (to[now][cc] == -1) {
            to[now][cc] = add_vertex();
            pr[to[now][cc]] = now;
            sym[to[now][cc]] = cc;
        }
        now = to[now][cc];
    }
    ind[now] = i;
}

inline void calc() {
    vector <int> now, ne;
    now.push_back(0);
    while (!now.empty()) {
        for (int i : now) {
            for (int j = 0; j < 2; ++j) {
                if (i == 0) {
                    if (to[i][j] != -1) {
                        suf[to[i][j]] = 0;
                        ne.push_back(to[i][j]);
                    } else {
                        to[i][j] = 0;
                    }
                    continue;
                }
                if (to[i][j] == -1) {
                    to[i][j] = to[suf[i]][j];
                } else {
                    ne.push_back(to[i][j]);
                    suf[to[i][j]] = to[suf[i]][j];
                    if (ind[suf[to[i][j]]] != -1) ssuf[to[i][j]] = suf[to[i][j]];
                    else ssuf[to[i][j]] = ssuf[suf[to[i][j]]];
                }
            }
        }
        now.swap(ne);
        vector <int>().swap(ne);
    }
}

vector <vector <int>> g;
vector <int> used, ans;

bool dfs(int v, int lvl) {
    if (used[v] == lvl) return false;
    used[v] = lvl;
    for (int i : g[v]) {
        if (ans[i] == -1) {
            ans[i] = v;
            return true;
        }
    }
    for (int i : g[v]) {
        if (dfs(ans[i], lvl)) {
            ans[i] = v;
            return true;
        }
    }
    return false;
}

vector <vector <int>> gg;

vector <bitset<750>> flex;

void dfs(int v) {
    used[v] = -1;
    for (int i : gg[v]) {
        if (used[i] != -1) {
            dfs(i);
        }
        flex[v] |= flex[i];
        flex[v].set(i);
    }
}

void solve() {
    int n;
    cin >> n;
    add_vertex();
    vector <string> a(n);
    bool kek = false;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        add_string(a[i], i);
    }
    if (n == 100 && a[0][0] == 'b') kek = true;
    g.resize(2 * n);
    gg.resize(n);
    calc();
    for (int i = 0; i < n; ++i) {
        vector <bool> flex(n);
        int now = 0;
        for (char c : a[i]) {
            now = to[now][c - 'a'];
            int tmp = now;
            while (now > 0) {
                if (ind[now] != -1) {
                    if (flex[ind[now]]) break;
                    if (ind[now] != i) {
                        gg[i].push_back(ind[now]);
                    }
                    flex[ind[now]] = true;
                }
                now = ssuf[now];
            }
            now = tmp;
        }
    }
  //  if (kek) assert(false);
    used.resize(n);
    flex.resize(n);
    for (int i = 0; i < n; ++i) {
        if (used[i] != -1) dfs(i);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (flex[i][j]) g[i].push_back(n + j);
        }
    }
    ans.resize(2 * n, -1);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cnt += dfs(i, i);
    }
    set <int> cha;
    vector <int> p(n, -1);
    bitset <750> now;
    for (int i = 0; i < n; ++i) {
        bool ok = false;
        for (int j : g[i]) {
            if (ans[j] == i) {
                ok = true;
                p[j - n] = i;
                break;
            }
        }
        if (!ok) {
            cha.insert(i);
            now.set(i);
        }
    }
    int cccc = 0;
    while (true) {
        ++cccc;
        int num = -1;
        auto it = cha.begin();
        while (it != cha.end()) {
            int pos = 750;
            pos = (flex[*it] & now)._Find_first();
         /*   auto tmp = (flex[*it] & now);
           for (int i = 0; i < n; ++i) {
               if (tmp[i] == 1) {
                   pos = i;
                   break;
               }
           }*/
           if (pos != 750) {
               num = pos;
               break;
           }
           it = next(it);
        }
        if (num == -1) break;
        cha.erase(num);
        cha.insert(p[num]);
        now.reset(num);
        now.set(p[num]);
    }
    cout << (int)cha.size() << "\n";
    for (int i : cha) cout << i + 1 << " ";
}

signed main() {
    if (1) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    if (1) {
        int t = 1;
        // cin >> t;
        while (t--) {
            solve();
        }
    }
}

/*

 */