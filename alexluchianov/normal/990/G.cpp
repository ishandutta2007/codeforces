#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;

int const nmax = 200000;

namespace Dsu{
  vector<int> mult;
  vector<int> sz;
  void initialize(int n){
    mult.resize(1 + n);
    sz.resize(1 + n);
    for(int i = 1;i <= n; i++)
      mult[i] = i;
    for(int i = 1;i <= n; i++)
      sz[i] = 1;
  }
  int jump(int gala){
    if(gala != mult[gala])
      mult[gala] = jump(mult[gala]);
    return mult[gala];
  }
  void unite(int gala, int galb){
    gala = jump(gala);
    galb = jump(galb);
    if(gala == galb)
      return ;
    if(sz[galb] < sz[gala])
      swap(gala, galb);
    sz[galb] += sz[gala];
    mult[gala] = galb;
    sz[gala] = 0;
  }
}

int v[1 + nmax], frec[1 + nmax];
ll sol[1 + nmax];
vector<pair<int,int>> edges[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i <= n; i++) {
    cin >> v[i];
    frec[v[i]]++;
  }

  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    edges[__gcd(v[x], v[y])].push_back({x, y});
  }
  Dsu::initialize(n);

  for(int i = 1; i <= nmax; i++){
    for(int j = i; j <= nmax; j += i)
      sol[i] += frec[j];

    for(int j = i; j <= nmax; j += i)
      for(int h = 0; h < edges[j].size(); h++)
        Dsu::unite(edges[j][h].first, edges[j][h].second);
    ll result = 0;

    for(int j = i; j <= nmax; j += i)
      for(int h = 0; h < edges[j].size(); h++) {
        int x = edges[j][h].first, y = edges[j][h].second;
        result += 1LL * Dsu::sz[x] * (Dsu::sz[x] - 1) / 2;
        Dsu::sz[x] = 1;
        Dsu::mult[x] = x;
        result += 1LL * Dsu::sz[y] * (Dsu::sz[y] - 1) / 2;
        Dsu::sz[y] = 1;
        Dsu::mult[y] = y;
      }

    sol[i] += result;
  }
  for(int i = nmax; 1 <= i; i--)
    for(int j = 2 * i; j <= nmax; j += i)
      sol[i] -= sol[j];

  for(int i = 1;i <= nmax; i++)
    if(0 < sol[i])
      cout << i << " " << sol[i] << '\n';

  return 0;
}