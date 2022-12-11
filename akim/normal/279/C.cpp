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
int x[100100]={0},y[100100]={0},z[100100]={0};
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int n,m,i,q,f;
 scanf("%d%d",&n,&m);
 for(i=1;i<=n;i++){scanf("%d",&x[i]);}
 i=1;q=0;
 while(i<=n)
 {q++;
  while(i<=n&&x[i]>=x[i-1]){y[i]=q;i++;}
  while(i<=n&&x[i]<=x[i-1]){y[i]=q;i++;}
  f=i-2;z[f+1]=1;
  while(f>0&&x[f]==x[f+1]){z[f]=1;f--;}
 }
 for(i=0;i<m;i++)
 {int l,r;
  scanf("%d%d",&l,&r);
  if(y[l]==y[r]||(y[l]+1==y[r]&&z[l]==1)){printf("Yes\n");}else{printf("No\n");}
 }
}