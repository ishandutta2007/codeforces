#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
int n,m,test;
int l,r;
vector<pair<int,int> > g[505];
bool u[505];
int ans=0;
void dfs(int v)
{u[v] = true;
 for (int i = 0; i < (int)g[v].size(); i++)
 {if((g[v][i].second<l||g[v][i].second>r)&&!u[g[v][i].first])dfs(g[v][i].first);}
}
int main() {
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
 scanf("%d %d", &n, &m);
 for (int i = 1; i <= m; i++)
 {
  scanf("%d %d", &l, &r);
  g[l].push_back(make_pair(r, i));
  g[r].push_back(make_pair(l, i));
 }
 scanf("%d", &test);
 for (int i = 1; i <= test; i++)
 {
  scanf("%d %d", &l, &r);
  ans = 0;
  for (int j = 1; j <= n; j++) 
  u[j] = false;
  for (int j = 1; j <= n; j++) 
  if (!u[j])
  {
   ans++;
   dfs(j);
  }
  printf("%d\n", ans);
 }
 return 0;
}