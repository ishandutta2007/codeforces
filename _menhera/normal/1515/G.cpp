#pragma GCC target("avx2,popcnt")
#include<bits/stdc++.h>


#include <algorithm>

#include <algorithm>
#include <utility>
#include <vector>

namespace atcoder {
namespace internal {

template <class E> struct csr {
    std::vector<int> start;
    std::vector<E> elist;
    csr(int n, const std::vector<std::pair<int, E>>& edges)
        : start(n + 1), elist(edges.size()) {
        for (auto e : edges) {
            start[e.first + 1]++;
        }
        for (int i = 1; i <= n; i++) {
            start[i] += start[i - 1];
        }
        auto counter = start;
        for (auto e : edges) {
            elist[counter[e.first]++] = e.second;
        }
    }
};

// Reference:
// R. Tarjan,
// Depth-First Search and Linear Graph Algorithms
struct scc_graph {
  public:
    scc_graph(int n) : _n(n) {}

    int num_vertices() { return _n; }

    void add_edge(int from, int to) { edges.push_back({from, {to}}); }

    // @return pair of (# of scc, scc id)
    std::pair<int, std::vector<int>> scc_ids() {
        auto g = csr<edge>(_n, edges);
        int now_ord = 0, group_num = 0;
        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);
        visited.reserve(_n);
        auto dfs = [&](auto self, int v) -> void {
            low[v] = ord[v] = now_ord++;
            visited.push_back(v);
            for (int i = g.start[v]; i < g.start[v + 1]; i++) {
                auto to = g.elist[i].to;
                if (ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if (low[v] == ord[v]) {
                while (true) {
                    int u = visited.back();
                    visited.pop_back();
                    ord[u] = _n;
                    ids[u] = group_num;
                    if (u == v) break;
                }
                group_num++;
            }
        };
        for (int i = 0; i < _n; i++) {
            if (ord[i] == -1) dfs(dfs, i);
        }
        for (auto& x : ids) {
            x = group_num - 1 - x;
        }
        return {group_num, ids};
    }

    std::vector<std::vector<int>> scc() {
        auto ids = scc_ids();
        int group_num = ids.first;
        std::vector<int> counts(group_num);
        for (auto x : ids.second) counts[x]++;
        std::vector<std::vector<int>> groups(ids.first);
        for (int i = 0; i < group_num; i++) {
            groups[i].reserve(counts[i]);
        }
        for (int i = 0; i < _n; i++) {
            groups[ids.second[i]].push_back(i);
        }
        return groups;
    }

  private:
    int _n;
    struct edge {
        int to;
    };
    std::vector<std::pair<int, edge>> edges;
};

}  // namespace internal

}  // namespace atcoder

#include <cassert>
#include <vector>

namespace atcoder {

struct scc_graph {
  public:
    scc_graph() : internal(0) {}
    scc_graph(int n) : internal(n) {}

    void add_edge(int from, int to) {
        int n = internal.num_vertices();
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        internal.add_edge(from, to);
    }

    std::vector<std::vector<int>> scc() { return internal.scc(); }

  private:
    internal::scc_graph internal;
};

}  // namespace atcoder

using namespace std;
using namespace atcoder;

const int MAXN = 202020;

int N, M;
int a[MAXN], b[MAXN], l[MAXN];
vector<int > conn[MAXN];

int color[MAXN];
vector<int> colorE[MAXN];
long long colorans[MAXN];

long long dist[MAXN];
bool vis[MAXN];

void dfs(int u, long long d)
{
    if(vis[u]) return;
    vis[u] = true;
    dist[u] = d;
    for(auto Eno: conn[u])
    {
        if(color[a[Eno]] != color[b[Eno]]) continue;
        dfs(b[Eno], d+l[Eno]);
    }
}

long long solve(int c, vector<int> vs)
{
    long long g = 0;
    dfs(vs[0], 0);
    for(auto Eno: colorE[c])
        g = std::gcd(g, abs(dist[a[Eno]]+l[Eno]-dist[b[Eno]]));
    return g;
}

int main()
{
    scanf("%d%d", &N, &M);
    scc_graph graph(N);
    for(int i=0; i<M; ++i)
    {
        scanf("%d%d%d", a+i, b+i, l+i);
        --a[i]; --b[i]; graph.add_edge(a[i], b[i]);
        conn[a[i]].push_back(i);
    }
    auto ret = graph.scc();
    for(int i=0; i<(int)ret.size(); ++i)
        for(auto x: ret[i])
            color[x] = i;
    for(int i=0; i<M; ++i)
        if(color[a[i]] == color[b[i]])
            colorE[color[a[i]]].push_back(i);
    for(int i=0; i<(int)ret.size(); ++i)
        colorans[i] = solve(i, ret[i]);
    int Q; scanf("%d", &Q);
    // for(int i=0; i<(int)ret.size(); ++i) cerr << colorans[i] << endl;
    for(int i=0; i<Q; ++i)
    {
        int v, s, t; scanf("%d%d%d", &v, &s, &t);
        int c = color[v-1];
        if(s == 0) puts("YES");
        else
        {
            long long g = gcd(t, colorans[c]);
            if(g == 0) puts("NO");
            else if(s % g == 0) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}