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
int x[200100]={0},px[1000]={0},py[1000]={0};
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int i,f;
 x[1]=1;
 for(i=2;i<200100;i++)
 if(x[i]==0){for(f=i*2;f<200100;f+=i){x[f]=1;}}
 f=0;
 for(i=200099;i>1;i--)
 {if(x[i]==0){f=0;}x[i]=f;f++;}
 int n,m;
 scanf("%d%d",&n,&m);
 for(i=0;i<n;i++)
 {
  for(f=0;f<m;f++)
  {int p;
   scanf("%d",&p);
   px[i]+=x[p];
   py[f]+=x[p];
  }
 }
 int otv=1000000000;
 for(i=0;i<n;i++){otv=min(otv,px[i]);}
 for(i=0;i<m;i++){otv=min(otv,py[i]);}
 printf("%d",otv);
}