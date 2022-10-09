#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <set>

int const nmax = 1000001;
std::vector<int> primes[5 + nmax];

void computeciur() {
  for(int i = 2;i <= nmax; i++) {
    if(0 == primes[i].size()) {
      for(int j = i; j <= nmax; j += i)
        primes[j].push_back(i);
    }
  }
}

class Dsu{
  private:
    std::vector<int> mult;
  public:
    Dsu(int n) {
      mult.resize(1 + n);
      for(int i = 1; i <= n; i++)
        mult[i] = i;
    }

    int jump(int gala) {
      if(mult[gala] != gala) 
        mult[gala] = jump(mult[gala]);
      return mult[gala];
    }

    void unite(int gala, int galb) {
      gala = jump(gala);
      galb = jump(galb);
      if(gala == galb)
        return ;
      mult[gala] = galb;
    }
    bool connect(int x, int y) {
      return jump(x) == jump(y);
    }
};


int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;
  computeciur();
  std::vector<int> v(1 + n);
  Dsu dsu(nmax);

  for(int i = 1;i <= n; i++) {
    std::cin >> v[i];
    for(int h = 0; h < primes[v[i]].size(); h++) {
      int to = primes[v[i]][h];
      dsu.unite(to, v[i]);
    }
  }

  std::set<std::pair<int,int>> edges;
  for(int i = 1; i <= n; i++) {
    int x = dsu.jump(v[i]);
    for(int h = 0; h < primes[v[i] + 1].size(); h++) {
      int y = dsu.jump(primes[v[i] + 1][h]);
      if(x < y)
        edges.insert({x, y});
      else
        edges.insert({y, x});
    }
    for(int h = 0; h < primes[v[i] + 1].size(); h++)
      for(int h2 = h + 1; h2 < primes[v[i] + 1].size(); h2++) {
        int x = dsu.jump(primes[v[i] + 1][h]);
        int y = dsu.jump(primes[v[i] + 1][h2]);
        if(x < y)
          edges.insert({x, y});
        else
          edges.insert({y, x});


      }
  }

  for(int i = 1;i <= q; i++) {
    int x, y;
    std::cin >> x >> y;
    x = dsu.jump(v[x]);
    y = dsu.jump(v[y]);

    if(y < x)
      std::swap(x, y);

    if(x == y)
      std::cout << 0 << '\n';
    else if(edges.find({x, y}) != edges.end())
      std::cout << 1 << '\n';
    else
      std::cout << 2 << '\n';
  }
  return 0;
}