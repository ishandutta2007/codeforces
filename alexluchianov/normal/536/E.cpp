#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using ll = long long;

int const nmax = 100000;
int score[5 + nmax];

struct Node{
  int result;
  bool complete;
  int suff;
  int pref;
  Node(int val = 0) {
    result = score[val];
    complete = val;
    suff = pref = val;
  }
  Node(int result_, bool complete_, int suff_, int pref_) {
    result = result_;
    complete = complete_;
    suff = suff_;
    pref = pref_;
  }
  Node operator + (Node const oth) const {
    Node answer;
    answer.result = result + oth.result - score[suff] - score[oth.pref] + score[suff + oth.pref];
    answer.complete = complete & oth.complete;
    answer.suff = oth.suff + (oth.complete * suff);
    answer.pref = pref + (complete * oth.pref);
    return answer;
  }
  Node reverse() const {
    return Node(result, complete, pref, suff);
  }
};

class SegmentTree{
  private:
    std::vector<Node> aint;
  public:
    SegmentTree(int n = 0) {
      aint.resize(1 + 4 * n);
    }
    void update(int node, int from, int to, int x, int val) {
      assert(from <= x && x <= to);
      if(from < to) {
        int mid = (from + to) / 2;
        if(x <= mid)
          update(node * 2, from, mid, x, val);
        else
          update(node * 2 + 1, mid + 1, to, x, val);
        aint[node] = aint[node * 2] + aint[node * 2 + 1];
      } else
        aint[node] = val;
    }
    Node query(int node, int from, int to, int x, int y) {
      assert(x <= y && from <= x && y <= to);

      if(from == x && to == y)
        return aint[node];
      else {
        int mid = (from + to) / 2;
        if(x <= mid && y <= mid)
          return query(node * 2, from, mid, x, y);
        else if(mid + 1 <= x && mid + 1 <= y)
          return query(node * 2 + 1, mid + 1, to, x, y);
        else
          return query(node * 2, from, mid, x, mid) + 
            query(node * 2 + 1, mid + 1, to, mid + 1, y);
      }
    }
};

namespace HeavyPath {
  std::vector<int> g[5 + nmax];
  int level[5 + nmax], sz[5 + nmax];

  void dfs(int node, int parent) {
    sz[node] = 1;
    level[node] = level[parent] + 1;
    for(int h = 0; h < g[node].size(); h++) {
      int to = g[node][h];
      if(to == parent)
        continue;
      dfs(to, node);
      sz[node] += sz[to];
    }
  }

  int start[5 + nmax], pos[5 + nmax], revpos[5 + nmax], far[5 + nmax], ptr = 0;
  void orderNodes(int node, int parent) {
    std::sort(g[node].begin(), g[node].end(), [&](int x, int y){return sz[x] < sz[y];});
    std::reverse(g[node].begin(), g[node].end());
    
    pos[node] = ++ptr;
    revpos[ptr] = node;
    far[node] = parent;

    if(pos[parent] + 1 == pos[node] && parent != 0)
      start[node] = start[parent];
    else {
      start[node] = node;
      assert(sz[node] * 2 <= sz[parent] || parent == 0);
    }

    for(int h = 0; h < g[node].size(); h++) {
      int to = g[node][h];
      if(to == parent)
        continue;
      orderNodes(to, node);
    }
  }
  SegmentTree aint;
  int n;
  void initialize(int n_) {
    n = n_;
    aint = SegmentTree(n);
  }
  void update(int x, int y, int val) {
    if(level[x] < level[y])
      std::swap(x, y);
    aint.update(1, 1, n, pos[x], val);
  }
  
  int getLca(int x, int y) {
    while(start[x] != start[y]) {
      if(level[far[start[x]]] <= level[far[start[y]]])
        y = far[start[y]];
      else
        x = far[start[x]];
    }
    if(level[x] <= level[y])
      return x;
    else
      return y;
  }

  int query(int x, int y) {
    int lca = getLca(x, y);

    auto getPath = [&](int anc, int target) {
      int steps = 0;
      Node answer;
      while(start[target] != start[anc]) {
        assert(level[anc] <= level[start[target]]);
        answer = aint.query(1, 1, n, pos[start[target]], pos[target]) + answer;
        target = far[start[target]];
        ++ steps;
      }
      if(target == anc)
        return answer;
      return aint.query(1, 1, n, pos[anc] + 1, pos[target]) + answer;
    };
    return (getPath(lca, x).reverse() + getPath(lca, y)).result;
  }
}


struct Event{
  int type;
  int x;
  int y;
  int l;
  bool operator < (Event const oth) {
    if(l != oth.l)
      return l > oth.l;
    else
      return type < oth.type;
  }
};

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;
  for(int i = 1; i < n; i++)
    std::cin >> score[i];
  std::vector<Event> events;
  for(int i = 1;i < n; i++) {
    int x, y, cost;
    std::cin >> x >> y >> cost;
    events.push_back({0, x, y, cost});
    HeavyPath::g[x].push_back(y);
    HeavyPath::g[y].push_back(x);
  }
  for(int i = 1; i <= q; i++) {
    int x, y, cost;
    std::cin >> x >> y >> cost;
    events.push_back({i, x, y, cost});
  }
  std::sort(events.begin(), events.end());
  HeavyPath::initialize(n);
  HeavyPath::dfs(1, 0);
  HeavyPath::orderNodes(1, 0);

  std::vector<int> sol(q);
  for(int i = 0; i < events.size(); i++) {
    Event ev = events[i];
    if(ev.type == 0)
      HeavyPath::update(ev.x, ev.y, 1);
    else 
      sol[ev.type - 1] = HeavyPath::query(ev.x, ev.y);
      
  }
  for(auto it: sol) 
    std::cout << it << '\n';
  return 0;
}