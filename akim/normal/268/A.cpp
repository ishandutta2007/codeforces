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
int x[110]={0},y[110]={0};
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int n,i,l,r,otv;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  scanf("%d%d",&l,&r);
  x[l]++;y[r]++;
 }
 otv=0;
 for(i=0;i<110;i++)
 {
  otv+=x[i]*y[i];
 }
 printf("%d",otv);
}