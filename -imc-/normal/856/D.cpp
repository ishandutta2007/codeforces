#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;

const int maxN = 200500, logMaxN = 18;

vector<int> e[maxN];

int timeCounter;
int inTime[maxN], outTime[maxN];
int parent[logMaxN][maxN];
int depth[maxN];

bool isParentChild(int u, int v) {
    return inTime[v] >= inTime[u] && outTime[v] <= outTime[u];
}

void dfs(int v, int p = -1) {
    inTime[v] = timeCounter++;
    parent[0][v] = v;
    
    for (int u: e[v]) {
        if (u == p) continue;
        
        depth[u] = depth[v] + 1;
        dfs(u, v);
        parent[0][u] = v;
    }
    outTime[v] = timeCounter++;
}

int lca(int u, int v) {
    if (isParentChild(u, v)) return u;
    if (isParentChild(v, u)) return v;
    
    for (int k = logMaxN - 1; k >= 0; k--)
        if (!isParentChild(parent[k][u], v))
            u = parent[k][u];
        
    u = parent[0][u];
    assert(isParentChild(u, v));
    return u;
}

vector<vector<int>> r_end, r_begin;

struct trail {
    int id, h, dp_add;
    
    bool operator<(const trail& t) const { return make_pair(-h, id) < make_pair(-t.h, t.id); }
};

map<int, int> id_relax;
int cur_h;

struct trails {
    int dp_add = 0;
    set<trail> t;
    
    void merge(trails& other) {
        if (t.size() < other.t.size()) {
            other.merge(*this);
            swap(dp_add, other.dp_add);
            t.swap(other.t);
            return;
        }
        
        for (auto it: other.t) {
            it.dp_add += other.dp_add - dp_add;
            t.insert(it);
        }
    }
    
    void filter() {
        while (!t.empty() && t.begin()->h == cur_h) {
            id_relax[t.begin()->id] += t.begin()->dp_add + dp_add;
            //printf("id %d merged, add %d\n", it.id, it.dp_add + dp_add);
            t.erase(t.begin());
        }
    }
};

vector<int> dp;
vector<vector<tuple<int, int, int>>> start;

void xdfs(int v, trails& to) {
    //printf("xdfs %d\n", v + 1);
    vector<trails> children(e[v].size());
    vector<int> cv(children.size());
    
    int cid = 0;
    int dp_sum = 0;
    
    for (int u: e[v]) {
        xdfs(u, children[cid]);
        cv[cid] = u;
        dp_sum += dp[u];
        cid++;
    }
    
    cur_h = depth[v];
    id_relax.clear();
    
    to = trails();
    for (int i = 0; i < children.size(); i++) {
        children[i].dp_add += dp_sum - dp[cv[i]];
        children[i].filter();
        to.merge(children[i]);
    }
    
    for (auto id_h_cost: start[v]) {
        trail tr = {};
        tr.id = get<0>(id_h_cost);
        tr.h = get<1>(id_h_cost);
        tr.dp_add = dp_sum + get<2>(id_h_cost);
        trails trr;
        trr.t.insert(tr);
        trr.filter();
        to.merge(trr);
        //printf("at %d start id %d, depth %d, cost %d + add %d\n", v + 1, tr.id, tr.h, get<2>(id_h_cost), dp_sum);
    }
    
    dp[v] = max(dp[v], dp_sum);
    
    for (auto it: id_relax) {
        it.second -= dp_sum;
        //printf("remax with %d\n", it.second);
        dp[v] = max(dp[v], it.second);
    }
    
    //printf("leave vertex %d, dp %d\n", v + 1, dp[v]);
}

void solve(bool) {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n - 1; i++) {
        int p;
        cin >> p;
        p--;
        e[p].push_back(i + 1);
    }
    
    dfs(0);
    for (int log = 1; log < logMaxN; log++)
        for (int i = 0; i < n; i++)
            parent[log][i] = parent[log - 1][parent[log - 1][i]];
        
    start.resize(n);
    dp.resize(n);
    
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        
        int l = lca(u, v);
        
        //if (!isParentChild(u, v) && !isParentChild(v, u)) {
            start[u].emplace_back(i, depth[l], 0);
            start[v].emplace_back(i, depth[l], c);
        /*}
        else if (isParentChild(u, v)) {
            start[v].emplace_back(i, depth[l], c);
        }
        else {
            start[u].emplace_back(i, depth[l], c);
        }*/
    }
    
    trails to;
    xdfs(0, to);
    cout << dp[0] << "\n";
    cout.flush();
    assert(to.t.empty());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    return 0;
}