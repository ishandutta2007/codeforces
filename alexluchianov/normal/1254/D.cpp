#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;
int const nmax = 150000;
int const sqr = 200;
int const modulo = 998244353;

class ModuloRing{
private:
  void gcd(int a, int b, int &x, int &y){
    if(b == 0){
      x = 1;
      y = 0;
    } else {
      gcd(b, a % b, x, y);
      int aux = x;
      x = y;
      y = aux - a / b * y;
    }
  }
public:
  int number;
  ModuloRing (int number_ = 0){
    this->number = number_ % modulo;
  }
  ModuloRing (ll number_){
    this->number = number_ % modulo;
  }
  ModuloRing operator + (ModuloRing const &a) {
    return (number + a.number);
  }
  ModuloRing operator - (ModuloRing const &a) {
    return (modulo + number - a.number);
  }
  ModuloRing operator * (ModuloRing const &a) {
    return (1LL * number * a.number);
  }
  ModuloRing operator / (ModuloRing const &a) {
    int x, y;
    gcd(a.number, modulo, x ,y);
    x %= modulo;
    if(x < 0)
      x += modulo;
    return 1LL * number * x;
  }
};

class BSarray{
private:
  int n;
  int sqr;
  vector<ModuloRing> v;
  vector<ModuloRing> sum;
public:
  BSarray(int n_ = 0){
    n = n_;
    sqr = sqrt(n);
    v.resize(1 + n);
    sum.resize(1 + n);
  }

  void update(int pos, ModuloRing val){
    if(n < pos)
      return ;
    if(val.number < 0)
      val.number += modulo;

    v[pos] = v[pos] + val;

    int ptr = 1 + (pos - 1) / sqr;
    sum[ptr] = sum[ptr] + val;
  }

  ModuloRing query(int pos){
    ModuloRing result;
    int start = 1, ptr = 1;
    while(start + sqr < pos){
      result = result + sum[ptr];
      start += sqr;
      ptr++;
    }
    while(start <= pos){
      result = result + v[start];
      start++;
    }
    return result;
  }
};

vector<int> g[1 + nmax];
ModuloRing bonus[1 + sqr];
int era = 0;
int group[1 + sqr][1 + nmax];
int sz[1 + sqr][1 + nmax];

int hard[1 + nmax];

int n;
void dfs(int node, int parent, int id){
  group[era][node] = id;
  sz[era][id]++;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent) {
      dfs(to, node, id);
    }
  }
}

void initialize(int node){
  hard[node] = ++era;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    dfs(to, node, h);
  }
  group[era][node] = g[node].size();
  sz[era][g[node].size()] = 0;
}

void updatehard(int node, int val){
  bonus[hard[node]] = bonus[hard[node]] + val;
}

ModuloRing queryhard(int node){
  ModuloRing result;
  ModuloRing chance = 1;
  chance = chance / n;
  for(int ptr = 1; ptr <= era; ptr++)
    result = result + bonus[ptr] * chance * (n - sz[ptr][group[ptr][node]]);
  return result;
}

int level[1 + nmax], pos[1 + nmax], posend[1 + nmax], euler = 0;
int vanillasz[1 + nmax];

void computelevel(int node, int parent){
  level[node] = level[parent] + 1;
  pos[node] = ++euler;
  vanillasz[node] = 1;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent) {
      computelevel(to, node);
      vanillasz[node] += vanillasz[to];
    }
  }
  posend[node] = ++euler;
}

BSarray arr;

void updatelight(int node, int val){
  ModuloRing chance = 1;
  chance = chance / n;
  arr.update(pos[node], val);
  arr.update(pos[node] + 1, -val);

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(level[node] + 1 == level[to]) {
      arr.update(pos[to], chance * val * (n - vanillasz[to]));
      arr.update(posend[to], chance * -val * (n - vanillasz[to]));
    } else {
      arr.update(1, chance * val * vanillasz[node]);
      arr.update(pos[node], ModuloRing(0) - chance * val * vanillasz[node]);
      arr.update(posend[node], chance * val * vanillasz[node]);
    }
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int q;
  cin >> n >> q;
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i = 1;i <= n; i++) {
    if(n / sqr <= g[i].size())
      initialize(i);
  }
  computelevel(1, 0);
  arr = BSarray(euler);

  for(int i = 1;i <= q; i++){
    int op;
    cin >> op;
    if(op == 1){
      int x, val;
      cin >> x >> val;
      if(hard[x] == 0)
        updatelight(x, val);
      else
        updatehard(x, val);
    } else {
      int node;
      cin >> node;
      cout << (queryhard(node) + arr.query(pos[node])).number << '\n';
    }
  }
  return 0;
}
/*
5 4
1 2
1 3
2 4
2 5
1 1 1
2 2
1 2 2
2 2
*/