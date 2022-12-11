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
vector<pair<int,string> > rb[100100];
int x[300300];
string s;int lss,lp,otv=0;
void dfs(int u,int ls)
{int i,f,g;
 for(g=0;g<rb[u].size();g++)
 {
  int lr=rb[u][g].sc.length();
  for(i=0;i<lr;i++)
  {f=x[ls+i-1];
   while(f!=-1&&rb[u][g].sc[i]!=s[f+1]){f=x[f];}
   if(s[f+1]==rb[u][g].sc[i]){x[ls+i]=f+1;}else{x[ls+i]=-1;}
   if(x[ls+i]==lss-2){otv++;}
//   cout<<u<<" "<<x[ls+i]<<"\n";
  }
  dfs(rb[u][g].fs,ls+lr);
 }
}
int main()
{
// freopen("*.in","r",stdin);
// freopen("*.out","w",stdout);
 int n,i,f;
 scanf("%d\n",&n);
 for(i=2;i<=n;i++)
 {int u;char c;scanf("%d%d",&u,&c);
  string s;getline(cin,s);
  rb[u].pb(mp(i,s));
 }
 getline(cin,s);s+='#';lss=s.length();
 x[0]=-1;
 for(i=1;i<lss;i++)
 {f=x[i-1];
  while(f!=-1&&s[i]!=s[f+1]){f=x[f];}
  if(s[f+1]==s[i]){x[i]=f+1;}else{x[i]=-1;}
  if(x[i]==lss-2){otv++;}
 }
// for(i=0;i<ls;i++){printf("%d ",x[i]);}
 dfs(1,lss);
 cout<<otv;
}