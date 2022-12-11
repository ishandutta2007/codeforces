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
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int n,m,s,f,t,l,r,i;
 scanf("%d%d%d%d",&n,&m,&s,&f);int nt=1;
 for(i=0;i<m;i++)
 {scanf("%d%d%d",&t,&l,&r);
  while(nt<t)
  {
   if(s<f)
   {printf("R");s++;
   }
   if(s>f)
   {printf("L");s--;
   }
   nt++;
   if(s==f){break;}
  }
  if(s<f&&(s+1<l||s+1>r)&&(s<l||s>r))
  {printf("R");s++;
  }else
  if(s>f&&(s-1<l||s-1>r)&&(s<l||s>r))
  {printf("L");s--;
  }else
  if(s==f){break;}
   else
  {printf("X");}
 nt++;
 }
 while(s!=f)
  {
   if(s<f)
   {printf("R");s++;
   }
   if(s>f)
   {printf("L");s--;
   }
  }
}