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
bool kp[500][500]={0};
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int a=200,b=200,dv=0,x,y,dst=0;
 scanf("%d%d",&x,&y);x+=200;y+=200;
 bool log=0;
 while(a!=x||b!=y)
 {if(log==1){dst++;log=0;}
  kp[a][b]=1;
  if(dv==0){a++;if(kp[a][b+1]!=1){dv=1;log=1;}}else
  if(dv==1){b++;if(kp[a-1][b]!=1){dv=2;log=1;}}else
  if(dv==2){a--;if(kp[a][b-1]!=1){dv=3;log=1;}}else
  if(dv==3){b--;if(kp[a+1][b]!=1){dv=0;log=1;}}
 }
 printf("%d",dst);
}