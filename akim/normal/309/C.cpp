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
long long x[40]={0},z[40]={0};
long long y[1001000];
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 long long n,m,o=0,i,f,p;
 scanf("%I64d%I64d",&n,&m);
 for(i=0;i<n;i++){long long k;scanf("%I64d",&k);for(f=0;f<35;f++){x[f]+=k%2;k/=2;}}
 for(i=0;i<m;i++){long long k;scanf("%I64d",&k);z[k]++;}
 for(i=0;i<35;i++)
 {for(f=i,p=1;f<35;f++,p*=2)
  {
   long long k=min(x[f]*p,z[i]),l;
   o+=k;l=(x[f]*p-k)%p;
   x[f]-=((k%p==0)?(k/p):(k/p+1));
   for(int g=i;g<f;g++){x[g]+=l%2;l/=2;}
   z[i]-=k;
  }
 }
 printf("%I64d",o);
}