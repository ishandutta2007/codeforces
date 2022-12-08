#include <bits/stdc++.h>
#define ll long long
#define pl pair<ll,ll>
#define pi pair<int,int>
#define f first
#define s second
#define vi vector<int>
#define vl vector<ll>
#define ld long double

using namespace std;

const int mxN = 300005;

int root[mxN];
int rnk[mxN];

int get_root(int node) {
    if(root[node] == node) { return node; }
    return root[node] = get_root(root[node]);
}

void unify(int a, int b) {
    int ra = get_root(a);
    int rb = get_root(b);
    if(rnk[ra] > rnk[rb]) {
        root[rb] = ra;
    } else if(rnk[ra] < rnk[rb]) {
        root[ra] = rb;
    } else {
        root[rb] = ra;
        rnk[ra] ++;
    }
}

vector<int> nei[mxN];
int depth[mxN];
int par[mxN];
bool val[mxN];

void dfs(int node, int p = -1) {
    for(int ne : nei[node]) {
        if(ne == p) { continue; }
        depth[ne] = depth[node] + 1;
        par[ne] = node;
        dfs(ne,node);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        root[i] = i;
    }
    for(int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        if(get_root(a) == get_root(b)) { continue; }
        nei[a].push_back(b);
        nei[b].push_back(a);
        unify(a,b);
    }
    dfs(1);
    int q;
    cin >> q;
    vector<pi> qs(q);
    vector<deque<int>> paths(q);
    int qi = 0;
    for(pi &p : qs) {
        int a, b;
        cin >> a >> b;
        p = {a,b};
        deque<int> st;
        while(depth[a] > depth[b]) {
            val[a] = !val[a];
            st.push_back(a);
            a = par[a];
        }
        deque<int> en;
        while(depth[b] > depth[a]) {
            val[b] = !val[b];
            en.push_front(b);
            b = par[b];
        }
        while(a != b) {
            val[a] = !val[a];
            val[b] = !val[b];
            st.push_back(a);
            en.push_front(b);
            a = par[a];
            b = par[b];
        }
        st.push_back(a);
        for(int x : st) {
            paths[qi].push_back(x);
        }
        for(int x : en) {
            paths[qi].push_back(x);
        }
        qi ++;
    }
    bool fail = false;
    for(int i = 1; i <= n; i ++) {
        if(val[i]) {
            fail = true;
        }
    }
    if(fail) {
        int res = 0;
        for(int i = 1; i <= n; i ++) {
            int d = val[i];
            for(int c : nei[i]) {
                if(c == par[i]) {continue;}
                if(val[c]) {
                    d ++;
                }
            }
            res += (d-1)/2;
        }
        vector<bool> vis(n+1);
        for(int i = 1; i <= n ; i ++) {
            if(vis[i]) { continue; }
            int sz = -1;
            vis[i] = true;
            deque<int> bfs = {i};
            while(bfs.size()) {
                int cur = bfs.back();
                bfs.pop_back();
                sz ++;
                for(int ne : nei[cur]) {
                    if(ne == par[cur]) {continue;}
                    if(val[ne] && !vis[ne]) {
                        vis[ne] = true;
                        bfs.push_front(ne);
                    }
                }
                if(val[cur] && !vis[par[cur]]) {
                    vis[par[cur]] = true;
                    bfs.push_front(par[cur]);
                }
            }
            if(sz) {
                res ++;
            }
        }
        cout << "NO\n";
        cout << res << "\n";
    } else {
        cout << "YES\n";
        for(int qi = 0; qi < q; qi ++) {
            cout << paths[qi].size() << "\n";
            for(int x : paths[qi]) {
                cout << x << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}

/*
8 7
1 4
3 4
2 4
4 6
6 5
6 7
6 8
0
7
1 4
3 4
2 4
4 6
6 5
6 7
6 8
*/

/*
5 4
1 2
2 3
1 4
4 5
2
2 3
5 4
*/