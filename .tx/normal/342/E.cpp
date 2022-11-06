#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

struct Dsu {
    int* a;
    int* r;
    int* c;
    
    Dsu(int n) {
        a = new int[n];
        r = new int[n];
        c = new int[n];
        
        for (int i = 0; i < n; i++) {
            a[i] = i;
            c[i] = i;
            r[i] = 1;
        }
    }
    
    int get(int x) {
        return a[x] == x ? x : a[x] = get(a[x]);
    }
    
    int getc(int x) {
        return c[get(x)];
    }
    
    void unite(int x, int y, int uc) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return;
        }
        if (r[x] < r[y]) {
            a[x] = y;
            c[y] = uc;
        } else {
            a[y] = x;
            c[x] = uc;
            if (r[x] == r[y]) {
                r[x]++;
            }
        }
    }
};

Dsu dsu(111111);
vector<int> g[111111];

const int BLEN = 310;

vector<pair<int, int> > qlca[111111];
pair<int, int> qs[111111];
int alca[111111 * BLEN];
int h[111111];

int d[111111];

bool used[111111];

void dfs(int v, int p, int ch) {
    used[v] = true;
    h[v] = ch;
    for (auto& i : qlca[v]) {
        if (used[i.first]) {
            int lca = dsu.getc(i.first);
            alca[i.second] = lca;
        }
    }    
    
    for (int i : g[v]) {
        if (i != p) {
            dfs(i, v, ch + 1);
        }
    }
    
    if (p != -1) {
        dsu.unite(v, p, p);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n, m);
    for (int i = 1; i < n; i++) {
        scid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    
    vector<int> cred;
    cred.push_back(0);
    int lid = 0;
    
    for (int i = 0; i < m; i++) {
        scid(t, v);
        --v;
        if (t == 1) {
            cred.push_back(v);
        } else {
            for (int i : cred) {
                qlca[v].push_back({i, lid});
                qlca[i].push_back({v, lid});
                ++lid;
            }
        }
        
        if (i % BLEN == 0) {
            cred.clear();
        }
        
        qs[i] = {t, v};
    }
    
    dfs(0, -1, 0);
    
    vector<int> ared;
    cred.clear();
    cred.push_back(0);
    
    fill(d, d + n, (int) 1e9);
    lid = 0;
    
    for (int i = 0; i < m; i++) {
        int t = qs[i].first;
        int v = qs[i].second;
//        cerr << t << " " << v << endl;
        if (t == 1) {
            cred.push_back(v);
        } else {
            int ans = d[v];
            for (int u : cred) {
                int lca = alca[lid++];
                int cd = h[v] - h[lca] + h[u] - h[lca];
                ans = min(ans, cd);
            }
            
            cout << ans << "\n";
        }
        
        if (i % BLEN == 0) {
            for (int x : cred) {
                ared.push_back(x);
            }
            cred.clear();
            queue<int> q;
            fill(d, d + n, (int) 1e9);
            for (int i : ared) {
                d[i] = 0;
                q.push(i);
            }
            
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int i : g[v]) {
                    if (d[i] > d[v] + 1) {
                        d[i] = d[v] + 1;
                        q.push(i);
                    }
                }
            }
        }
    }
    
    return 0;
}