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
 string s;getline(cin,s);int ls=s.length(),n,i;ls--;
 for(i=0;i<ls;i++){x[i+1]=x[i]+(s[i]==s[i+1]?1:0);}
 scanf("%d",&n);
 for(;n>0;n--)
 {int u,v;
  scanf("%d%d",&u,&v);
  printf("%d\n",x[v-1]-x[u-1]);
 }
}