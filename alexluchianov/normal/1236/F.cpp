#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 500000;
const int modulo = 1000000007;

vector<int> g[1 + nmax];

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
  ModuloRing(int number = 0){
    this->number = number;
  }

  ModuloRing operator + (ModuloRing const &a){
    return (number + a.number) % modulo;
  }
  ModuloRing operator * (ModuloRing const &a){
    return (1LL * number * a.number) % modulo;
  }
  ModuloRing operator - (ModuloRing const &a){
    ModuloRing result(number - a.number);
    if(result.number < 0)
      result.number += modulo;
    return result;
  }
  ModuloRing operator / (ModuloRing const &a){
    ModuloRing result = number;
    int x, y;
    gcd(a.number, modulo, x, y);
    x %= modulo;
    if(x < 0)
      x += modulo;
    return result * x;
  }
};

ModuloRing lgpow(ModuloRing a, int b){
  if(b == 0)
    return {1};
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

ModuloRing md(int val){
  return ModuloRing(val);
}

int n, m;

ModuloRing node2(){
  ModuloRing result;
  for(int i = 1;i <= n; i++)
    result = result + md(1) / 2 * (md(1) + md(n - 1) * md(1) / 2);
  return result;
}

vector<pair<int,int>> edge;
vector<int> ginit[1 + nmax];

int seen[1 + nmax];

ModuloRing edge2(){
  ModuloRing result;
  for(int i = 0; i < edge.size(); i++){
    int x = edge[i].first, y = edge[i].second;
    result = result + md(1) / 4 * (md(1) / 4 * (m - ginit[x].size() - ginit[y].size() + 1) + md(1) / 2 * (ginit[x].size() + ginit[y].size() - 2) + 1);

  }
  return result;
}

vector<int> cycle[1 + nmax];

ModuloRing ringsolpart(int id){
  return lgpow(md(1) / 2, cycle[id].size());
}

ModuloRing ringsol(){
  ModuloRing result;
  for(int i = 0; i < m; i++)
    if(seen[i] == 0)
      result = result + ringsolpart(i);
  return result;
}

ModuloRing sumcycle[1 + nmax];

//*
ModuloRing ring2(){
  ModuloRing result;
  ModuloRing defaultsum = ringsol();

  for(int i = 0; i < m; i++)
    if(seen[i] == 0) {
      ModuloRing sum = defaultsum - ringsolpart(i);
      //cout << sum.number << '\n';

      for(int j = 0; j < cycle[i].size(); j++)
        sum = sum - (sumcycle[cycle[i][j]] - ringsolpart(i)) + (sumcycle[cycle[i][j]] - ringsolpart(i)) * 2;
      result = result + ringsolpart(i) * (sum + 1);
    }
  return result;
}

//*/


ModuloRing nodeedge(){
  ModuloRing result;
  for(int i = 1; i <= n; i++){
    result = result + md(1) / 2 * (md(1) / 4 * (m - ginit[i].size()) + md(1) / 2 * ginit[i].size());
  }
  return result * 2;
}

//*

ModuloRing ringedge(){
  ModuloRing result;
  for(int i = 0; i < edge.size(); i++){
    if(seen[i] == 0){
      int sum = 0;
      for(int j = 0; j < cycle[i].size(); j++){
        int x = cycle[i][j];
        sum += ginit[x].size();
      }
      sum -= cycle[i].size();//counted twice
      result = result + ringsolpart(i) * (md(1) / 4 * (m - sum) + md(1) * (cycle[i].size()) + md(1) / 2 * (sum - cycle[i].size()));
    }
  }
  return result * 2;
}

ModuloRing ringnode(){
  ModuloRing result;
  for(int i = 0; i < edge.size(); i++){
    if(seen[i] == 0){
      result = result + ringsolpart(i) * (md(1) * cycle[i].size() + md(1) / 2 * (n - cycle[i].size()) );
    }
  }
  return result * 2;
}
//*/


int mult[1 + nmax];

int far(int a){
  if(a != mult[a])
    mult[a] = far(mult[a]);
  return mult[a];
}

void unite(int gala, int galb){
  gala = far(gala);
  galb = far(galb);
  mult[gala] = galb;
}

int level[1 + nmax], father[1 + nmax];
void dfs(int node, int parent){
  level[node] = level[parent] + 1;
  father[node] = parent;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent)
      dfs(to, node);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  for(int i = 0;i < m; i++){
    int x, y;
    cin >> x >> y;
    edge.push_back({x, y});
    ginit[x].push_back(y);
    ginit[y].push_back(x);
  }
  for(int i = 1;i <= n; i++)
    mult[i] = i;

  for(int i = 0;i < m; i++){
    int x = edge[i].first, y = edge[i].second;
    if(far(x) != far(y)) {
      unite(x, y);
      seen[i] = 1;
      g[x].push_back(y);
      g[y].push_back(x);
    }
  }
  dfs(1, 0);

  for(int i = 0; i < m; i++){
    if(seen[i] == 0){
      int x = edge[i].first, y = edge[i].second;
      while(x != y){
        if(level[x] < level[y]) {
          cycle[i].push_back(y);
          y = father[y];
        } else {
          cycle[i].push_back(x);
          x = father[x];
        }
      }
      cycle[i].push_back(x);

      x = edge[i].first;
      y = edge[i].second;
      while(x != y){
        if(level[x] < level[y]) {
          sumcycle[y] = sumcycle[y] + ringsolpart(i);
          y = father[y];
        } else {
          sumcycle[x] = sumcycle[x] + ringsolpart(i);
          x = father[x];
        }
      }
      sumcycle[x] = sumcycle[x] + ringsolpart(i);

      //cout << cycle[i].size() << '\n';
    }
  }

  ModuloRing ex = md(1) / 2 * n - md(1) / 4 * m + ringsol();
  /*
  cout << "Node: " << (md(1) / 2).number << '\n';
  cout << "Edges: " << (md(1) / 4 * m).number << '\n';
  cout << "Ring: " << ringsol().number << '\n';
  */

  ex = ex * ex;
  /*
  cout << "Node2: " << node2().number << '\n';
  cout << "Edge2: " << edge2().number <<  '\n';
  cout << "Ring2: " << ring2().number << '\n';
  cout << "NodeEdge: " << nodeedge().number << '\n';
  cout << "RingEdge: " << ringedge().number << '\n';
  cout << "RingNode: " << ringnode().number << '\n';
  */

  ModuloRing ex2 = node2() + edge2() + ring2() - nodeedge() - ringedge() + ringnode();

  cout << (ex2 - ex).number ;
  return 0;
}
/*
4 4
1 2
2 3
3 4
4 2
*/