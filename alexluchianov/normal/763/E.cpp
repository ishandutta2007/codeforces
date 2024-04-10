#include <iostream>
#include <vector>

using ll = long long;

int const nmax = 100000;
int const kmax = 5;

std::vector<int> g[5 + nmax];

class Dsu{
private:
  struct Event{
    int x;
    int y;
    int szx;
    int szy;
    int timestamp;
  };
  std::vector<int> mult;
  std::vector<int> sz;
  std::vector<Event> st;
public:
  Dsu(int n) {
    mult.resize(1 + n);
    sz.resize(1 + n);
    for(int i = 1;i <= n; i++) {
      mult[i] = i;
      sz[i] = 1;
    }
  }
  int jump(int gala) {
    if(mult[gala] != gala)
      return jump(mult[gala]);
    return gala;
  }

  int unite(int gala, int galb, int timestamp) {
    gala = jump(gala);
    galb = jump(galb);
    if(gala == galb)
      return 0;
    if(sz[gala] < sz[galb])
      std::swap(gala, galb);

    st.push_back({gala, galb, sz[gala], sz[galb], timestamp});
    mult[galb] = gala;
    sz[gala] += sz[galb];
    sz[galb] = 0;
    return 1;
  }

  void revert(int timestamp) {
    while(0 < st.size() && timestamp < st.back().timestamp) {
      mult[st.back().x] = st.back().x;
      mult[st.back().y] = st.back().y;
      sz[st.back().x] = st.back().szx;
      sz[st.back().y] = st.back().szy;
      st.pop_back();
    }
  }
};

int sol[5 + nmax];

struct Query{
  int x;
  int y;
  int id;
};

int ansLeft[5 + nmax], stateLeft[5 + nmax][1 + kmax];
int ansRight[5 + nmax], stateRight[5 + nmax][1 + kmax];

void divide(int from, int to, std::vector<Query> queries, Dsu &dsu) {
  if(queries.size() == 0)
    return ;
  if(from == to) {
    for(int i = 0; i < queries.size(); i++)
      sol[queries[i].id] = 1;
    return ;
  }
  std::vector<Query> queriesLeft, queriesRight;
  int mid = (from + to) / 2;
  int timestamp = 0;
  
  int ans = 0;
  for(int i = mid; from <= i; i--) {
    ++ans;
    for(int h = 0; h < g[i].size(); h++) {
      int target = g[i][h];
      if(i <= target && target <= mid)
        ans -= dsu.unite(i, target, ++timestamp);
    }
    ansLeft[i] = ans;
    for(int j = 0; j <= kmax; j++)
      if(i <= mid - j)
        stateLeft[i][j] = dsu.jump(mid - j);
      else
        stateLeft[i][j] = 0;
  }

  ans = 0;
  for(int i = mid + 1; i <= to; i++) {
    ++ans;
    for(int h = 0; h < g[i].size(); h++) {
      int target = g[i][h];
      if(mid + 1 <= target && target <= i)
        ans -= dsu.unite(target, i, ++timestamp);
    }
    ansRight[i] = ans;
    for(int j = 0; j <= kmax; j++)
      if(mid + 1 + j <= i)
        stateRight[i][j] = dsu.jump(mid + 1 + j);
      else
        stateRight[i][j] = 0;
  }
  
  dsu.revert(0);

  for(int i = 0;i < queries.size(); i++) {
    int x = queries[i].x;
    int y = queries[i].y;
    int id = queries[i].id;

    if(y <= mid)
      queriesLeft.push_back(queries[i]);
    else if(mid + 1 <= x)
      queriesRight.push_back(queries[i]);
    else {
      sol[id] = ansLeft[x] + ansRight[y];

      for(int j = 0; j <= kmax; j++) {
        int node = mid - j;
        int val = stateLeft[x][j];
        if(0 < val) {
          dsu.unite(node, val, ++timestamp);
        }
      }
      
      for(int j = 0; j <= kmax; j++) {
        int node = mid + 1 + j;
        int val = stateRight[y][j];
        if(0 < val) {
          dsu.unite(node, val, ++timestamp);
        }
      }

      for(int j = 0; j <= kmax; j++) {
        int node = mid - j;
        if(x <= node) {
          for(int h = 0; h < g[node].size(); h++) {
            int target = g[node][h];
            if(mid + 1 <= target && target <= y) {
              sol[id] -= dsu.unite(node, target, ++timestamp);
            }
          }
        }
      }
      dsu.revert(0);
    }
  }

  divide(from, mid, queriesLeft, dsu);
  divide(mid + 1, to, queriesRight, dsu);
}

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, k, m;
  std::cin >> n >> k >> m;
  for(int i = 1;i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  Dsu dsu(n);
  int q;
  std::cin >> q;
  std::vector<Query> queries;
  for(int i = 1;i <= q; i++) {
    int x, y;
    std::cin >> x >> y;
    queries.push_back({x, y, i});
  }
  divide(1, n, queries, dsu);
  for(int i = 1;i <= q; i++)
    std::cout << sol[i] << '\n';
  return 0;
}