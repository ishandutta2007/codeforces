#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll int, ll int>
#define ff first
#define ss second
#define pb push_back
#pragma GCC optimize("O2")
using namespace std;
// debug template
#ifdef POTATO
#include "debug.h"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = ["; _print(__VA_ARGS__)
#else
#define debug(...)
#endif
// convenient functions
inline void yes() { cout << "YES" << endl; return; }
inline void no() { cout << "NO" << endl; return; }
template <class T>
inline void out(T temp) { cout << temp << endl; return; }
// global
const int mxN = 2e5 + 1;
const ll int MOD = 998244353;
vector<int> adj[mxN];
vector<int> pfacts[mxN];
vector<int> primes;
vector<int> virnode[mxN];
vector<int> viradj[mxN];
int lift[mxN][20];
int depth[mxN];
int dfsorder[mxN];
int dfsend[mxN];
int n;
ll int ans = 0;
void init() {
    // initialize
    for (int i = 2; i < mxN; i++) {
        if (!pfacts[i].empty()) continue;
        primes.pb(i);
        for (int j = i; j < mxN; j += i) {
            pfacts[j].pb(i);
        }
    }
}
void Input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for (int &fact : pfacts[x]) {
            virnode[fact].pb(i);
        }
    }
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
}
int dfsordercnt = 0;
void DFSInit(int u = 1, int par = 0, int dep = 1) {
    depth[u] = dep;
    lift[u][0] = par;
    dfsorder[u] = ++dfsordercnt;
    for (int &v : adj[u]) {
        if (v != par) {
            DFSInit(v, u, dep + 1);
        }
    }
    dfsend[u] = dfsordercnt;
    return;
}
void LCAInit() {
    for (int dep = 1; dep < 20; dep++) {
        for (int u = 1; u <= n; u++) {
            lift[u][dep] = lift[lift[u][dep - 1]][dep - 1];
        }
    }
    return;
}
int LCAQuery(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    int diff = depth[v] - depth[u];
    for (int i = 19; i >= 0; i--) {
        if (diff & (1 << i)) v = lift[v][i];
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; i--) {
        if (lift[u][i] != lift[v][i]) {
            u = lift[u][i];
            v = lift[v][i];
        }
    }
    return lift[u][0];
}
vector<int> virallnodes;
bool isexist[mxN];
int subtsum[mxN];
int virtreeroot;
void VirtualReset() {
    for (int &u : virallnodes) {
        viradj[u].clear();
        subtsum[u] = 0;
    }
    virallnodes.clear();
}
void VirtualAddEdge(int &u, int &v) {
    viradj[u].pb(v);
    viradj[v].pb(u);
}
void BuildVirtualTree(int tar) {
    // find all vertices
    virallnodes.pb(virnode[tar][0]);
    for (int i = 1; i < int(virnode[tar].size()); i++) {
        virallnodes.pb(LCAQuery(virnode[tar][i - 1], virnode[tar][i]));
        virallnodes.pb(virnode[tar][i]);
    }
    sort(virallnodes.begin(), virallnodes.end(), [](int &lhs, int &rhs){ return dfsorder[lhs] < dfsorder[rhs]; });
    vector<int>::iterator it = unique(virallnodes.begin(), virallnodes.end());
    virallnodes.resize(it - virallnodes.begin());
    // assigning 0/1
    for (int &u : virallnodes) isexist[u] = false;
    for (int &u : virnode[tar]) isexist[u] = true;
    // find all edges
    virtreeroot = virallnodes.front();
    stack<int> s;
    s.push(virtreeroot);
    for (int i = 1; i < int(virallnodes.size()); i++) {
        while (!s.empty() && (dfsend[s.top()] < dfsorder[virallnodes[i]])) {
            int prev = s.top();
            s.pop();
            VirtualAddEdge(prev, s.top());
        }
        s.push(virallnodes[i]);
    }
    while (s.size() >= 2) {
        int prev = s.top();
        s.pop();
        VirtualAddEdge(prev, s.top());
    }
    return;
}
void VirtualDFSInit(int u = virtreeroot, int par = 0) {
    subtsum[u] = isexist[u];
    for (int &v : viradj[u]) {
        if (v != par) {
            VirtualDFSInit(v, u);
            subtsum[u] += subtsum[v];
        }
    }
    return;
}
void VirtualDFSFind(int u = virtreeroot, int par = 0) {
    for (int &v : viradj[u]) {
        if (v != par) {
            ll int cur = depth[v] - depth[u];
            cur = (cur * subtsum[v]) % MOD;
            cur = (cur * (subtsum[virtreeroot] - subtsum[v])) % MOD;
            cur = (cur * (subtsum[virtreeroot] - 2)) % MOD;
            ans = (ans + cur) % MOD;
            VirtualDFSFind(v, u);
        }
    }
    return;
}
void solve(int case_no) {
    // solve
    Input();
    DFSInit();
    LCAInit();
    for (int &prime : primes) {
        if (virnode[prime].size() <= 1) continue;
        sort(virnode[prime].begin(), virnode[prime].end(), [](int &lhs, int &rhs){ return dfsorder[lhs] < dfsorder[rhs]; });
        BuildVirtualTree(prime);
        VirtualDFSInit();
        VirtualDFSFind();
        VirtualReset();
    }
    if (ans % 2 == 1) ans += MOD;
    ans /= 2;
    out(ans);
}
signed main() {
#ifdef POTATO
    freopen("../input.txt", "r", stdin);
//    freopen("../output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(NULL));
    init();
    int t = 1;
//    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}
/*

*/