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

string nm[111111];
vector<int> g[111111];
bool is_root[111111];

int tin[111111];
int tout[111111];

vector<int> lvl[111111];
int h[111111];

struct query {
    int l, r, id;
    
    bool operator<(const query& q) const {
        return r < q.r;
    }
};

vector<query> qs[111111];

int timer = 0;
void dfs(int v, int p, int d) {
    tin[v] = ++timer;
    lvl[d].push_back(v);
    h[v] = d;
    
    for (int i : g[v]) {
        if (i != p) {
            dfs(i, v, d + 1);
        }
    }
    
    tout[v] = ++timer;
}

int ans[111111];

struct SegmentTree {
    int* a;
    int n;
    
    SegmentTree() {}
    
    SegmentTree(int n) : n(n) {
        a = new int[4 * n];
        memset(a, 0, sizeof(int) * 4 * n);
    }
    
    void set(int i, int l, int r, int qi, int qx) {
        if (l + 1 == r) {
            a[i] = qx;
            return;
        }
        int m = (l + r) >> 1;
        if (qi < m) {
            set(i * 2 + 1, l, m, qi, qx);
        } else {
            set(i * 2 + 2, m, r, qi, qx);
        }
        a[i] = a[i * 2 + 1] + a[i * 2 + 2];
    }
    
    void set(int i, int x) {
        set(0, 0, n, i, x);
    }
    
    int get(int i, int l, int r, int ql, int qr) {
        if (r <= ql || qr <= l) {
            return 0;
        }
        if (ql <= l && r <= qr) {
            return a[i];
        }
        int m = (l + r) >> 1;
        return get(i * 2 + 1, l, m, ql, qr) + get(i * 2 + 2, m, r, ql, qr);
    }
    
    int get(int l, int r) {
        return get(0, 0, n, l, r);
    }
};

int last[111111];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        scids(s);
        scid(x);
        --x;
        
        nm[i] = s;
        if (x != -1) {
            g[x].push_back(i);
            g[i].push_back(x);
        } else {
            is_root[i] = true;
        }
    }
     
    for (int i = 0; i < n; i++) {
        if (is_root[i]) {
            dfs(i, -1, 0);
        }
    }
    
//    for (int i = 0; i < n; i++) {
//        cout << i << ": ";
//        for (int j : lvl[i]) {
//            cout << j << " ";
//        }
//        cout << "\n";
//    }
    
    scid(m);
    for (int i = 0; i < m; i++) {
        scid(x, y);
        --x;
        y += h[x];
        if (y >= n || lvl[y].empty()) {
            continue;
        }        
        auto cmp_tin = [&](const int& a, const int& b) {
            return tin[a] < tin[b];
        };
        auto cmp_tout = [&](const int& a, const int& b) {
            return tout[a] < tout[b];
        };
        int l = upper_bound(lvl[y].begin(), lvl[y].end(), x, cmp_tin) - lvl[y].begin();
        int r = upper_bound(lvl[y].begin(), lvl[y].end(), x, cmp_tout) - lvl[y].begin();
        
        qs[y].push_back(query{l, r, i});
    }
    
    SegmentTree st(n);
    map<string, int> ids;
    
    for (int i = 0; i < n; i++) {
        sort(qs[i].begin(), qs[i].end());
        memset(st.a, 0, sizeof(int) * 4 * lvl[i].size());
        st.n = lvl[i].size();
        memset(last, -1, sizeof(int) * lvl[i].size());
        ids.clear();
        int lr = 0;
        for (auto& q : qs[i]) {
            if (q.r != lr) {
                for (int j = lr; j < q.r; j++) {
                    int t = lvl[i][j];
                    if (ids.find(nm[t]) == ids.end()) {
                        int id = ids.size();
                        ids[nm[t]] = id;
                    }
                    t = ids[nm[t]];
                    if (last[t] != -1) {
                        st.set(last[t], 0);
                    }
                    st.set(j, 1);
                    last[t] = j;
                }
            }
            lr = q.r;
            ans[q.id] = st.get(q.l, q.r);
        }
    }
    
    for (int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
    }
    
    

    return 0;
}