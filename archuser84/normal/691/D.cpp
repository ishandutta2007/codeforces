//#pragma GCC optimize ("O2")
//#pragma GCC optimize ("Ofast")
// <IN THE NAME OF GOD>
// this is mamad
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define debug "ahhh shit\n"

int n, m;
vector <int> p, leaders, ans;
vector <pii> swaps, cur_per;

struct dsu {
    vector <int> par;
    int n;
    dsu(int N): n(N) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }
    inline int get(int x) {
        return (x == par[x]? x: (par[x] = get(par[x])));
    }
    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            par[x] = y;
            return true;
        }
        return false;
    }
};

void read_input() {
    scanf("%d%d", &n, &m);
    p.resize(n);
    swaps.resize(m);
    for (int &e: p) {
        scanf("%d", &e);
        e--;
    }
    for (pii &e: swaps) {
        scanf("%d%d", &e.first, &e.second);
        e.first--;
        e.second--;
    }
    return;
}

void solve() {
    dsu d(n);
    for (pii e: swaps)
        d.unite(e.first, e.second);
    cur_per.resize(n);
    for (int i = 0; i < n; i++)
        cur_per[i] = pii{p[i], i};
    sort(cur_per.rbegin(), cur_per.rend());
    leaders.resize(n);
    for (int i = 0; i < n; i++)
        leaders[i] = d.get(i);
    set <pii> can;
    for (int i = 0; i < n; i++)
        can.insert(pii{leaders[i], i});
    ans.resize(n);
    for (int i = 0; i < n; i++) {
        auto idx = can.lower_bound(pii{leaders[cur_per[i].second], -1});
        ans[(*idx).second] = cur_per[i].first;
        can.erase(idx);
    }
    return;
}

void write_output() {
    for (int e: ans)
        printf("%d ", e + 1);
    return;
}

int main() {
    //ios::sync_with_stdio(false), cin.tie(NULL);
    read_input(), solve(), write_output();
    return 0;
}