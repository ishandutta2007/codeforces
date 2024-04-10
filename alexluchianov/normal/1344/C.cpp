#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

using ll = long long;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))

int const nmax = 200000;
vector<int> g[1 + nmax], g2[1 + nmax];
int seen[1 + nmax], in_stack[1 + nmax];

void dfs(int node){
  seen[node] = 1;
  in_stack[node] = 1;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(seen[to] == 0)
      dfs(to);
    else if(in_stack[to] == 1){
      cout << -1;
      exit(0);
    }
  }
  in_stack[node] = 0;
}

int dpg[1 + nmax], dpg2[1 + nmax];

void pressdp(int node){
  dpg[node] = 1;
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(dpg[to] == 0)
      pressdp(to);
  }
}

void pressdp2(int node){
  dpg2[node] = 1;
  for(int h = 0; h < g2[node].size(); h++){
    int to = g2[node][h];
    if(dpg2[to] == 0)
      pressdp2(to);
  }
}

char sol[1 + nmax];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  for(int i = 1; i <= m; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g2[y].push_back(x);
  }
  for(int i = 1;i <= n; i++)
    if(seen[i] == 0)
      dfs(i);
  int result = 0;
  for(int i = 1; i <= n; i++){
    if(0 == dpg[i] && 0 == dpg2[i]){
      result++;
      sol[i] = 'A';
    } else
      sol[i] = 'E';
    if(0 == dpg[i])
      pressdp(i);
    if(0 == dpg2[i])
      pressdp2(i);
  }
  cout << result << '\n';
  for(int i = 1;i <= n; i++)
    cout << sol[i];
  return 0;
}