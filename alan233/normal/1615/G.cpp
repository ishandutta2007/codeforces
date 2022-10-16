// Author: wlzhouzhuan
#pragma GCC optimize(2,3,"Ofast")
#pragma GCC target("avx","avx2")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
#define fir first
#define sec second
#define SZ(x) (int(x.size()))
#define pii pair<int,int>
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(!isdigit(ch))f|=ch=='-',ch=getchar();
    while(isdigit(ch))x=10*x+ch-'0',ch=getchar();
    return f?-x:x;
}
template<class T>void print(T x){
    if(x<0)putchar('-'),x=-x;
    if(x>=10)print(x/10);
    putchar(x%10+'0');
}
template<class T>void print(T x,char let){print(x),putchar(let);}
template<class T1,class T2>void ckmin(T1&x,T2 y){if(x>y)x=y;}
template<class T1,class T2>void ckmax(T1&x,T2 y){if(x<y)x=y;}

struct forward_lists {
    int L, N;
    vector<int> next;
 
    // L: lists are [0...L), N: integers are [0...N)
    explicit forward_lists(int L = 0, int N = 0) { assign(L, N); }
 
    int rep(int l) const { return l + N; }
    int head(int l) const { return next[rep(l)]; }
    bool empty(int l) const { return head(l) == -1; }
 
    void init(int l, int n) { next[rep(l)] = n, next[n] = -1; }
    void clear(int l) { next[rep(l)] = -1; }
    void exchange(int l, int t) { swap(next[rep(l)], next[rep(t)]); }
 
    void push(int l, int n) { insert(rep(l), n); }
    void insert(int i, int n) { next[n] = next[i], next[i] = n; }
    void pop(int l) { assert(head(l) != -1), next[rep(l)] = next[head(l)]; }
 
    void clear() { fill(begin(next) + N, end(next), -1); }
    void assign(int L, int N) { this->L = L, this->N = N, next.assign(L + N, -1); }
};
 
#define FOR_EACH_IN_FORWARD_LIST(i, l, lists) \
    for (int i = lists.head(l); i != -1; i = lists.next[i])
 
struct linked_lists {
    int L, N;
    vector<int> next, prev;
 
    // L: lists are [0...L), N: integers are [0...N)
    explicit linked_lists(int L = 0, int N = 0) { assign(L, N); }
 
    int rep(int l) const { return l + N; }
    int head(int l) const { return next[rep(l)]; }
    int tail(int l) const { return prev[rep(l)]; }
    bool empty(int l) const { return next[rep(l)] == rep(l); }
 
    int add_list() { return next.push_back(rep(L)), prev.push_back(rep(L)), L++; }
    void clear(int l) { assert(0 <= l && l < L), next[rep(l)] = prev[rep(l)] = rep(l); }
 
    void init(int l, int n) { meet(rep(l), n, rep(l)); }
    void push_front(int l, int n) { meet(rep(l), n, head(l)); }
    void push_back(int l, int n) { meet(tail(l), n, rep(l)); }
    void insert_before(int i, int n) { meet(prev[i], n, i); }
    void insert_after(int i, int n) { meet(i, n, next[i]); }
    void erase(int n) { meet(prev[n], next[n]); }
    void pop_front(int l) { meet(rep(l), next[head(l)]); }
    void pop_back(int l) { meet(prev[tail(l)], rep(l)); }
 
    void splice_front(int l, int b) {
        assert(0 <= l && l < L && 0 <= b && b < L);
        if (l != b && !empty(b))
            meet(tail(b), head(l)), meet(rep(l), head(b)), clear(b);
    }
    void splice_back(int l, int b) {
        assert(0 <= l && l < L && 0 <= b && b < L);
        if (l != b && !empty(b))
            meet(tail(l), head(b)), meet(tail(b), rep(l)), clear(b);
    }
 
    void clear() {
        iota(begin(next) + N, end(next), N);
        iota(begin(prev) + N, end(prev), N);
    }
    void assign(int L, int N) {
        this->L = L, this->N = N;
        next.resize(N + L), prev.resize(N + L), clear();
    }
 
  private:
    inline void meet(int u, int v) { next[u] = v, prev[v] = u; }
    inline void meet(int u, int v, int w) { meet(u, v), meet(v, w); }
};
 
#define FOR_EACH_IN_LINKED_LIST(i, l, lists) \
    for (int z##i = l, i = lists.head(z##i); i != lists.rep(z##i); i = lists.next[i])
 
struct micali_vazirani {
    int V, E = 0;
    vector<int> adj, off, mate;
    vector<array<int, 2>> edge;
 
    micali_vazirani(int V, const vector<array<int, 2>>& g)
        : V(V), E(g.size()), adj(2 * E), off(V + 1, 0), mate(V, -1), edge(g) {
        for (auto [u, v] : edge)
            off[u + 1]++, off[v + 1]++;
        partial_sum(begin(off), end(off), begin(off));
        vector<int> cur = off;
        int e = 0;
        for (auto [u, v] : edge)
            adj[cur[u]++] = adj[cur[v]++] = e++;
    }
 
    inline int other(int e, int u) const { return u ^ edge[e][0] ^ edge[e][1]; }
    inline int len(int u) const { return off[u + 1] - off[u]; }
 
    void bootstrap() {
        linked_lists buck(V, V);
        vector<int> cnt(V, 0);
        for (int u = 0; u < V; u++) {
            if (mate[u] == -1 && len(u)) {
                cnt[u] = len(u);
                buck.push_back(cnt[u], u);
            }
        }
        int s = 1;
        while (s < V) {
            if (buck.empty(s)) {
                s++;
                continue;
            }
            int u = buck.head(s);
            buck.erase(u);
            assert(mate[u] == -1);
            for (int i = off[u]; i < off[u + 1]; i++) {
                int e = adj[i], v = other(e, u);
                if (mate[v] == -1) {
                    mate[u] = v, mate[v] = u;
                    buck.erase(v);
                    break;
                }
            }
            if (mate[u] == -1)
                continue;
            for (int w : {u, mate[u]}) {
                for (int i = off[w]; i < off[w + 1]; i++) {
                    int e = adj[i], t = other(e, w);
                    if (mate[t] == -1) {
                        cnt[t]--;
                        buck.erase(t);
                        if (cnt[t] > 0) {
                            buck.push_back(cnt[t], t);
                            s = min(s, cnt[t]);
                        }
                    }
                }
            }
        }
    }
 
    int max_matching() {
        int more = 1;
        init();
        while (more && count_matched < V / 2) {
            reset_search();
            more = search();
        }
        return count_matched;
    }
 
  private:
    static inline constexpr int inf = INT_MAX / 2;
    static inline constexpr int mv_max_phases = 10; // augmentation phases per search
 
    struct link_t {
        int hi = -1, lo = -1;
    };
 
    struct node_t {
        int minlevel = inf, maxlevel = inf, level[2] = {inf, inf};
        int vis = -1, bloom = -1, petal = -1;
        link_t trail[2] = {};
        int arc[2] = {}, preds = 0, succs = 0;
        bool color = 0, erased = 0;
    };
 
    struct bloom_t {
        int peak, base, star;
    };
 
    vector<int> pred, succ;
    vector<node_t> node;
    vector<bloom_t> bloom;
    forward_lists phaselist, bridges;
    vector<bool> seen;
    int count_matched, phase, blooms, pending, ddfsid, barrier, exposed[2];
 
    inline void add_phase(int lvl, int u) { phaselist.push(lvl, u), pending++; }
    inline void add_bridge(int lvl, int e) { bridges.push(lvl, e); }
 
    // find base*(u) in constant time with union-find
    inline int findstar(int u) {
        int b = node[u].bloom;
        if (b != -1) {
            if (node[bloom[b].star].bloom != -1)
                bloom[b].star = findstar(bloom[b].star);
            return bloom[b].star;
        }
        return u;
    }
 
    void init() {
        pred.resize(2 * E);
        succ.resize(2 * E);
        node.resize(V);
        phaselist.assign(V, V);
        bridges.assign(V, E);
 
        count_matched = 0;
        for (int u = 0; u < V; u++) {
            assert(mate[u] == -1 || mate[mate[u]] == u);
            count_matched += u < mate[u];
        }
    }
 
    void reset_search() {
        phase = blooms = ddfsid = pending = 0;
        phaselist.clear(), bridges.clear();
        for (int u = 0; u < V; u++) {
            node[u] = node_t();
            if (mate[u] == -1) {
                add_phase(0, u);
                node[u].minlevel = node[u].level[0] = 0;
            }
        }
        seen.assign(E, false);
        bloom.clear();
    }
 
    int search() {
        bool done = false;
        int more, augmentations = 0, good = 0;
        while (!done && good < mv_max_phases && count_matched < V / 2) {
            done = MIN();
            more = MAX();
            good += more > 0;
            count_matched += more;
            augmentations += more;
            phase++;
        }
        return augmentations;
    }
 
    void visit_prop(int e, int u, int v, bool parity) {
        assert(!seen[e] && !node[u].erased && !node[v].erased);
        if (node[v].minlevel == inf) {
            node[v].minlevel = node[v].level[!parity] = phase + 1;
            add_phase(phase + 1, v);
        }
        assert(node[v].minlevel == phase + 1 && node[v].level[!parity] == phase + 1);
        pred[off[v] + node[v].preds++] = u;
        succ[off[u] + node[u].succs++] = v;
        seen[e] = true;
    }
 
    void visit_bridge(int e, bool parity) {
        auto [u, v] = edge[e];
        assert(!seen[e] && !node[u].erased && !node[v].erased);
        assert(node[u].level[parity] < inf && node[v].level[parity] < inf);
        int tenacity = node[u].level[parity] + node[v].level[parity] + 1;
        int lvl = tenacity >> 1;
        assert(phase <= lvl && lvl < V);
        add_bridge(lvl, e);
        seen[e] = true;
    }
 
    void bfs_visit(int e, int u, int v) {
        bool parity = phase % 2;
        if (node[v].minlevel > phase) {
            visit_prop(e, u, v, parity);
        } else if (node[v].level[parity] < inf) {
            visit_bridge(e, parity);
        }
    }
 
    bool MIN() {
        if (pending == 0)
            return true;
 
        bool parity = phase % 2;
        FOR_EACH_IN_FORWARD_LIST (u, phase, phaselist) {
            pending--;
            if (node[u].erased)
                continue;
            if (parity == 0) {
                for (int i = off[u]; i < off[u + 1]; i++) {
                    int e = adj[i], v = other(e, u);
                    if (mate[u] != v && !seen[e] && !node[v].erased)
                        bfs_visit(e, u, v);
                }
            } else if (!node[mate[u]].erased) {
                for (int i = off[u]; i < off[u + 1]; i++) {
                    int e = adj[i], v = other(e, u);
                    if (mate[u] == v && !seen[e])
                        bfs_visit(e, u, v);
                    if (mate[u] == v)
                        break;
                }
            }
        }
        return false;
    }
 
    void push_dfs(int& h, bool c, int v, int w) {
        assert(node[h].vis != ddfsid || (node[h].color == c && node[h].arc[c] > 1));
        node[h].vis = ddfsid;
        node[h].color = c;
        node[w].arc[c] = 0;
        node[w].trail[c].hi = h;
        node[w].trail[c].lo = v;
        h = w;
    }
 
    bool pop_dfs(int& h, bool c) {
        h = node[h].trail[c].hi;
        int i = node[h].arc[c], s = node[h].preds;
        return i < s;
    }
 
    void advance_dfs(int& h, bool c) {
        int& i = node[h].arc[c];
        int v = pred[off[h] + i++], w = findstar(v);
        lazy_erase_predecessors(h, i);
        push_dfs(h, c, v, w);
    }
 
    bool reverse_dfs(int& h, bool c, int b) {
        bool ok = false;
        while (!ok && h != b) {
            ok = pop_dfs(h, c);
        }
        return ok;
    }
 
    bool backtrack_dfs(int& h, bool c, int b) {
        int x = h, lvl = node[x].minlevel;
        while ((h == x || node[h].minlevel > lvl) && reverse_dfs(h, c, b)) {
            do {
                advance_dfs(h, c);
            } while (node[h].vis != ddfsid && node[h].minlevel > lvl);
        }
        return h != b;
    }
 
    int ddfs(int peak) {
        int r = findstar(edge[peak][0]), b = findstar(edge[peak][1]);
        if (r == b)
            return -1;
 
        int red_barrier = r;
        ++ddfsid, barrier = b;
        node[r].arc[0] = node[b].arc[1] = 0;
        node[r].trail[0] = node[b].trail[1] = {};
 
        while (node[r].minlevel != 0 || node[b].minlevel != 0) {
            if (node[r].minlevel >= node[b].minlevel) {
                advance_dfs(r, 0);
            } else {
                advance_dfs(b, 1);
            }
            if (r == b) {
                if (!backtrack_dfs(b, 1, barrier)) {
                    b = barrier = r;
                    if (!backtrack_dfs(r, 0, red_barrier)) {
                        r = barrier = b;
                        return 0;
                    }
                }
            }
        }
        assert(r != b);
        exposed[0] = r, exposed[1] = b;
        return 1;
    }
 
    int MAX() {
        int augmentations = 0;
        FOR_EACH_IN_FORWARD_LIST (peak, phase, bridges) {
            auto [red, blue] = edge[peak];
            if (node[red].erased || node[blue].erased)
                continue;
 
            auto what = ddfs(peak);
            if (what == 1) {
                augment_path(peak);
                augmentations++;
            } else if (what == 0) {
                form_bloom(peak);
                blooms++;
            }
        }
        return augmentations;
    }
 
    void bloom_build_petals() {
        for (bool c : {0, 1}) {
            int u = barrier, v = node[u].trail[c].hi;
            while (v != -1) {
                node[v].petal = node[u].trail[c].lo;
                u = v, v = node[u].trail[c].hi;
            }
        }
    }
 
    void bloom_dfs_level(int u) {
        if (u == barrier)
            return;
 
        int lvl = 2 * phase + 1 - node[u].minlevel;
        assert(!node[u].erased && node[u].bloom == -1 && node[u].vis == ddfsid);
        assert(lvl < V && node[u].maxlevel == inf && node[u].level[lvl % 2] == inf);
 
        node[u].bloom = blooms;
        node[u].maxlevel = node[u].level[lvl % 2] = lvl;
        add_phase(lvl, u);
 
        for (int i = 0; i < node[u].preds; i++) {
            int v = pred[off[u] + i], w = findstar(v);
            if (node[w].bloom == -1 && node[u].color == node[w].color)
                bloom_dfs_level(w);
        }
 
        if (lvl % 2 == 0) {
            for (int i = off[u]; i < off[u + 1]; i++) {
                int e = adj[i], v = other(e, u);
                if (!node[v].erased && !seen[e] && node[v].level[0] < inf)
                    visit_bridge(e, 0);
            }
        }
    }
 
    void form_bloom(int peak) {
        assert(node[barrier].bloom == -1);
        bloom.push_back({peak, barrier, barrier});
        bloom_build_petals();
        bloom_dfs_level(findstar(edge[peak][0]));
        bloom_dfs_level(findstar(edge[peak][1]));
    }
 
    using path_t = list<int>;
 
    inline void add_path(path_t& path, bool back, path_t&& subpath) {
        path.splice(back ? end(path) : begin(path), subpath);
    }
    inline void add_path(path_t& path, bool back, int node) {
        back ? path.push_back(node) : path.push_front(node);
    }
 
    path_t walk_bloom(int u, bool down) {
        int B = node[u].bloom;
 
        if (node[u].minlevel % 2 == 0) /* outer */ {
            return walk_down(u, B, down);
        } else /* inner */ {
            int t = edge[bloom[B].peak][!node[u].color];
            auto path = walk_peak(u, B, !down);
            add_path(path, down, walk_base(t, B, down));
            return path;
        }
    }
 
    path_t walk_star(int u, int star, bool down) {
        path_t path;
        while (u != star) {
            add_path(path, down, walk_bloom(u, down));
            u = bloom[node[u].bloom].base;
        }
        return path;
    }
 
    path_t walk_peak(int u, int B, bool down) {
        bool c = node[u].color;
        int t = edge[bloom[B].peak][c];
 
        path_t path{u}, top_path;
        while (node[t].bloom != B) {
            add_path(top_path, down, walk_bloom(t, down));
            t = bloom[node[t].bloom].base;
        }
        while (u != t) {
            int v = node[u].trail[c].lo;
            add_path(path, !down, walk_star(v, u, down));
            u = node[u].trail[c].hi;
            add_path(path, !down, u);
        }
        add_path(path, !down, move(top_path));
        return path;
    }
 
    path_t walk_base(int u, int B, bool down) {
        int base = bloom[B].base;
 
        path_t path;
        while (u != base) {
            if (node[u].bloom == B) {
                add_path(path, down, u);
                u = node[u].petal; // take a predecessor of the same color
            } else {
                add_path(path, down, walk_bloom(u, down));
                u = bloom[node[u].bloom].base;
            }
        }
        return path;
    }
 
    path_t walk_down(int u, int B, bool down) {
        int base = bloom[B].base;
 
        path_t path;
        while (u != base) {
            if (node[u].bloom == B) {
                add_path(path, down, u);
                u = pred[off[u]]; // any predecessor works to go down
            } else {
                add_path(path, down, walk_bloom(u, down));
                u = bloom[node[u].bloom].base;
            }
        }
        return path;
    }
 
    path_t find_path(int top, int c, bool down) {
        int u = exposed[c], w = findstar(top);
 
        path_t path;
        while (u != w) {
            int v = node[u].trail[c].lo;
            add_path(path, !down, u);
            add_path(path, !down, walk_star(v, u, down));
            u = node[u].trail[c].hi;
        }
        add_path(path, !down, w);
        add_path(path, !down, walk_star(top, w, down));
        return path;
    }
 
    void augment_path(int peak) {
        auto path = find_path(edge[peak][0], 0, false);
        auto rest = find_path(edge[peak][1], 1, true);
        path.splice(end(path), rest);
 
        assert(path.size() == 2u * phase + 2);
 
        auto ait = begin(path), bit = next(ait);
        while (bit != end(path)) {
            int u = *ait++, v = *bit++;
            assert(!node[u].erased && !node[v].erased);
            if (mate[v] != u)
                mate[u] = v, mate[v] = u;
        }
        for (int u : path) {
            node[u].erased = true;
        }
        erase_successors(path);
    }
 
    void erase_successors(path_t& path) {
        while (!path.empty()) {
            int u = path.front();
            path.pop_front();
            for (int i = 0; i < node[u].succs; i++) {
                int v = succ[off[u] + i];
                if (!node[v].erased && lazy_erase_predecessors(v)) {
                    node[v].erased = true;
                    path.push_back(v);
                }
            }
        }
    }
 
    inline bool lazy_erase_predecessors(int v, int i = 0) {
        int& s = node[v].preds;
        while (i < s && node[pred[off[v] + i]].erased) {
            swap(pred[off[v] + i], pred[off[v] + s - 1]), s--;
        }
        return i == s; // erased all after i?
    }
};

const int N=300005;

bool used[N],vis[N];
int a[N],n;

int main(){
    n=read();
    for(int i=1;i<=n;i++)a[i]=read(),vis[a[i]]=1;
    for(int i=1;i<n;i++)if(a[i]==a[i+1]&&a[i])used[a[i]]=1;
    vector<array<int,2>>edge;
    int t=*max_element(a+1,a+n+1)+1;
    for(int i=1;i<n;i++){
        if(used[a[i]]||used[a[i+1]])continue;
        if(!a[i]&&!a[i+1]){
            edge.pb({t+i,t+i+1});
        }else if(!a[i]){
            edge.pb({t+i,a[i+1]});
        }else if(!a[i+1]){
            edge.pb({a[i],t+i+1});
        }
    }
    micali_vazirani G(t+n+1,edge);
    G.max_matching();
    int go=0;
    for(auto it:edge){
        int u=it[0],v=it[1];
        if(G.mate[u]==v){
            if(u>t&&v>t){
                ++go;
                while(vis[go])++go;
                a[u-t]=a[v-t]=go;
            }else if(u>t){
                a[u-t]=v;
            }else if(v>t){
                a[v-t]=u;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!a[i])a[i]=1;
        print(a[i], " \n"[i==n]);
    }
    return 0;
}