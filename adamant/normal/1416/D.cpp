#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 42;

set<pair<int, int>> vers[maxn];
set<int> vers2[maxn];
int par[maxn], p[maxn];
vector<pair<int, int>> st;

void add_edge(int a, int b) {
    a = par[a];
    b = par[b];
    if(vers2[a].size() < vers2[b].size()) {
        swap(a, b);
    }
    if(a != b) {
        for(auto it: vers2[b]) {
            vers2[a].insert(it);
            vers[a].emplace(-p[it], it);
            par[it] = a;
        }
        st.emplace_back(a, b);
    } else {
        st.emplace_back(-1, -1);
    }
}

void revert() {
    int a, b;
    tie(a, b) = st.back();
    if(a != -1) {
        for(auto it: vers2[b]) {
            vers2[a].erase(it);
            vers[a].erase({-p[it], it});
            par[it] = b;
        }
    }
    st.pop_back();
}

int get_max(int v) {
    int pr = par[v], u, x;
    while(!vers[pr].empty()) {
        auto it = begin(vers[pr]);
        tie(x, u) = *it;
        vers[pr].erase(it);
        if(p[u] == -x) {
            p[u] = 0;
            return -x;
        }
    }
    return 0;
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        vers[i].emplace(-p[i], i);
        vers2[i].insert(i);
        par[i] = i;
    }
    int u[m], v[m], mark[m];
    memset(mark, 0, sizeof(mark));
    for(int i = 0; i < m; i++) {
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;
    }
    int type[q], num[q];
    for(int i = 0; i < q; i++) {
        cin >> type[i] >> num[i];
        num[i]--;
        if(type[i] == 2) {
            mark[num[i]] = 1;
        }
    }
    for(int i = 0; i < m; i++) {
        if(!mark[i]) {
            add_edge(u[i], v[i]);
        }
    }
    for(int i = q - 1; i >= 0; i--) {
        if(type[i] == 2) {
            add_edge(u[num[i]], v[num[i]]);
        }
    }
    for(int i = 0; i < q; i++) {
        if(type[i] == 2) {
            revert();
        } else {
            cout << get_max(num[i]) << "\n";
        }
    }
}

signed main() {
    //cout << ((sizeof(to) + sizeof(inv) + sizeof(szs)) >> 20) << endl;
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    t = 1;//cin >> t;
    while(t--) {
        solve();
    }
}