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
int x[10]={0},t1=0,t2=0,t3=0;
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int n,i;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {int u;scanf("%d",&u);
  x[u]++;
 }
 while(x[1]&&x[2]&&x[4]){x[1]--;x[2]--;x[4]--;t1++;}
 while(x[1]&&x[3]&&x[6]){x[1]--;x[3]--;x[6]--;t3++;}
 while(x[1]&&x[2]&&x[6]){x[1]--;x[2]--;x[6]--;t2++;}
 if(t1+t2+t3==n/3)
 {
  for(i=0;i<t1;i++)
  {printf("%d %d %d\n",1,2,4);
  }
  for(i=0;i<t2;i++)
  {printf("%d %d %d\n",1,2,6);
  }
  for(i=0;i<t3;i++)
  {printf("%d %d %d\n",1,3,6);
  }
 }else
 {printf("-1");
 }
}