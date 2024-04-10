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
long long x[100100];
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 long long n,lh=0,i,m;
 scanf("%I64d",&n);
 for(i=0;i<n;i++){scanf("%I64d",&x[i]);}
 scanf("%I64d",&m);
 for(i=0;i<m;i++)
 {long long w,h;
  scanf("%I64d%I64d",&w,&h);
  long long o=max(lh,x[w-1]);
  printf("%I64d\n",o);
  lh=o+h;
 }
}