#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define pb push_back
int h[100100]={0},r[200200][2],qv=10,k,x[100100]={0};
bool dfs(int u,int q)
{
 x[u]=q;
 int v=h[u];
 while(v!=0)
 {
  if(x[r[v][0]]==0)
  {
   if(dfs(r[v][0],q+1)){if(qv<=q){cout<<u<<" ";}return(1);}
  }else
  {
   if(q-x[r[v][0]]+1>k){cout<<q-x[r[v][0]]+1<<endl<<u<<" ";qv=x[r[v][0]];return(1);}
  }
  v=r[v][1];
 }
 return(0);
}
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int n,m,i,u,v,q;
 scanf("%d%d%d",&n,&m,&k);
 for(i=0;i<m;i++)
 {
  scanf("%d%d",&u,&v);
  r[i*2+1][0]=u;r[i*2+1][1]=h[v];h[v]=i*2+1;
  r[i*2+2][0]=v;r[i*2+2][1]=h[u];h[u]=i*2+2;
 }
 dfs(1,1);
}