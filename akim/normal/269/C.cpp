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
int r[200200][4]={0},v[200200]={0},is[200200]={0},h[200200],x[400400][5];
bool pm[200200]={0};
vector<int> vc;
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int n,m,i,f;
 scanf("%d%d",&n,&m);
 for(i=0;i<m;i++)
 {
  scanf("%d%d%d",&r[i][0],&r[i][1],&r[i][2]);
  v[r[i][0]]+=r[i][2];v[r[i][1]]+=r[i][2];
  x[i*2+1][0]=r[i][2];x[i*2+1][1]=r[i][0];x[i*2+1][2]=i;x[i*2+1][3]=h[r[i][1]];h[r[i][1]]=i*2+1;
  x[i*2+2][0]=r[i][2];x[i*2+2][1]=r[i][1];x[i*2+2][2]=i;x[i*2+2][3]=h[r[i][0]];h[r[i][0]]=i*2+2;
 }
 vc.pb(1);i=0;
 while(i<vc.size())
 {
  f=h[vc[i]];
  while(f>0)
  {
   if(r[x[f][2]][3]==0)
   {
    v[x[f][1]]-=x[f][0];
    is[x[f][1]]+=x[f][0];
    if(v[x[f][1]]==is[x[f][1]]||x[f][1]==n)
    {
     if(x[f][1]!=n&&pm[x[f][1]]==0){vc.pb(x[f][1]);}
    }
    if(r[x[f][2]][0]==vc[i]){r[x[f][2]][3]=1;}else{r[x[f][2]][3]=2;}
   }
   f=x[f][3];
  }
  i++;
 }
 for(i=0;i<m;i++)
 {
  printf("%d\n",r[i][3]-1);
 }
}