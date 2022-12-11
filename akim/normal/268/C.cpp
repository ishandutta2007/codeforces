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
 int n,m;
 scanf("%d%d",&n,&m);
 printf("%d\n",min(n,m)+1);
 int i=n,f=0;
 while(i>=0&&f>=0&&i<=n&&f<=m)
 {
  printf("%d %d\n",i,f);
  i--;f++;
 }
}