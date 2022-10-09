#include <iostream>
#include <vector>

using namespace std;

int const nmax = 200000;
int const maskmax = (1 << 21);
int n;
#define ll long long

vector<int> g[5 + nmax];
char cost[5 + nmax];
int sz[1 + nmax]; //size in terms of number of nodes
int scount[5 + maskmax];
int delnode[1 + nmax];
ll sol[1 + nmax];

void computenodesize(int node, int parent) {
  sz[node] = 1;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent && delnode[to] == 0) {
      computenodesize(to, node);
      sz[node] += sz[to];
    }
  }
}

int getcentroid(int node, int parent, int totnodes) {
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent && delnode[to] == 0 && totnodes / 2 < sz[to])
      return getcentroid(to, node, totnodes);
  }
  return node;
}

void dfscount(int node, int parent, int mask, int sadd) {
  scount[mask] += sadd;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent && delnode[to] == 0)
      dfscount(to, node, mask ^ (1 << cost[to]), sadd);
  }
}

//mask-ul asta este prefixul verde + masca regelui
ll computesol(int node, int parent, int mask ,int p ) {
  ll ans = 0;
  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    if(to != parent && delnode[to] == 0)
      ans += computesol(to, node, mask ^ (1 << cost[to]) , p);
  }
  if(p == 0){
    int mask2 = mask ; //de asta am nevoie in sufix
    ans += scount[mask2];

    for(int j = 0; j < 20; j++) {
      ans += scount[mask2 ^ (1 << j)];
    }
  } else{
    for(int j = 0; j < 20; j++) {
      ans += (mask == (1 << j));
    }
    ans += (mask == 0);
  }
  sol[node] += ans; //contorizezi pentru nodul din care pleaca drumul
  return ans;
}

void decompose(int node) {  //va fi apelata recursiv
  computenodesize(node, -1);
  int cent = getcentroid(node, -1, sz[node]);

  //rezolvam problema, deocamdata fa abstractie de faptul ca este centroidul arborelui
  int centmask = (1 << cost[cent]);

  dfscount(cent, -1, centmask, 1);

  //pentru partea urmatoare vezi E1


  ll soladd = 0;
  scount[centmask]--;
  for(int h = 0; h < g[cent].size(); h++) {
    int to = g[cent][h];
    if(delnode[to] == 0){
      dfscount(to, cent, centmask ^ (1 << cost[to]), -1);

      soladd += computesol(to, cent, (1 << cost[to]) , 0);
      //la computesol am scos centmask, pentru ca aici facem partea verde;

      dfscount(to, cent, centmask ^ (1 << cost[to]), 1);
    }
  }
  sol[cent] += soladd / 2;
  computesol(cent , cent , centmask , 1);

  dfscount(cent, -1, centmask, -1);

  scount[centmask]++;

  delnode[cent] = 1;
  for(int h = 0; h < g[cent].size(); h++) {
    int to = g[cent][h];
    if(delnode[to] == 0)
      decompose(to);
  }
}

int main() {
  cin >> n;
  for(int i = 1;i < n ;i++){
    int a , b;
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for(int i = 1 ; i <= n;i++){
    cin >> cost[i];
    cost[i] -= 'a';
  }
  decompose(1 );
  cout << '\n';
  for(int i = 1 ; i <= n ;i++)
    cout << sol[i] << " ";
  return 0;
}