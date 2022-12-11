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
long long x[100100]={0};
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 long long n,t,i;
 scanf("%I64d%I64d",&n,&t);
 for(i=0;i<n;i++){scanf("%I64d",&x[i]);}x[n]=2000000000ll;
 long long l,r=-1,vr=0,mk=0;;
 for(l=0;l<n;l++)
 {
  while(r<n&&vr<=t){r++;vr+=x[r];}
  mk=max(mk,r-l);//printf("%I64d %I64d\n",r,l);
  vr-=x[l];
 }
 printf("%I64d",mk);
}