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
 int o=0;double r,h;
 scanf("%lf%lf",&r,&h);
 o=((int)(h/r))*2;
 if(sqrt(sqr(r)-sqr(r/2))<=((int)h)%((int)r)){o+=3;}else
 if(r/2<=((int)h)%((int)r)){o+=2;}else
  {o+=1;}
 printf("%d",o);
}