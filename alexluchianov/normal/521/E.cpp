#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using ll = long long;
int const nmax = 200000;

class Dsu{
private:
  std::vector<int> mult;
  int timestamp;
  struct Event{
    int timestamp;
    int x;
    int y;
    int szx;
    int szy;
  };
  std::vector<Event> st;
public:
  std::vector<int> sz;
  Dsu(int n = 0) {
    timestamp = 0;
    mult.resize(n + 1);
    sz.resize(n + 1);
    std::iota(mult.begin(), mult.end(), 0);
    std::fill(sz.begin(), sz.end(), 1);
  }
  int jump(int gala) {
    if(mult[gala] != gala) {
      return jump(mult[gala]);
    }
    return mult[gala]; 
  }
  int getTime() {
    return timestamp;
  }
  void unite(int gala, int galb) {
    ++timestamp;
    gala = jump(gala);
    galb = jump(galb);
    if(gala == galb)
      return ;
    st.push_back({timestamp, gala, galb, sz[gala], sz[galb]});
    if(sz[gala] < sz[galb]) 
      std::swap(gala, galb);
    mult[galb] = gala;
    sz[gala] += sz[galb];
  }
  bool connect(int gala, int galb) {
    return jump(gala) == jump(galb);
  }
  void undo(int timestamp) {
    while(0 < st.size() && timestamp < st.back().timestamp) {
      Event op = st.back();
      mult[op.x] = op.x;
      mult[op.y] = op.y;
      sz[op.x] = op.szx;
      sz[op.y] = op.szy;
      st.pop_back();
    }
  }
  void printStack() {
    std::cout << "PrintStack " << std::endl;
    for(int i = 0; i < st.size(); i++)
      std::cout << st[i].timestamp << " " << st[i].x << " " << st[i].y << " " << st[i].szx << " " << st[i].szy << '\n';
    std::cout << '\n';
  }
};

namespace TimeTree{
  std::vector<std::pair<int,int>> aint[1 + nmax * 4];
  std::vector<int> g[5 + nmax];

  void update(int node, int from, int to, int x, int y, std::pair<int,int> edge) {
    if(from == x && to == y) {
      aint[node].push_back(edge);
    } else {
      int mid = (from + to) /2;
      if(x <= mid)
        update(node * 2, from, mid, x, std::min(y, mid), edge);
      if(mid + 1 <= y)
        update(node * 2 + 1 , mid + 1, to, std::max(mid + 1, x), y, edge);
    }
  }
  Dsu dsu;
  int n;
  void initialize(int n_) {
    n = n_;
    dsu = Dsu(n);
  }

  void addEdge(int x, int y) {
    if(y < x)
      std::swap(x, y);
    if(1 < x)
      update(1, 1, n, 1, x - 1, {x, y});
    if(x + 1 < y)
      update(1, 1, n, x + 1, y - 1, {x, y});
    if(y < n)
      update(1, 1, n, y + 1, n, {x, y});
    g[x].push_back(y);
    g[y].push_back(x);
  }
  
  int query(int node, int from, int to) {
    int original = dsu.getTime();
    for(int h = 0; h < aint[node].size(); h++) { 
      dsu.unite(aint[node][h].first, aint[node][h].second);
    }
    int answer = 0;
    if(from < to) {
      int mid = (from + to) / 2;
      int result = query(node * 2, from, mid) ;
      int result2 = query(node * 2 + 1, mid + 1, to);
      answer = std::max(result, result2);
    } else {
      std::vector<int> candidates;

      for(int h = 0; h < g[from].size(); h++) {
        candidates.push_back(dsu.jump(g[from][h]));
      }
      std::sort(candidates.begin(), candidates.end());
      
      for(int i = 2; i < candidates.size(); i++)
        if(candidates[i - 2] == candidates[i - 1] && candidates[i - 1] == candidates[i]) {
          answer = from;
        }
    }
    dsu.undo(original);
    return answer;
  }
};

std::vector<int> g[5 + nmax];
int level[5 + nmax], group[5 + nmax], far[5 + nmax];

void dfs(int node, int parent) {
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent && level[to] == 0) {
      far[to] = node;
      level[to] = level[node] + 1;
      if(parent == 0)
        group[to] = to;
      else
        group[to] = group[node];
      dfs(to, node);
    }
  }
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::pair<int,int>> edges;
  TimeTree::initialize(n);
  for(int i = 1;i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    edges.push_back({x, y});
    TimeTree::addEdge(x, y);
  }
  int start = TimeTree::query(1, 1, n);
  if(start == 0) {
    std::cout << "NO\n";
    return 0;
  }
  for(int i = 0; i < edges.size(); i++) {
    int x = edges[i].first, y = edges[i].second;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  level[start] = 1;
  dfs(start, 0);
  std::vector<std::pair<int,int>> candidates;
  for(int h = 0;h < g[start].size(); h++) {
    int to = g[start][h];
    if(level[start] + 1 < level[to]) {
      candidates.push_back({group[to], to});
      
    }
  }

  std::sort(candidates.begin(), candidates.end());
  int stopx = 0, stopy = 0;
  for(int i = 1;i < candidates.size(); i++)
    if(candidates[i - 1].first == candidates[i].first) { 
      stopx = candidates[i - 1].second;
      stopy = candidates[i].second;
    }
  
  auto getLca = [&](int x, int y) {
    while(x != y) {
      if(level[x] < level[y])
        y = far[y];
      else
        x = far[x];
    }
    return x;
  };
  
  int lca = getLca(stopx, stopy);
  std::vector<int> paths[3];

  auto getPath = [&](int y, int x) {
    std::vector<int> path;
    while(x != y) {
      path.push_back(y);
      y = far[y];
    }
    path.push_back(x);
    return path;
  };

  paths[0] = getPath(lca, start);
  
  std::reverse(paths[0].begin(), paths[0].end());
  paths[1] = getPath(stopx, lca);
  paths[2] = getPath(stopy, lca);
  
  paths[1].insert(paths[1].begin(), start);
  paths[2].insert(paths[2].begin(), start);
  
  std::cout << "YES\n";
  
  for(int h = 0; h < 3; h++ ) {
    std::cout << paths[h].size() << " ";
    for(int i = 0; i < paths[h].size(); i++)
      std::cout << paths[h][i] << " ";
    std::cout << '\n';
  }
  return 0;
}