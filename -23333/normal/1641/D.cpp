#include <bits/stdc++.h>
using namespace std;
#define rep(i,h,t) for (int i=h;i<=t;i++)
#define dep(i,t,h) for (int i=t;i>=h;i--)
#define ll long long
const int N=1e6;
set<int> S;
int n,m,nn;
int a[N][6],v[N],color[N];
ll ans[N];
const int gg=16;
#define mid ((h+t)/2)
vector<int> ve;
ll sss=1e10;
void gao()
{
	rep(i,1,nn) color[i]=rand()%gg;
	rep(i,0,(1<<gg)-1) ans[i]=1e10;
	rep(i,1,n)
	{
		int now=0;
		rep(j,1,m) now|=1<<color[a[i][j]];
		ans[now]=min(ans[now],1ll*v[i]);
	}
	rep(i,0,(1<<gg)-1)
	  rep(j,1,gg)
	    if ((i>>(j-1))&1) ans[i]=min(ans[i],ans[i^(1<<(j-1))]);
	rep(i,0,(1<<gg)-1)
	{
	  sss=min(sss,ans[i]+ans[((1<<gg)-1)^i]);
    }
}
int main()
{
	ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,1,n)
    {
      rep(j,1,m) cin>>a[i][j],ve.push_back(a[i][j]);
      cin>>v[i];
    }
    sort(ve.begin(),ve.end());
    ve.erase(unique(ve.begin(),ve.end()),ve.end());
    rep(i,1,n) 
      rep(j,1,m) a[i][j]=lower_bound(ve.begin(),ve.end(),a[i][j])-ve.begin()+1;
    nn=ve.size();
    int T=100;
    while (T--)
    {
    	gao();
    }
    if (sss>=1e10) cout<<-1<<endl;
    else cout<<sss<<endl;
	return 0; 
}