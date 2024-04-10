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
int x[100100]={0};
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int n,i,f,q=0;
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {int u;
  scanf("%d",&u);
  for(f=q+1;x[f-1]>u;f--);
  if(f==q+1){q++;x[q]=u;}
  x[f]=min(u,x[f]);
 }
 printf("%d",q);
}