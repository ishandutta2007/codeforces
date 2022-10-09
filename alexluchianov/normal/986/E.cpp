#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <bitset>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;

int const nmax = 200000;
int const valmax = 10000000;
int const modulo = 1000000007;
int const lgmax = 20;
vector<int> g[1 + nmax];
int pos[1 + nmax], posend[1 + nmax], euler = 0;
int far[1 + lgmax][1 + nmax], level[1 + nmax];

void dfs(int node, int parent){
  far[0][node] = parent;
  level[node] = level[parent] + 1;

  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to == parent)
      g[node].erase(g[node].begin() + h);
  }
  pos[node] = ++euler;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    dfs(to, node);
  }
  posend[node] = ++euler;
}

void computefar(int n){
  for(int h = 1; h < lgmax; h++)
    for(int i = 1;i <= n; i++)
      far[h][i] = far[h - 1][far[h - 1][i]];
}

class FenwickTree{
private:
  int n;
  vector<int> aib;
public:
  FenwickTree(int n){
    this->n = n;
    aib.resize(1 + n);
  }
  void update(int x, int val){
    while(x <= n){
      aib[x] += val;
      x += (x ^ (x & (x - 1)));
    }
  }
  int query(int x){
    int result = 0;
    while(0 < x){
      result += aib[x];
      x = (x & (x - 1));
    }
    return result;
  }
};

vector<pair<int, int>> updates[1 + valmax];

bitset<1 + nmax> ciur;
vector<int> primes;

void computeprimes(){
  ciur[1] = 1;
  for(int i = 2;i * i <= nmax; i++)
    if(ciur[i] == 0)
      for(int j = i * i; j <= nmax; j += i)
        ciur[j] = 1;
  for(int i = 1;i <= nmax; i++)
    if(ciur[i] == 0)
      primes.push_back(i);
}

vector<pair<int,int>> decompose(int number){
  vector<pair<int,int>> sol;
  for(int i = 0; i < primes.size(); i++){
    int val = primes[i];
    if(val * val <= number){
      int coef = 0;
      while(number % val == 0){
        number /= val;
        coef++;
      }
      if(0 < coef)
        sol.push_back({val, coef});
    } else
      break;
  }
  if(1 < number)
    sol.push_back({number, 1});
  return sol;
}

int getlca(int x, int y){
  if(level[x] < level[y])
    swap(x, y);

  for(int h = lgmax - 1; 0 <= h; h--)
    if(level[y] <= level[x] - (1 << h))
      x = far[h][x];

  if(x == y)
    return x;
  else {
    for(int h = lgmax - 1; 0 <= h; h--)
      if(far[h][x] != far[h][y]){
        x = far[h][x];
        y = far[h][y];
      }
    return far[0][x];
  }
}

struct Query{
  int x;
  int y;
  int exp;
  int id;
  bool operator < (Query const &a) const{
    return exp < a.exp;
  }
};
vector<Query> query[1 + valmax];

int sol[1 + nmax], v[1 + nmax];

int lgpow(int a, int b){
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    int result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return 1LL * result * result % modulo;
    else
      return 1LL * result * result % modulo * a % modulo;
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  dfs(1, 0);
  computefar(n);

  computeprimes();

  for(int i = 1;i <= n; i++) {
    vector<pair<int,int>> dep = decompose(v[i]);
    for(auto& it : dep)
      for(int h = 1; h <= it.second; h++)
        updates[it.first].push_back({h, i});
  }

  for(int i = 1;i <= valmax; i++)
    sort(updates[i].begin(), updates[i].end());

  int q;
  cin >> q;

  for(int i = 1;i <= q; i++){
    int x, y, val;
    cin >> x >> y >> val;
    sol[i] = 1;
    vector<pair<int,int>> dep = decompose(val);
    for(auto& it : dep)
      query[it.first].push_back({x, y, it.second, i});
  }

  for(int i = 1;i <= valmax; i++)
    sort(query[i].begin(), query[i].end());

  FenwickTree aib(euler);

  for(int i = 1;i <= valmax; i++){
    int ptr = 0;
    for(auto& it : query[i]) {
      while(ptr < updates[i].size() && updates[i][ptr].first <= it.exp) {
        aib.update(pos[updates[i][ptr].second], 1);
        aib.update(posend[updates[i][ptr].second], -1);
        ptr++;
      }

      int lca = getlca(it.x, it.y);
      int result = aib.query(pos[it.x]) + aib.query(pos[it.y]) - aib.query(pos[lca]) - aib.query(pos[far[0][lca]]);
      sol[it.id] = 1LL * sol[it.id] * lgpow(i, result) % modulo;
    }
    while(0 < ptr){
      aib.update(pos[updates[i][ptr - 1].second], -1);
      aib.update(posend[updates[i][ptr - 1].second], 1);
      ptr--;
    }
  }

  for(int i = 1;i <= q; i++)
    cout << sol[i] << '\n';
  return 0;
}