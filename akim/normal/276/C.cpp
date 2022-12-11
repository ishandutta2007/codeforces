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
int x[200200],y[200200];
pair<int,int> z[400400];
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int n,q,i;
 scanf("%d%d",&n,&q);
 for(i=0;i<n;i++){scanf("%d",&x[i]);}
 sort(x,x+n);
 for(i=0;i<q;i++)
 {int u,v;
  scanf("%d%d",&u,&v);
  z[i*2]=(mp(u-1,-1));z[i*2+1]=(mp(v-1,1));
 }
 int sz=q*2;
 sort(z,z+sz);
 int p=0,mn=0;
 for(i=0;i<n;i++)
 {
  while(p<sz&&(z[p].fs<i||(z[p].fs==i&&z[p].sc==-1))){mn+=z[p].sc;p++;}
  y[i]=-mn;
 }
 sort(y,y+n);
 long long otv=0;
 for(i=0;i<n;i++)
 {
  otv+=(long long)y[i]*x[i];
 }
 printf("%I64d",otv);
}