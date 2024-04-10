#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <utility>
#define maxn 200005
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = getchar();c < '0' || c > '9';c = getchar()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = getchar()) res = res * 10 + (c - '0');
  return res * sig;
}
int n;
ll ans;
vector <P> adj[maxn];
int f[4][maxn],tmp[4][maxn];
bool leaf[maxn];
void dfs(int u,int fa){
  for(int i = 0;i < (int)adj[u].size();i++){
    int v = adj[u][i].first, w = adj[u][i].second;
    if(v == fa) continue;
    dfs(v,u);
    for(int j = 0;j < 4;j++) tmp[j][v] = -f[j][u];
    if(w == 0){
      f[0][u]++;
      if(!leaf[v]){
        f[0][u] += f[0][v];
        f[2][u] += f[1][v] + f[2][v];
      }
    }else{
      f[1][u]++;
      if(!leaf[v]){
        f[1][u] += f[1][v];
        f[3][u] += f[0][v] + f[3][v];
      }
    }
    for(int j = 0;j < 4;j++) tmp[j][v] += f[j][u];
  }
  if(!leaf[u]){
    for(int i = 0;i < (int)adj[u].size();i++){
      int v = adj[u][i].first;
      if(v == fa) continue;
      ans += (ll)tmp[0][v] * (f[0][u] - tmp[0][v]);
      ans += (ll)tmp[0][v] * (f[1][u] - tmp[1][v]);
      ans += (ll)tmp[0][v] * (f[2][u] - tmp[2][v]);
      ans += (ll)tmp[1][v] * (f[1][u] - tmp[1][v]);
      ans += (ll)tmp[3][v] * (f[1][u] - tmp[1][v]);
    }
    ans += f[0][u] + f[1][u] + f[2][u];
    ans += f[0][u] + f[1][u] + f[3][u];
  }
}
int main(){
  n = getint();
  for(int i = 1;i < n;i++){
    int u = getint(), v = getint(), w = getint();
    adj[u].push_back(mp(v,w));
    adj[v].push_back(mp(u,w));
  }
  for(int i = 2;i <= n;i++){
    if((int)adj[i].size() == 1) leaf[i] = true;
  }
  dfs(1,-1);
  printf("%I64d\n",ans);
  return 0;
}