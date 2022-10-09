#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

int const nmax = 500000;

struct Node{
  int state[2][3][3];

  Node() {
    for(int t = 0;t < 2; t++)
      for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
          state[t][i][j] = -nmax * 3;
  }

  Node(int x, int y) {
    for(int t = 0;t < 2; t++)
      for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
          state[t][i][j] = -nmax * 3;
    state[x][0][0] = y;
    state[x][1][1] = -y * 2;
    state[!x][1][1] = -y * 2;
    state[x][2][2] = y;
  }

  Node operator + (const Node oth) {
    Node result;
    for(int t = 0; t < 2; t++) {
      for(int i = 0; i < 3; i++)
        for(int j = i; j < 3; j++)
          result.state[t][i][j] = std::max(state[t][i][j], oth.state[t][i][j]);
      for(int i = 0; i < 3; i++)
        for(int j = i; j < 3; j++)
          for(int h = j + 1; h < 3; h++)
            result.state[t][i][h] = std::max(result.state[t][i][h], state[t][i][j] + oth.state[t][j + 1][h]);
    }
    return result;
  }

  void flip() {
    for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
        std::swap(state[0][i][j], state[1][i][j]);
  }
};


class SegmentTree{
  private:
    std::vector<Node> aint;
    std::vector<char> lazy;
  public:
    SegmentTree(int n) {
      aint.resize(1 + 4 * n);
      lazy.resize(1 + 4 * n);
    }

    void build(int node, int from, int to, std::vector<std::pair<int,int>> &aux) {
      if(from < to) {
        int mid = (from + to) / 2;
        build(node * 2, from, mid, aux);
        build(node * 2 + 1, mid + 1, to, aux);
        aint[node] = aint[node * 2] + aint[node * 2 + 1];
      } else
        aint[node] = Node(aux[from].second, aux[from].first);
    }

    void clean_node(int node, int from, int to) {
      if(lazy[node] == 0)
        return ;
      int mid = (from + to) / 2;
      if(from < to) {
        lazy[node * 2] ^= lazy[node];
        lazy[node * 2 + 1] ^= lazy[node];
      }
      aint[node].flip();
      lazy[node] = 0;
    }

    void update(int node, int from, int to, int x, int y) {
      if(from == x && to == y) {
        lazy[node] ^= 1;
        clean_node(node, from, to);
      } else {
        int mid = (from + to) / 2;
        clean_node(node * 2, from, mid);
        clean_node(node * 2 + 1, mid + 1, to);

        if(x <= mid)
          update(node * 2, from, mid, x, std::min(y, mid));
        if(mid + 1 <= y)
          update(node * 2 + 1, mid + 1, to, std::max(mid + 1, x), y);
        aint[node] = aint[node * 2] + aint[node * 2 + 1];
      }
    }
    int query() {
      return std::max(aint[1].state[1][0][2], aint[1].state[0][0][2]);
    }
};

int level[5 + nmax], start[5 + nmax], stop[5 + nmax];
int par[5 + nmax];
std::vector<std::pair<int,int>> g[5 + nmax];

void dfs(int node, int parent, std::vector<std::pair<int,int>> &sol, int &ptr) {
  for(int h = 0; h < g[node].size(); h++)
    if(g[node][h].first == parent)
      g[node].erase(g[node].begin() + h);
  start[node] = ptr++;
  sol.push_back({level[node], par[node]});

  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h].first;
    level[to] = level[node] + 1;
    par[to] = par[node] ^ g[node][h].second;
    ptr++;
    sol.push_back({level[node], par[node]});
    dfs(to, node, sol, ptr);
  }

  stop[node] = ptr++;
  sol.push_back({level[node], par[node]});
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  std::vector<std::pair<int,int>> edges;
  for(int i = 1;i < n; i++) {
    int x, y, t;
    std::cin >> x >> y >> t;
    g[x].push_back({y, t});
    g[y].push_back({x, t});
    edges.push_back({x, y});
  }

  level[1] = 1;
  par[1] = 0;
  int ptr = 0;
  std::vector<std::pair<int,int>> base;
  dfs(1, 0, base, ptr);
  SegmentTree aint(base.size()); 
  aint.build(1, 0, base.size() - 1, base);

  int q;
  std::cin >> q;

  for(int i = 1; i <= q; i++) {
    int id;
    std::cin >> id;
    id--;
    int lower;
    if(level[edges[id].second] < level[edges[id].first])
      lower = edges[id].first;
    else
      lower = edges[id].second;
    aint.update(1, 0, base.size() - 1, start[lower], stop[lower]);
    std::cout << aint.query() << '\n';
  }
  return 0;
}