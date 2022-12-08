#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;

#define f first
#define s second
#define setind DEBUG_INDENT = 
#define enl "\n";
#define debug(k) for(int _ = 0; _ < DEBUG_INDENT; _ ++) { cout << "  "; } cout << #k << ": " << k << enl;

const int MOD = 1e9 + 7;
const ll MODL = 1e9 + 7;

using namespace __gnu_pbds;

template<typename T>
using pbds = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int DEBUG_INDENT = 0;

const int mxN = 200005;

int root[mxN];
int sz[mxN];

int get_root(int node) {
    if(root[node] == node) { return node; }
    return root[node] = get_root(root[node]);
}

vector<pi> nei[mxN];

string res;

void unify(int a, int b, int i) {
    int aa = a;
    int bb = b;
    a = get_root(a);
    b = get_root(b);
    if(a == b) { return;}
    res[i] = '1';
    nei[aa].push_back({bb,i});
    nei[bb].push_back({aa,i});
    if(sz[a] < sz[b]) { swap(a,b); }
    sz[a] += sz[b];
    root[b] = a;
}

int depth[mxN];
int sup[mxN];

void dfs(int node, int par = -1) {
    for(pi ne : nei[node]) {
        if(ne.f == par) { continue; }
        sup[ne.f] = node;
        depth[ne.f] = depth[node] + 1;
        dfs(ne.f,node);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        res = string(m,'0');
        for(int i = 1; i <= n; i ++) {
            root[i] = i;
            sz[i] = 1;
            nei[i].clear();
        }
        vector<pi> edges;
        for(int i = 0; i < m; i ++) {
            int a, b;
            cin >> a >> b;
            edges.push_back({a,b});
            unify(a,b,i);
        }
        
        // depth[1] = 0;
        // dfs(1);
        if(m == n + 2) {
            vector<int> bs;
            vector<int> nodes;
            for(int i = 0; i < m; i ++) {
                if(res[i] == '0') {
                    bs.push_back(i);
                    nodes.push_back(edges[i].f);
                    nodes.push_back(edges[i].s);
                }
            }
            sort(nodes.begin(),nodes.end());
            bool cyc = true;
            for(int i = 0; i < 6; i += 2) {
                if(nodes[i] != nodes[i+1]) {
                    cyc = false;
                }
            }
            if(cyc) {
                int a = bs[0];
                int st = edges[a].f;
                int en = edges[a].s;
                vector<int> dist(n+1);
                dist[st] = 0;
                queue<int> bfs; bfs.push(st);
                while(bfs.size()) {
                    int cur =bfs.front();
                    bfs.pop();
                    for(pi ne: nei[cur]) {
                        if(dist[ne.f] == 0) {
                            dist[ne.f] = dist[cur] + 1;
                            bfs.push(ne.f);
                        }
                    }
                }
                pi mn = {1e9,1e9};
                for(pi ne : nei[en]) {
                    mn = min(mn,{dist[ne.f],ne.s});
                }
                res[mn.s] = '0';
                res[a] = '1';
            }
        }
        cout << res << "\n";
    }
    return 0;
}