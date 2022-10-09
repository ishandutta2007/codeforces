#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

class Dsu{
public:
  struct Event{
    int x;
    int y;
    int szx;
    int szy;
    int timestamp;
  };
  std::vector<int> mult;
  std::vector<int> sz;
  Dsu(int n) {
    mult.resize(1 + n);
    sz.resize(1 + n);
    for(int i = 1;i <= n; i++)
      mult[i] = i;
    for(int i = 1;i <= n; i++)
      sz[i] = 1;
  }
  int jump(int gala) {
    if(mult[gala] != gala)
      return jump(mult[gala]);
    return mult[gala];
  }
  std::vector<Event> st;
  void unite(int gala, int galb, int timestamp) {
    gala = jump(gala);
    galb = jump(galb);
    if(gala == galb)
      return ;
    if(sz[galb] < sz[gala])
      std::swap(gala, galb);
    st.push_back({gala, galb, sz[gala], sz[galb], timestamp});
    sz[galb] += sz[gala];
    mult[gala] = galb;
  }

  void clear(int timestamp) {
    while(0 < st.size() && timestamp <= st.back().timestamp) {
      Event e = st.back();
      mult[e.x] = e.x;
      mult[e.y] = e.y;
      sz[e.x] = e.szx;
      sz[e.y] = e.szy;
      st.pop_back();
    }
  }
};
int const nmax = 500000;

struct Edge{
  int x;
  int y;
  int timestamp;
  int day;
};

std::vector<std::vector<std::pair<int,int>>> aint;

void update(int node, int from, int to, int x, int y, std::pair<int,int> edge) {
  if(x == from && to == y)
    aint[node].push_back(edge);
  else {
    int mid = (from + to) / 2;
    if(x <= mid)
      update(node * 2, from, mid, x, std::min(mid, y), edge);
    if(mid + 1 <= y)
      update(node * 2 + 1, mid + 1, to, std::max(mid + 1, x), y, edge);
  }
}

std::vector<int> queries[1 + nmax * 4];

void query(int node, int from, int to, Dsu &dsu) {
  for(int h = 0; h < aint[node].size(); h++)
    dsu.unite(aint[node][h].first, aint[node][h].second, node);
  if(from < to) {
    int mid = (from + to) / 2;
    query(node * 2, from, mid, dsu);
    query(node * 2 + 1, mid + 1, to, dsu);
  } else
    for(int h = 0; h < queries[from].size(); h++)
      std::cout << dsu.sz[dsu.jump(queries[from][h])] << '\n';
  dsu.clear(node);
}


int main() {
  int n, q, k;
  std::cin >> n >> q >> k;
  aint.resize(1 + 4 * q);
  
  int day = 1;
  
  std::vector<Edge> events;
  std::vector<int> ending(1 + q);

  for(int i = 1;i <= q; i++) {
    int t;
    std::cin >> t;
    if(t == 1) {
      int x, y;
      std::cin >> x >> y;
      events.push_back({x, y, i, day});
    } else if(t == 2) {
      int x;
      std::cin >> x;
      queries[i].push_back(x);
    } else {
      ending[day] = (i - 1);
      day++;
    }
  }
  ending[day] = q;
  for(int i = 0; i < events.size(); i++)
    if(events[i].day <= day - k)
      update(1, 1, q, events[i].timestamp, ending[events[i].day + k - 1], {events[i].x, events[i].y});
    else
      update(1, 1, q, events[i].timestamp, q, {events[i].x, events[i].y});
  
  Dsu dsu(n);
  query(1, 1, q, dsu);
  return 0;
}