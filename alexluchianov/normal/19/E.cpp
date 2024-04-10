#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

class Dsu{
private:
  std::vector<int> mult;
  std::vector<int> sz;
  std::vector<int> acc;
  bool isBipartite;
  int n;
  int time;

  struct Event{
    int x;
    int y;
    int szx;
    int szy;
    bool isBipartite;
    int timestamp;
  };

  std::vector<Event> st;
public:
  Dsu(int n_) {
    n = n_;
    time = 0;
    mult.resize(1 + n);
    sz.resize(1 + n);
    acc.resize(1 + n);
    isBipartite = true;
    for(int i = 1;i <= n; i++) {
      mult[i] = i;
      sz[i] = 1;
      acc[i] = 0;
    }
  }
  int getTime() {
    return time;
  }
  int jump(int gala, int &aux) {
    if(gala == mult[gala])
      return gala;
    else {
      aux ^= acc[gala];
      return jump(mult[gala], aux);
    }
  }
  void unite(int gala, int galb) {
    ++time;
    int dist = 0;
    gala = jump(gala, dist);
    galb = jump(galb, dist);
    st.push_back({gala, galb, sz[gala], sz[galb], isBipartite, time});
    if(gala == galb) {
      if(dist == 0)
        isBipartite = false;
    } else {
      if(sz[gala] < sz[galb])
        std::swap(gala, galb);
      sz[gala] += sz[galb];
      acc[galb] = (1 ^ dist);
      mult[galb] = gala;
    }
  }
  
  bool checkBipartite() {
    return isBipartite;
  }

  void revert(int time) {
    while(0 < st.size() && time < st.back().timestamp) {
      Event e = st.back();
      sz[e.x] = e.szx;
      sz[e.y] = e.szy;
      mult[e.x] = e.x;
      mult[e.y] = e.y;
      isBipartite = e.isBipartite;
      st.pop_back();
    }
  }
};

int const nmax = 10000;
std::vector<std::pair<int,int>> aint[1 + 4 * nmax];

void update(int node, int from, int to, int x, int y, std::pair<int,int> edge) {

  if(from == x && to == y)
    aint[node].push_back(edge);
  else {
    int mid = (from + to) / 2;
    if(x <= mid)
      update(node * 2, from, mid, x, std::min(y, mid), edge);
    if(mid + 1 <= y)
      update(node * 2 + 1, mid + 1, to, std::max(mid + 1, x), y, edge);
  }
}

void solve(int node, int from, int to, std::vector<int> &sol, Dsu &dsu) {
  int timestamp = dsu.getTime();
  for(int h = 0; h < aint[node].size(); h++) 
    dsu.unite(aint[node][h].first, aint[node][h].second);
  if(from == to && dsu.checkBipartite() == true)
    sol.push_back(from);
  
  if(from < to) {
    int mid = (from + to) / 2;
    solve(node * 2, from, mid, sol, dsu);
    solve(node * 2 + 1, mid + 1, to, sol, dsu);
  }
  dsu.revert(timestamp);
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  Dsu dsu(n);
  for(int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    if(1 < i)
      update(1, 1, m, 1, i - 1, {x, y});
    if(i < m)
      update(1, 1, m, i + 1, m, {x, y});
  }
  std::vector<int> sol;
  solve(1, 1, m, sol, dsu);
  std::cout << sol.size() << '\n';
  for(int i = 0; i < sol.size(); i++)
    std::cout << sol[i] << " ";
  std::cout << '\n';
  return 0;
}