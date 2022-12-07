#include <bits/stdc++.h>
using namespace std;
const int Maxn=610;
pair<string,string>pr[Maxn];
map<string,int>mp; int num=0; int N,A,B,K,F;
int Hash[Maxn][Maxn];

struct node
{
  int d,x,y;
  node(){}
  node(int _d,int _x,int _y){d=_d; x=_x; y=_y;}
  friend bool operator <(const node &x,const node &y)
  {
    return x.d<y.d;
  }
};

priority_queue<node>Q;

int D[Maxn][Maxn];
int main()
{
  scanf("%d%d%d%d%d",&N,&A,&B,&K,&F);

  for(int i=1;i<=N;i++)
  {
    cin>> pr[i].first>> pr[i].second;
    if(mp[pr[i].first]==0) mp[pr[i].first]=++num;
    if(mp[pr[i].second]==0) mp[pr[i].second]=++num;
    int x=mp[pr[i].first]; int y=mp[pr[i].second];
    if(pr[i].first!=pr[i-1].second) Hash[x][y]+=A,Hash[y][x]+=A;
    else Hash[x][y]+=B,Hash[y][x]+=B;
  }
  for(int i=1;i<=num;i++) for(int j=1;j<i;j++)
  {
    Q.push(node(Hash[i][j],i,j));
  }
  memset(D,63,sizeof(D)); int ans=0;
  while(!Q.empty() && K)
  {
    node x=Q.top(); Q.pop();
    if(x.d>F){K--; D[x.x][x.y]=D[x.y][x.x]=0; ans+=F; }
    else break;
  }
  for(int i=1;i<=N;i++)
  {
    int x=mp[pr[i].first]; int y=mp[pr[i].second];
    if(D[x][y]==0) continue;
    else
    {
      if(pr[i].first==pr[i-1].second) ans+=B;
      else ans+=A;
    }
  }
  return printf("%d\n",ans),0;
}