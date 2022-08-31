#include <cmath>
#include <functional>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <chrono>
#include <cstring>



using namespace std;

typedef long long ll;

mt19937 rnd(228);

const int N = 200;

string s[N];
int vert_b[N][N], vert_w[N][N], hor_b[N][N], hor_w[N][N];
int cell[N][N];

int sz = 0;

struct edge {
    int i, j, ti, tj, cost;
};

struct basic {
    int i, val, cost;
};

vector <edge> e;
vector <basic> f;

struct huy {
    int v, to, cap;
};

const int M = 1e5;
const int inf = 2e9;

vector <huy> ed;
vector <int> g[M];

void add_edge(int v, int to, int cap) {
    g[v].push_back(ed.size());
    ed.push_back({v, to, cap});
    g[to].push_back(ed.size());
    ed.push_back({to, v, 0});
}

bool u[M];

int dfs(int v, int t, int fl = inf) {
    if (u[v]) return 0;
    u[v] = true;
    if (v == t) {
        return fl;
    } else {
        for (int ind : g[v]) {
            int to = ed[ind].to;
            if (ed[ind].cap > 0) {
                int go = dfs(to, t, min(ed[ind].cap, fl));
                if (go) {
                    ed[ind].cap -= go;
                    ed[ind ^ 1].cap += go;
                    return go;
                }
            }
        }
    }
    return 0;
}

int main() {
#ifdef iq
    freopen("a.in", "r", stdin);
#endif // ONPC
    int n, m;
    int a = 0, b = 1, c = 1;
    cin >> n >> m;
    vector <string> s(n);
    //cin >> n >> m >> a >> b >> c;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (s[i][j] == '#') {
            cell[i][j] = sz++;
          }
        }
    }
    int S = sz++;
    int t = sz++;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '#') {
          if (!i || s[i - 1][j] != '#') {
            add_edge(cell[i][j], t, 1);
          } else {
            add_edge(cell[i][j], cell[i - 1][j], 1);
          }
          if (!j || s[i][j - 1] != '#') {
            add_edge(S, cell[i][j], 1);
          } else {
            add_edge(cell[i][j - 1], cell[i][j], 1);
          }
        }
      }
    }
    /*
    vector <int> x(sz);
    auto cost = [&] () {
        ll sum = 0;
        for (auto c : e) {
            if (x[c.i] == c.ti && x[c.j] == c.tj) {
                sum += c.cost;
            }
        }
        for (auto c : f) {
            if (x[c.i] == c.val) {
                sum += c.cost;
            }
        }
        return sum;
    };
    cout << cost() << endl;
    */
    ll ans = 0;
    while (int x = dfs(S, t)) {
        for (int i = 0; i < sz; i++) u[i] = 0;
        ans += x;
    }
    cout << ans << endl;
}