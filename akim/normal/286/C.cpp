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
int x[1000100]={0},o[1000100]={0};
bool b[1000100]={0};
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int n,i,m;
 scanf("%d",&n);
 for(i=1;i<=n;i++){scanf("%d",&x[i]);}
 scanf("%d",&m);
 for(i=0;i<m;i++){int k;scanf("%d",&k);b[k]=1;}
 int q=0;
 for(i=n;i>0;i--)
 {if(b[i]==1){o[q++]=x[i];continue;}
  if(q>0&&o[q-1]==x[i]){q--;continue;}
  o[q++]=x[i];b[i]=1;
 }
 if(q>0){printf("NO\n");return(0);}
 printf("YES\n");
 for(i=1;i<=n;i++)
 {
  if(b[i]){printf("-");}
  printf("%d ",x[i]);
 }
}