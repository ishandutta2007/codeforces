#include<bits/stdc++.h>
using namespace std;
const int MAXN = 202020;
int N, M;
bool vis[2*MAXN];
vector<int> conn[2*MAXN];
bool dfs(int a)
{
  if(vis[a]) return false;
  vis[a] = true;
  for(auto x: conn[a]) dfs(x);
  return true;
}
int main()
{
  int N, M, Q;
  scanf("%d%d%d", &N, &M, &Q);
  for(int i=0; i<Q; ++i)
  {
    int u, v; scanf("%d%d", &u, &v);
    u += MAXN;
    conn[u].push_back(v);
    conn[v].push_back(u);
  }
  int cnt = 0;
  for(int i=1; i<=N; ++i)
    if(dfs(MAXN+i)) ++cnt;
  for(int i=1; i<=M; ++i)
    if(dfs(i)) ++cnt;
  printf("%d\n", cnt-1);
  return 0;
}