#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#define maxn 300005
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = getchar();c < '0' || c > '9';c = getchar()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res * sig;
}
int n,type[maxn],par[maxn];
vector <int> chi[maxn];
int f[maxn],leaf[maxn];
void dfs_leaf(int u){
  if(!chi[u].size()) leaf[u] = 1;
  for(int i = 0;i < (int)chi[u].size();i++){
    int v = chi[u][i];
    if(v == par[u]) continue;
    dfs_leaf(v);
    leaf[u] += leaf[v];
  }
}
void dfs(int u){
  if(!chi[u].size()) f[u] = 1;
  else if(type[u] == 0){
    for(int i = 0;i < (int)chi[u].size();i++){
      int v = chi[u][i];
      if(v == par[u]) continue;
      dfs(v);
      f[u] += f[v] - 1;
    }
    f[u]++;
  }else{
    int mincst = inf;
    for(int i = 0;i < (int)chi[u].size();i++){
      int v = chi[u][i];
      if(v == par[u]) continue;
      dfs(v);
      mincst = min(mincst,leaf[v] - f[v]);
    }
    f[u] = leaf[u] - mincst;
  }
}
int main(){
  n = getint();
  for(int i = 1;i <= n;i++) type[i] = getint();
  for(int i = 2;i <= n;i++){
    par[i] = getint();
    chi[par[i]].push_back(i);
  }
  dfs_leaf(1);
  dfs(1);
  printf("%d\n",f[1]);
  return 0;
}