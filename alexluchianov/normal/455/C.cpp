#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 300000;
vector<int> g[1 + nmax];
int mult[1 + nmax], sz[1 + nmax], seen[1 + nmax];

int jump(int a){
  if(a != mult[a])
    mult[a] = jump(mult[a]);
  return mult[a];
}

void unite(int gala, int galb){
  gala = jump(gala);
  galb = jump(galb);
  if(gala != galb){
    mult[gala] = galb;
    int newdiam = MAX(MAX(sz[gala], sz[galb]), sz[gala] / 2 + sz[gala] % 2 + sz[galb] / 2 + sz[galb] % 2 + 1);
    sz[galb] = newdiam;
  }
}

int farthest = 0, dist = 0;

void dfs(int node, int parent,int acc){
  seen[node] = 1;
  if(dist < acc){
    dist = acc;
    farthest = node;
  }
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent)
      dfs(to, node, acc + 1);
  }
}

int getdiam(int node){
  farthest = dist = 0;
  dfs(node, 0, 0);
  int start = farthest;
  farthest = dist = 0;
  dfs(start   , 0, 0);
  return dist;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, q;
  cin >> n >> m >> q;
  for(int i = 1;i <= n; i++) {
    mult[i] = i;
  }

  for(int i = 1;i <= m; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    unite(x, y);
  }
  for(int i = 1;i <= n; i++) {
    if(seen[i] == 0) {
      sz[jump(i)] = getdiam(i);
    }
  }
  for(int i = 1;i <= q; i++){
    int op;
    cin >> op;
    if(op == 1){
      int x;
      cin >> x;
      cout << sz[jump(x)] << '\n';
    } else {
      int x, y;
      cin >> x >> y;
      unite(x, y);
    }
  }
  return 0;
}