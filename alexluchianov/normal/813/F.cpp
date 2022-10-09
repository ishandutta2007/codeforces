#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

using ll = long long;

class Dsu{
private:
  std::vector<int> mult;
  std::vector<int> sz;
  std::vector<int> far;
  bool isBipartite;

  struct Event{
    int time;
    bool isBipartite;
    int x;
    int y;
    int szx;
    int szy;
  };

  std::vector<Event> st;
  int timer;
public:
  Dsu(int n) {
    mult.resize(1 + n);
    sz.resize(1 + n);
    far.resize(1 + n);
    for(int i = 1;i <= n; i++) {
      mult[i] = i;
      sz[i] = 1;
    }

    isBipartite = true;
    timer = 0;
  }
  int jump(int gala, int &acc) {
    while(mult[gala] != gala) {
      acc ^= far[gala];
      gala = mult[gala];
    }
    return gala;
  }
  
  void unite(int gala, int galb) {
    ++timer;
    int acc = 0;
    gala = jump(gala, acc);
    galb = jump(galb, acc);
    st.push_back({timer, isBipartite, gala, galb, sz[gala], sz[galb]});

    if(gala == galb) {
      if(acc == 0) 
        isBipartite = false;
    } else {
      if(sz[gala] < sz[galb]) 
        std::swap(gala, galb);
      mult[galb] = gala;
      sz[gala] += sz[galb];
      far[galb] = !acc;
    }
  }

  int getTime() {
    return timer;
  }

  bool checkBipartite() {
    return isBipartite;
  }
  void revert(int time) {
    while(0 < st.size() && time < st.back().time) {
      Event e = st.back();
      st.pop_back();
      sz[e.x] = e.szx;
      sz[e.y] = e.szy;
      mult[e.x] = e.x;
      mult[e.y] = e.y;
      isBipartite = e.isBipartite;
    }
  }
};

int const nmax = 100000;
std::vector<std::pair<int,int>> aint[1 + 4 * nmax];

void update(int node, int from, int to, int x, int y, std::pair<int, int> edge) {
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
bool sol[1 + nmax];

void query(int node, int from, int to, Dsu &dsu) {
  int time = dsu.getTime();
  for(int h = 0; h < aint[node].size(); h++) 
    dsu.unite(aint[node][h].first, aint[node][h].second);
  if(from < to) {
    int mid = (from + to) / 2;
    query(node * 2, from, mid, dsu);
    query(node * 2 + 1, mid + 1, to, dsu);
  } else
    sol[from] = dsu.checkBipartite();
  dsu.revert(time);
}


int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;
  std::map<std::pair<int,int>, int> mp;

  for(int i = 1;i <= q; i++) {    
    std::pair<int,int> edge;
    std::cin >> edge.first >> edge.second;
    if(mp[edge] == 0) {
      mp[edge] = i;
    } else {
      update(1, 1, q, mp[edge], i - 1, edge);
      mp.erase(edge);
    }
  }
  for(std::map<std::pair<int,int>, int>::iterator it = mp.begin(); it != mp.end(); it++) 
    update(1, 1, q, it->second, q, it->first);
  Dsu dsu(1 + n);
  query(1, 1, q, dsu);

  for(int i = 1;i <= q; i++) {
    if(sol[i] == 0)
      std::cout << "NO\n";
    else
      std::cout << "YES\n";
  }
  return 0;
}