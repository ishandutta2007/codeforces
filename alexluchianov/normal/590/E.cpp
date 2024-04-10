#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>

using ll = long long;

int const nmax = 750;
int const sigma = 2;
int const lmax = 10000000;

namespace Aho {
  struct Node{
    int leaf = 0;
    int failure = 0;
    int link = 0;
    int son[sigma] = {0, 0};
  } tree[5 + lmax];

  int root, nodePtr;

  bool add(int node, int id, int ptr, std::string &s) {
    if(ptr == s.size()) {
      if(tree[node].leaf == 0) {
        tree[node].leaf = id;
        return 1;
      }
      return 0;
    } else {
      int bit = s[ptr] - 'a';
      if(tree[node].son[bit] == 0) 
        tree[node].son[bit] = ++nodePtr;
      return add(tree[node].son[bit], id, ptr + 1, s); 
    }
  }

  void _buildLinks(int node) {
    tree[node].link = tree[tree[node].failure].link;
    if(tree[tree[node].failure].leaf)
      tree[node].link = tree[node].failure;
    for(int h = 0; h < sigma; h++) {
      int to = tree[node].son[h];
      if(to == 0)
        continue;
      //std::cout << "edge: " << node << " -> " << to << " " << (char)('a' + h) << '\n';
      int target = tree[node].failure;
      while(tree[target].son[h] == 0)
        target = tree[target].failure;
      tree[to].failure = tree[target].son[h];
    }
  }

  void initialize() {
    root = 1;
    nodePtr = 1;
    tree[root].failure = 0;
    tree[0].failure = 0;
    for(int i = 0; i < sigma; i++)
      tree[0].son[i] = root;
  }

  bool addString(int id, std::string &s) {
    return add(root, id, 0, s);
  }

  void buildLinks() {
    std::queue<int> q;
    q.push(root);
    while(0 < q.size()) {
      int node = q.front();
      q.pop();
      _buildLinks(node);
      for(int h = 0; h < 2; h++) {
        int to = tree[node].son[h];
        if(1 < to) {
          q.push(to);
        }
      }
    }
  }

  void _extractOccurrences(int node, int ptr, std::string &s, std::vector<int> &sub) {
    if(0 < tree[node].leaf)
      sub[tree[node].leaf] = 1; 
    for(int target = tree[node].link; 0 < target && sub[tree[target].leaf] == 0; target = tree[target].link)
      sub[tree[target].leaf] = 1;
    if(ptr < s.size()) {
      int bit = s[ptr] - 'a';
      _extractOccurrences(tree[node].son[bit], ptr + 1, s, sub);
    }
  }

  void extractOccurrences(std::string &s, std::vector<int> &sub) {
    _extractOccurrences(root, 0, s, sub);
  }
};

class BipartiteGraph{
private:
  std::vector<int> g[5 + nmax];
  std::vector<int> active, seen;
  std::vector<int> per[2];
  int n;
public:
  BipartiteGraph(int n_, std::vector<int> &active_) {
    n = n_;
    active = active_;
    per[0].resize(1 + n);
    per[1].resize(1 + n);
    seen.resize(1 + n);
  }
  void addEdge(int x, int y) {
    g[x].push_back(y);
  }
  int pairup(int node) {
    if(seen[node] == 1)
      return 0;
    seen[node] = 1;
    for(int h = 0;h  < g[node].size(); h++) {
      int to = g[node][h];
      if(per[1][to] == 0) {
        per[1][to] = node;
        per[0][node] = to;
        return 1;
      }
    }
    for(int h = 0; h < g[node].size(); h++) {
      int to = g[node][h];
      if(pairup(per[1][to])) {
        per[1][to] = node;
        per[0][node] = to;
        return 1;
      }
    }
    return 0;
  }
  void findMatching() {
    while(true) {
      bool advance = false;
      std::fill(seen.begin(), seen.end(), false);
      for(int i = 1; i <= n; i++)
        if(per[0][i] == 0 && pairup(i))
          advance = true;
      if(advance == false)
        break;
    }
  }
  std::vector<int> solve() {
    findMatching();
    std::queue<int> q;
    std::vector<int> inZ(n + 1), inZ2(n + 1);
    for(int i = 1;i <= n; i++)
      if(active[i] == 1 && per[0][i] == 0) {
        q.push(i);
        inZ[i] = 1;
      }

    while(0 < q.size()) {
      int node = q.front();
      q.pop();
      for(int h = 0; h < g[node].size(); h++) {
        int to = g[node][h];
        if(0 == inZ2[to]) {
          inZ2[to] = 1;
          if(0 < per[1][to] && 0 == inZ[per[1][to]]) {
            inZ[per[1][to]] = 1;
            q.push(per[1][to]);
          }
        }
      }
    }
    std::vector<int> answer;
    for(int i = 1;i <= n; i++)
      if(active[i] == 1)
        if(inZ[i] == 1 && inZ2[i] == 0)
          answer.push_back(i);
    return answer;
  }
};

std::string s[5 + nmax];

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  Aho::initialize();
  std::vector<int> active(1 + n);
  for(int i = 1;i <= n; i++) {
    std::cin >> s[i];
    active[i] = Aho::addString(i, s[i]);
  }
  Aho::buildLinks();
  std::vector<std::pair<int,int>> edges;
  for(int i = 1; i <= n; i++) {
    if(active[i] == 1) {
      std::vector<int> sub(1 + n, 0);
      Aho::extractOccurrences(s[i], sub);
      for(int j = 1;j <= n; j++)
        if(sub[j] == 1 && i != j)
          edges.push_back({i, j});
    }
  }
  std::sort(edges.begin(), edges.end());
  BipartiteGraph graph(n, active);
  for(int i = 0; i < edges.size(); i++) {
    graph.addEdge(edges[i].first, edges[i].second);
  }
  std::vector<int> answer = graph.solve();
  std::cout << answer.size() << '\n';
  for(int i = 0; i < answer.size(); i++)
    std::cout << answer[i] << " ";
  std::cout << '\n';
  return 0;
}