#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>

using namespace std;

struct Ne {
    int node;
    ll dist;
};

vector<Ne> nei[100005];
ll dist[100005];
ll radius1 = -1;
int furthest1 = 1;
ll radius2 = -1;
int furthest2 = 1;

void find_furthest1(int node, ll d = 0, int par = -1) {
    if(d > radius1) {
        radius1 = d;
        furthest1 = node;
    }
    for(Ne ne : nei[node]) {
        if(ne.node == par) { continue; }
        find_furthest1(ne.node,d+ne.dist,node);
    }
}

void find_furthest2(int node, ll d = 0, int par = -1) {
    if(d > radius2) {
        radius2 = d;
        furthest2 = node;
    }
    dist[node] = d;
    for(Ne ne : nei[node]) {
        if(ne.node == par) { continue; }
        find_furthest2(ne.node,d+ne.dist,node);
    }
}

void gen_dist(int node, ll d = 0, int par = -1) {
    dist[node] = max(dist[node],d);
    for(Ne ne : nei[node]) {
        if(ne.node == par) { continue; }
        gen_dist(ne.node,d+ne.dist,node);
    }
}

struct DSU {
    vector<int> depth;
    vector<int> root;
    vector<int> set_size;
    int curr_set = 0;
    int max_component = 1;
    vector<int> state;

    DSU(int n) {
        depth.resize(n+1);
        root.resize(n+1);
        set_size.resize(n+1);
        state.resize(n+1);
        for(int i = 1; i <= n; i ++) {
            root[i] = i;
            set_size[i] = 1;
        }
    }

    int get_root(int node) {
        if(root[node] == node) { return node; }
        return root[node] = get_root(root[node]);
    }

    void join(int a, int b) {
        a = get_root(a);
        b = get_root(b);
        if(a == b) { return; }
        int rank_a = depth[a];
        int rank_b = depth[b];
        if(rank_a > rank_b) {
            root[b] = a;
            set_size[a] += set_size[b];
            max_component = max(max_component,set_size[a]);
        } else if(rank_a < rank_b) {
            root[a] = b;
            set_size[b] += set_size[a];
            max_component = max(max_component,set_size[b]);
        } else {
            root[b] = a;
            set_size[a] += set_size[b];
            max_component = max(max_component,set_size[a]);
            depth[a] ++;
        }
    }

    void remove(int a) {
        state[a] = 2;
        set_size[get_root(a)] --;
    }
};



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i < n; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        nei[a].push_back({b,c});
        nei[b].push_back({a,c});
    }
    ll radius = 0;
    stack<int> dfs; dfs.push(1);
    find_furthest1(1);
    find_furthest2(furthest1);
    gen_dist(furthest2);

    vector<pll> nodes(n);
    auto it = nodes.begin();
    for(int i = 1; i <= n; i ++) {
        *it = {dist[i],i};
        it ++;
    }
    sort(nodes.begin(), nodes.end());
    
    int q;
    cin >> q;
    while(q--) {
        ll l;
        cin >> l;
        DSU graph(n);
        int j = n - 1;
        int max_child = 1;
        for(int i = n - 1; i >= 0; i --) {
            pll nde = nodes[i];
            graph.state[nde.second] = 1;
            while(nodes[j].first > nde.first + l) {
                graph.remove(nodes[j].second);
                j --;
            }
            for(Ne ne : nei[nde.second]) {
                if(graph.state[ne.node] == 1) {
                    graph.join(ne.node,nde.second);
                }
            }
            max_child = max(max_child,graph.max_component);
        }
        cout << max_child << "\n";
    }
    return 0;
}