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
pair<long long,long long> x[100100];
void qsort(int l,int r)
{
 int i=l,f=r;
 pair<long long,long long> p=x[(l+r)/2];
 while(l<f)
 {
  while(x[i]<p){i++;}
  while(x[f]>p){f--;}
  if(i<=f){
           swap(x[i],x[f]);
           i++;f--;
          }
 }
 if(l<f){qsort(l,f);}
 if(i<r){qsort(i,r);}
}
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int n,i;
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  long long p1,p2;
  scanf("%I64d%I64d",&p1,&p2);
  x[i]=mp(p1,p2);
 }
// qsort(0,n-1);
 long long ost=0;
 for(i=1;i<=n;i++)
 {long long st=4,nst=1;
  while(x[i].sc>st){st=st*4ll;nst++;}
  if(x[i].fs+nst>ost){ost=x[i].fs+nst;}
 }
 printf("%d",ost);
}