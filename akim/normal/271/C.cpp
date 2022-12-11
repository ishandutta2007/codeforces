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
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int n,m,i;
 scanf("%d%d",&n,&m);
 if(n<m*3){printf("-1");return(0);}
 for(i=1;i<=m;i++){printf("%d %d ",i,i);n-=2;}
 for(i=0;i<n;i++){printf("%d ",i%m+1);}
}