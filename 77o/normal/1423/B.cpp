#include <bits/stdc++.h>
using namespace std;

// cl /c /EHsc /Ox /std:c++17 lib.cpp

#include <functional>
#include <limits>
#include <numeric>
#include <queue>
#include <utility>
#include <vector>


class BipartiteGraph {
  public:
    BipartiteGraph(std::pair<int, int> sizes) : sizes_(sizes) {
      edges_.first.resize(sizes_.first);
      nodes_.first.resize(sizes_.first);
      std::iota(nodes_.first.begin(), nodes_.first.end(), 0);

      edges_.second.resize(sizes_.second);
      nodes_.second.resize(sizes_.second);
      std::iota(nodes_.second.begin(), nodes_.second.end(), 0);
    }

    void AddEdge(std::pair<int, int> edge) {
      edges_.first[edge.first].push_back(edge.second);
      edges_.second[edge.second].push_back(edge.first);
    }

    std::pair<int, int> GetSizes() const {
      return sizes_;
    }

    std::pair<std::vector<int>, std::vector<int>> GetNodes() const {
      return nodes_;
    }

    std::vector<int> GetEdges(int node, bool part) const {
      if (part) {
        return edges_.second[node];
      } else {
        return edges_.first[node];
      }
    }

  private:
    std::pair<int, int> sizes_;
    std::pair<std::vector<int>, std::vector<int>> nodes_;
    std::pair<std::vector<std::vector<int>>,
              std::vector<std::vector<int>>> edges_;
};

class BipartiteMatching {
  public:
    static const int kNoMatch;

    BipartiteMatching(std::pair<int, int> capacities) {
      matches_.first.resize(capacities.first, kNoMatch);
      matches_.second.resize(capacities.second, kNoMatch);
    }

    int Get(int node, bool part) const {
      if (part) {
        return matches_.second[node];
      } else {
        return matches_.first[node];
      }
    }

    void Set(std::pair<int, int> edge) {
      if (matches_.first[edge.first] == kNoMatch) {
        ++size_;
      }
      matches_.first[edge.first] = edge.second;
      matches_.second[edge.second] = edge.first;
    }

    int Size() const {
      return size_;
    }

  private:
    int size_ = 0;
    std::pair<std::vector<int>, std::vector<int>> matches_;
};

const int BipartiteMatching::kNoMatch = -1;


BipartiteMatching Kuhn(const BipartiteGraph& bipartite_graph) {
  BipartiteMatching bipartite_matching(bipartite_graph.GetSizes());
  std::vector<bool> used(bipartite_graph.GetSizes().first);

  std::function<bool(int)> try_kuhn = [&] (int node) -> bool {
    if (used[node]) {
      return false;
    } else {
      used[node] = true;
      for (auto adjacent : bipartite_graph.GetEdges(node, false)) {
        auto next_node = bipartite_matching.Get(adjacent, true);
        if (next_node == BipartiteMatching::kNoMatch || try_kuhn(next_node)) {
          bipartite_matching.Set({node, adjacent});
          return true;
        }
      }
      return false;
    }
  };

  for (auto node : bipartite_graph.GetNodes().first) {
    used.assign(used.size(), false);
    try_kuhn(node);
  }

  return bipartite_matching;
}


BipartiteMatching HopcroftKarp(const BipartiteGraph& bipartite_graph) {
  BipartiteMatching bipartite_matching(bipartite_graph.GetSizes());
  const int kNoMatchNode = bipartite_graph.GetSizes().first;
  const int64_t kUnreachable = std::numeric_limits<int64_t>::max();
  std::vector<int64_t> distance(bipartite_graph.GetSizes().first + 1);

  auto try_bfs = [&] () -> bool {
    distance.assign(distance.size(), kUnreachable);
    std::deque<int> bfs;
    for (auto node : bipartite_graph.GetNodes().first) {
      if (bipartite_matching.Get(node, false) == BipartiteMatching::kNoMatch) {
        distance[node] = 0;
        bfs.push_back(node);
      }
    }

    while (!bfs.empty()) {
      auto node = bfs.front();
      bfs.pop_front();
      if (distance[node] < distance[kNoMatchNode]) {
        for (auto adjacent : bipartite_graph.GetEdges(node, false)) {
          auto next_node = bipartite_matching.Get(adjacent, true);
          if (next_node == BipartiteMatching::kNoMatch) {
            next_node = kNoMatchNode;
          } 
          if (distance[next_node] == kUnreachable) {
            distance[next_node] = distance[node] + 1;
            bfs.push_back(next_node);
          }
        }
      }
    }

    return distance[kNoMatchNode] < kUnreachable;
  };

  std::function<bool(int)> dfs = [&] (int node) -> bool {
    if (node != kNoMatchNode) {
      for (auto adjacent : bipartite_graph.GetEdges(node, false)) {
        auto next_node = bipartite_matching.Get(adjacent, true);
        if (next_node == BipartiteMatching::kNoMatch) {
          next_node = kNoMatchNode;
        }
        if (distance[next_node] == distance[node] + 1 && dfs(next_node)) {
          bipartite_matching.Set({node, adjacent});
          return true;
        }
      }
      distance[node] = kUnreachable;
      return false;
    }
    return true;
  };

  while (try_bfs()) {
    for (auto node : bipartite_graph.GetNodes().first) {
      if (bipartite_matching.Get(node, false) == BipartiteMatching::kNoMatch) {
        dfs(node);
      }
    }
  }
  return bipartite_matching;
}


template <typename T = int>
T BinarySearch(T lower_bound, T upper_bound, std::function<bool(T)> unary_predicate, T precision = 1);

#include <iostream>
#include <tuple>

mt19937 rng(58);
struct maximum_bipartite_matching_dfs{
  int n, m, matching = 0;
  vector<vector<int>> adj;
  vector<int> pu, pv; // u is matched with pu[u] and v with pv[v], -1 if no match
  maximum_bipartite_matching_dfs(int n, int m): n(n), m(m), pu(n, -1), pv(m, -1), cur(n), adj(n){ }
  int insert(int from, int to){
    adj[from].push_back(to);
    return (int)adj[from].size() - 1;
  }
  int id = 0;
  vector<int> cur;
  bool dfs(int u){
    cur[u] = id;
    for(auto v: adj[u]) if(!~pv[v]){
      pu[u] = v, pv[v] = u;
      return true;
    }
    for(auto v: adj[u]) if(cur[pv[v]] != id && dfs(pv[v])){
      pu[u] = v, pv[v] = u;
      return true;
    }
    return false;
  }
  // O(VE)
  int maximum_matching(){
    for (int i = 0; i < n; i++)
        shuffle(adj[i].begin(), adj[i].end(), rng);
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        return adj[a].size() < adj[b].size();
    });
    while(true){
      int augment = 0;
      ++ id;
      for(auto u : order) if(pu[u] == -1 && dfs(u)) ++ augment;
      if(!augment) break;
      matching += augment;
    }
    return matching;
  }
  int run_once(int v){
    if(pu[v] != -1) return 0;
    ++ id;
    return dfs(v);
  }
  pair<vector<int>, vector<int>> minimum_vertex_cover(){
    maximum_matching();
    vector<int> L, R, visL(n), visR(m);
    auto dfs = [&](auto self, int u)->void{
      visL[u] = true;
      for(auto v: adj[u]) if(v != pu[u] && !visR[v]){
        visR[v] = true, R.push_back(v);
        if(~pv[v]) self(self, pv[v]);
      }
    };
    for(auto u = 0; u < n; ++ u) if(!visL[u] && pu[u] == -1) dfs(dfs, u);
    for(auto u = 0; u < n; ++ u) if(!visL[u]) L.push_back(u);
    return {L, R};
  }
};

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> e(m);
  for (auto& [d, u, v] : e) {
    cin >> u >> v >> d;
    --u, --v;
  }
  sort(e.begin(), e.end());

  int lo = 0, hi = m;
  auto cannot = [&] (int mi) -> bool {
    maximum_bipartite_matching_dfs bipartite_graph(n, n);
    for (int i = 0; i < mi; ++i)
      bipartite_graph.insert(get<1>(e[i]), get<2>(e[i]));
    return bipartite_graph.maximum_matching() < n;
    // BipartiteGraph bipartite_graph({n, n});
    // for (int i = 0; i < mi; ++i)
    //   bipartite_graph.AddEdge({get<1>(e[i]), get<2>(e[i])});
    // return HopcroftKarp(bipartite_graph).Size() < n;
  };

  if (cannot(hi))
    cout << -1 << "\n";
  else
    cout << get<0>(e[BinarySearch<int>(lo, hi, cannot)]) << "\n";

  return 0;
}

template <typename T>
T BinarySearch(T lower_bound, T upper_bound, std::function<bool(T)> unary_predicate, T precision) {
  while (lower_bound + precision < upper_bound) {
    T middle = lower_bound + (upper_bound - lower_bound) / 2;
    if (unary_predicate(middle)) {
      lower_bound = middle;
    } else {
      upper_bound = middle;
    }
  }
  return lower_bound;
}