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
#define sqr(a) ((a)*(a))
long long x[2000100]={0};
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 long long k=1,p=1,n,i,f;
 scanf("%I64d",&n);
 while(n>p){p*=4;k++;}
 for(i=0;i<n;i++){scanf("%I64d",&x[i]);}
 sort(&x[0],&x[n]);
 long long o=0;p=1;
 for(i=n-1,f=0;i>=0;i--,f++)
 {if(f==p){p*=4;k--;}
  o+=k*x[i];
 }
 printf("%I64d",o);
}