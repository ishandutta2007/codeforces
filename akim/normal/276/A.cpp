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
 int ud=-2000000000,n,k,i;
 scanf("%d%d",&n,&k);
 for(i=0;i<n;i++)
 {int t,f;
  scanf("%d%d",&f,&t);
  ud=max(ud,t>k?(f-t+k):f);
 }
 printf("%d",ud);
}