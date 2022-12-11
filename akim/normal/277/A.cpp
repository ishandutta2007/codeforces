#include <algorithm>
#include <iostream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define abs(a) ((a)<0?-(a):(a))
int pms[200]={0},pmy[200]={0};
vector<int> st[200];
vector<int> yz[200];
void dfs(int u)
{int i;
 pms[u]=1;
 for(i=0;i<st[u].size();i++)
 if(pmy[st[u][i]]==0)
       {int v=st[u][i];

        int i;
        pmy[v]=1;
        for(i=0;i<yz[v].size();i++)
        if(pms[yz[v][i]]==0){dfs(yz[v][i]);}
        
       
       }
}
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int n,m,i,f;bool log=0;
 scanf("%d%d",&n,&m);
 for(i=0;i<n;i++)
 {int p;
  scanf("%d",&p);if(p!=0){log=1;}
  for(f=0;f<p;f++)
  {int y;
   scanf("%d",&y);
   st[i].pb(y);
   yz[y].pb(i);
  }
 }
 if(log==0){printf("%d",n);return(0);}
 int q=-1;
 for(i=0;i<n;i++)
 if(pms[i]==0)
 {dfs(i);q++;}
 printf("%d",q);
}