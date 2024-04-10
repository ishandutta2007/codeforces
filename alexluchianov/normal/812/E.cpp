#include <iostream>
#include <map>
#include <vector>

using namespace std;

using ll = long long;
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 100000;
vector<int> g[1 + nmax];
int v[1 + nmax];
int level[1 + nmax];

void dfs(int node){
  if(g[node].size() == 0)
    level[node] = 1;

  for(int h = 0; h < g[node].size(); h++) {
    int to = g[node][h];
    dfs(to);
    level[node] = !level[to];
  }
}

map<int,int> frec;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> v[i];
  for(int i = 2;i <= n; i++){
    int p;
    cin >> p;
    g[p].push_back(i);
  }
  dfs(1);
  int xorp = 0, scount = 0;
  for(int i = 1;i <= n; i++)
    if(level[i] == 1) {
      xorp ^= v[i];
      scount++;
    } else
      frec[v[i]]++;

  ll result = 0;
  if(xorp == 0)
    result = 1LL * scount * (scount - 1) / 2 + 1LL * (n - scount) * (n - scount - 1) / 2;

  for(int i = 1;i <= n; i++)
    if(level[i] == 1)
      result += frec[xorp ^ v[i]];

  cout << result;
  return 0;
}