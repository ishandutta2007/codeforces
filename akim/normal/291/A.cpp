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
int x[100100];
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int n,i,o=0;scanf("%d",&n);
 for(i=0;i<n;i++){scanf("%d",&x[i]);}
 sort(&x[0],&x[n]);
 for(i=1;i<n;i++)
 {
  if(x[i]==0){continue;}
  if(x[i]==x[i-1]){o++;}
  if(x[i]==x[i-2]){printf("-1");return(0);}
 }
 printf("%d",o);
}