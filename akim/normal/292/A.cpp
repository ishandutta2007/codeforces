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
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 long long n,ts=0,os=0,ot=0;
 scanf("%I64d",&n);
 for(;n>0;n--)
 {long long t,c;
  scanf("%I64d%I64d",&t,&c);
  os=max(t>=ot?c:c+ot-t,os);
  ot=max(t,ot)+c;
 }
 printf("%I64d %I64d",ot,os);
}