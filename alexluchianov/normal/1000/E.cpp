#include <iostream>
#include <vector>

using namespace std;

#define MIN(a , b) (((a) < (b)) ? (a) : (b))
#define MAX(a , b) (((a) < (b)) ? (b) : (a))

int const nmax = 600000;

vector<int> g[5 + nmax];

int level[5 + nmax];
int euler[5 + 2 * nmax];
int pos[5 + nmax];

int eulerp = 0;

void computeall(int node , int parent){
  euler[++eulerp] = node;
  pos[node] = eulerp;

  level[node] = level[parent] + 1;

  for(int h = 0 ; h < g[node].size() ; h++){
    int to = g[node][h];
    if(to != parent)
      computeall(to , node);

    euler[++eulerp] = node;
  }
}

int jump[5 + nmax];

int jumps(int a) {
  if(jump[a] != a)
    jump[a] = jumps(jump[a]);
  return jump[a];
}

void unite(int x , int y){
  x = jumps(x);
  y = jumps(y);
  if(x != y)
    jump[x] = y;
}

int rmq[25][5 + 2 * nmax];

void computermq(){
  for(int i = 1 ; i <= eulerp ; i++)
    rmq[0][i] = euler[i];

  for(int h = 1 ; h <= 20 ; h++)
    for(int i = 1 ; i <= eulerp - (1 << h) + 1 ; i++){
      int nodex = rmq[h - 1][i];
      int nodey = rmq[h - 1][i + (1 << (h - 1))];
      if(level[nodex] < level[nodey])
        rmq[h][i] = nodex;
      else
        rmq[h][i] = nodey;
    }
}

int lg[5 + 2 * nmax];

int getlca(int x , int y){
  x = pos[x];
  y = pos[y];
  if(y < x)
    swap(x , y);

  int h = lg[y - x];
  int nodex = rmq[h][x];
  int nodey = rmq[h][y - (1 << h) + 1];
  if(level[nodex] < level[nodey])
    return nodex;
  else
    return nodey;
}

int spec[5 + nmax][2];

int val[5 + nmax];

void computevalue(int node , int parent){
  for(int h = 0 ; h < g[node].size() ; h++){
    int to = g[node][h];
    if(to != parent) {
      computevalue(to , node);
      val[node] += val[to];
    }
  }
}

int supremedfs(int node ,int parent , int &smax){
  int smax2 = 0;

  for(int h = 0 ;h < g[node].size() ; h++){
    int to = g[node][h];
    if(to != parent){
      int result2 = supremedfs(to , node , smax);
      smax = MAX(smax , smax2 + result2);
      smax2 = MAX(smax2 , result2);
    }
  }

  return smax2 + val[node];
}
int main()
{

  for(int i = 2 ; i <= 2 * nmax ; i++)
    lg[i] = lg[i / 2] + 1;
  int n , m;
  cin >> n >> m;
  int x , y;

  for(int i = 1 ; i <= n ; i++)
    jump[i] = i;

  for(int i = 1 ; i <= m ; i++){
    cin >> x >> y;

    if(jumps(x) != jumps(y)){
      unite(x , y);
      g[x].push_back(y);
      g[y].push_back(x);
    } else {
      spec[i][0] = x;
      spec[i][1] = y;
    }
  }
  computeall(1 , 0);
  computermq();

  for(int i = 1 ; i <= m ; i++){
    if(0 < spec[i][0]){
      val[spec[i][0]]++;
      val[spec[i][1]]++;
      val[getlca(spec[i][0] , spec[i][1])] -= 2;
      //cout << getlca(spec[i][0] , spec[i][1]) << '\n';
    }
  }
  val[1]++;
  computevalue(1 , 0);

  for(int i = 1 ; i <= n ; i++)
    val[i] = !val[i];


  int smax = 0;
  supremedfs(1 , 0 , smax);
  cout << smax;
  return 0;
}