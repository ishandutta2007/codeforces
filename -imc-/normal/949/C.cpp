#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()

using li = long long;
using ld = long double;

const int MOD = 1e9 + 7;

int modpow(int x, int p) {
    int ans = 1;
    while (p) {
        if (p % 2)
            ans = ans * (li)x % MOD;
        p /= 2;
        x = x * (li)x % MOD;
    }
    return ans;
}

vector<vector<int>> e, re;
vector<char> used;

vector<int> order;

void dfs(int v) {
    used[v] = true;
    
    for (int u: e[v]) {
        if (!used[u])
            dfs(u);
    }
    order.push_back(v);
}

vector<int> comp;
vector<int> color;

vector<char> failComp;

void xdfs(int v, int c) {
    used[v] = true;
    color[v] = c;
    
    for (int u: re[v]) {
        if (!used[u])
            xdfs(u, c);
        else {
            if (color[u] != c) {
                assert(color[u] != -1);
                //cout << "have edge " << v << " " << u << " so fail\n";
                failComp[color[u]] = true;
            }
        }
    }
    comp.push_back(v);
}

void solve(bool __attribute__((unused)) read) {
    int n, m, h;
    cin >> n >> m >> h;
    
    vector<int> u(n);
    for (int i = 0; i < n; ++i) {
        cin >> u[i];
    }
    
    e.resize(n);
    re.resize(n);
    
    auto add_edge = [&](int x, int y) {
        //cout << "edge " << x << " " << y << endl;
        e[x].push_back(y);
        re[y].push_back(x);
    };
    
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        
        if ((u[a] + 1) % h == u[b]) {
            add_edge(a, b);
        }
        
        if ((u[b] + 1) % h == u[a]) {
            add_edge(b, a);
        }
    }
    
    // min size SCC
    
    used.assign(n, false);
    for (int i = 0; i < n; ++i)
        if (!used[i])
            dfs(i);
        
    reverse(all(order));
    
    used.assign(n, false);
    vector<int> answerComp(n);
    iota(all(answerComp), 0);
    color.assign(n, -1);
    failComp.assign(n, false);
    vector<vector<int>> comps(n);
    for (int v: order) {
        if (!used[v]) {
            comp.clear();
            //failComp = false;
            xdfs(v, v);
            comps[v] = comp;
            
            //if (failComp) continue;
            
            //cout << "comp: "; for (int x: comp) cout << x << " "; cout << "\n";
            
            
        }
    }
    
    for (int i = 0; i < n; ++i)
        if (!comps[i].empty() && !failComp[i]) {
            if (comps[i].size() < answerComp.size()) {
                answerComp = comps[i];
            }
        }
    
    cout << answerComp.size() << "\n";
    sort(all(answerComp));
    for (int x: answerComp)
        cout << x + 1 << " ";
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int nt = 1;
    //cin >> nt;
    for (int i = 0; i < nt; i++)
        solve(true);
    
    //while (true) solve(false);
    
    return 0;
}