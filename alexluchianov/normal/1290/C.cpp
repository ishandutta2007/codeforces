#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;
int const nmax = 300000;

namespace Dsu{
  vector<int> mult;
  vector<int> acc;
  vector<int> cost0, cost1;
  vector<int> forced;
  void initialize(int n){
    mult.resize(1 + n);
    acc.resize(1 + n);
    cost0.resize(1 + n);
    cost1.resize(1 + n);
    forced.resize(1 + n);
    for(int i = 1;i <= n; i++) {
      mult[i] = i;
      acc[i] = 0;
      cost1[i] = 1;
      forced[i] = -1;
    }
  }
  int jump(int gala){
    if(gala != mult[gala]){
      int parent = mult[gala];
      jump(parent);
      acc[gala] ^= acc[parent];
      mult[gala] = mult[parent];
    }
    return mult[gala];
  }

  void unite(int gala, int galb, int edge){
    if(jump(gala) == jump(galb))
      return ;
    edge ^= acc[gala] ^ acc[galb];

    gala = jump(gala);
    galb = jump(galb);

    mult[gala] = galb;
    acc[gala] = edge;
    if(edge == 0) {
      cost0[galb] += cost0[gala];
      cost1[galb] += cost1[gala];
    } else {
      cost0[galb] += cost1[gala];
      cost1[galb] += cost0[gala];
    }

    if(0 <= forced[gala]) {
      if(edge == 0)
        forced[galb] = forced[gala];
      else
        forced[galb] = forced[gala] ^ 1;
    }
  }

  int getcost(int gala){
    gala = jump(gala);
    if(-1 == forced[gala])
      return MIN(cost0[gala], cost1[gala]);
    else if(0 == forced[gala])
      return cost0[gala];
    else
      return cost1[gala];
  }

  void force(int gala, int val){
    jump(gala);
    val ^= acc[gala];
    forced[jump(gala)] = val;
  }
};
char s[1 + nmax];
vector<int> links[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;
  for(int i = 1;i <= n; i++)
    cin >> s[i];
  for(int i = 1;i <= k; i++){
    int m;
    cin >> m;
    for(int j = 1;j <= m; j++){
      int x;
      cin >> x;
      links[x].push_back(i);
    }
  }
  Dsu::initialize(k);
  int result = 0;
  for(int i = 1;i <= n; i++){
    if(links[i].size() == 1) {
      result -= Dsu::getcost(links[i][0]);
      Dsu::force(links[i][0], 1 - (s[i] - '0'));
      result += Dsu::getcost(links[i][0]);
    } else if(links[i].size() == 2){
      int x = links[i][0];
      int y = links[i][1];
      if(Dsu::jump(x) != Dsu::jump(y)) {
        result -= Dsu::getcost(x) + Dsu::getcost(y);
        Dsu::unite(x, y, 1 - (s[i] - '0'));
        result += Dsu::getcost(x);
      }
    }
    cout << result << '\n';
  }
  return 0;
}