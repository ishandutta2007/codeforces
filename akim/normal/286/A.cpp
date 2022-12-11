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
int x[100100]={0};
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int n,i;
 scanf("%d",&n);
 if(n%4==2||n%4==3){printf("-1");return(0);}
 for(i=1;i<n/2;i+=2)
 {
  x[i]=i+1;
  x[i+1]=n-i+1;
  x[n-i+1]=n-i;
  x[n-i]=i;
 }
 if(n%2==1){x[n-n/2]=n-n/2;}
 for(i=1;i<=n;i++){printf("%d ",x[i]);}
}