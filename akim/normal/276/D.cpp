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
int x[100]={0},y[100]={0};
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 long long a,b,i;
 scanf("%I64d%I64d",&a,&b);
 if(a==b){printf("0");return(0);}
 int q=0;while(a>0){x[q]=a%2;a/=2;q++;}
     q=0;while(b>0){y[q]=b%2;b/=2;q++;}
 for(i=99;i>=0;i--)
 {
  if(x[i]<y[i])
  {long long otv=0,f;
   for(f=1;i>=0;f*=2,i--)
   {otv+=f;}
   printf("%I64d",otv);
   return(0);
  }
 }
}