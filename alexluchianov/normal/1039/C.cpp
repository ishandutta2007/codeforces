#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

using ll = long long;

int const nmax = 500000;
int const modulo = 1000000007;

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
  ModuloRing(ll _number=0){
    number = _number % modulo;
  }
  ModuloRing operator + (ModuloRing a) const{
    return number + a.number;
  }
  ModuloRing operator - (ModuloRing a) const{
    return modulo + number - a.number;
  }
  ModuloRing operator * (ModuloRing a) const{
    return 1LL * number * a.number;
  }
  ModuloRing operator / (ModuloRing a) {
    int x, y;
    gcd(a.number, modulo, x, y);
    x %= modulo;
    if(x < 0)
      x += modulo;
    return 1LL * number * x;
  }
};

struct Edge{
  int x;
  int y;
  ll cost;
};
ll v[1 + nmax];
vector<Edge> edges;

map<ll,int> code;

int normalize(){
  vector<ll> temp;
  for(int i = 0; i < edges.size(); i++){
    temp.push_back(edges[i].cost);
  }
  sort(temp.begin(), temp.end());
  temp.erase(unique(temp.begin(), temp.end()), temp.end());
  for(int i = 0; i < temp.size(); i++)
    code[temp[i]] = 1 + i;
  for(int i = 0; i < edges.size(); i++)
    edges[i].cost = code[edges[i].cost];
  return temp.size();
}

ModuloRing lgpow(ModuloRing a, int b){
  if(b == 0)
    return 1;
  else if(b == 1)
    return a;
  else {
    ModuloRing result = lgpow(a, b / 2);
    if(b % 2 == 0)
      return result * result;
    else
      return result * result * a;
  }
}

class Dsu{
private:
  vector<int> mult;
  vector<int> sz;
public:
  Dsu(int n){
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
  }
};

vector<Edge> g[1 + nmax];
map<int,int> id;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  for(int i = 1;i <= n; i++)
    cin >> v[i];
  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    edges.push_back({x, y, v[x] ^ v[y]});
  }
  int lim = normalize();
  for(int i = 0; i < edges.size(); i++)
    g[edges[i].cost].push_back(edges[i]);

  ModuloRing result = 0;
  for(int i = 1;i <= lim; i++){
    Dsu myset(2 * g[i].size());
    int ptr = 0, components = n;
    id.clear();
    for(int h = 0; h < g[i].size(); h++){
      Edge e = g[i][h];
      if(id[e.x] == 0)
        id[e.x] = ++ptr;
      if(id[e.y] == 0)
        id[e.y] = ++ptr;
      e.x = id[e.x];
      e.y = id[e.y];

      if(myset.jump(e.x) != myset.jump(e.y)) {
        myset.unite(e.x, e.y);
        components--;
      }
    }
    result = result + lgpow(2, components);
  }

  result = result + (lgpow(2, k) - lim) * lgpow(2, n);
  cout << result.number;
  return 0;
}