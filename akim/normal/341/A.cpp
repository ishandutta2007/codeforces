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
long long x[100100];
long long gcd(long long x,long long y)
{while(x>0){y%=x;swap(x,y);}
 return(y);
}
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 long long n,o=0,ps=0,i;
 scanf("%I64d",&n);
 for(i=0;i<n;i++)
 {scanf("%I64d",&x[i]);o+=x[i];
 }
 sort(&x[0],&x[n]);
 for(i=0;i<n;i++)
 {o+=(x[i]*i-ps)*2;
  ps+=x[i];
  cerr<<1;
 }
 printf("%I64d %I64d",o/gcd(o,n),n/gcd(o,n));
}