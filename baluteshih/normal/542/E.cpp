#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define REP(i,n) for(ll i=0;i<n;i++)
#define REP1(i,n) for(ll i=1;i<=n;i++)
#define FILL(i,n) memset(i,n,sizeof i)
#define X first
#define Y second
#define ET cout << "\n"
#define SZ(_a) (int)_a.size()
#define ALL(_a) _a.begin(),_a.end()
#define pb push_back
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0);
#ifdef bbq
#define debug(...) {\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<", ";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
#else
#define debug(...)
#endif

const int INF=1e9;
vector<int> G[1005];
int bln[1005],clr[1005],dis[1005],ans[1005],tp;

bool dfs(int u,int c)
{
	clr[u]=c,bln[u]=tp;
	for(int i:G[u])
		if(!~clr[i])
			if(!dfs(i,1-c)) return 0;
			else;
		else if(clr[i]==clr[u]) return 0;
	return 1;
}

int main()
{
	IOS()
	int n,m,a,b,out=0;
	cin >> n >> m,FILL(clr,-1);
	while(m--)
		cin >> a >> b,G[a].pb(b),G[b].pb(a);
	for(int i=1;i<=n;++i)
		if(!~clr[i]&&(++tp,!dfs(i,0)))
			return cout << "-1\n",0;
	for(int i=1;i<=n;++i)
	{
		queue<int> q;
		fill(dis+1,dis+n+1,INF),q.push(i),dis[i]=0;
		while(!q.empty())
		{
			int u=q.front();
			q.pop();
			for(int j:G[u])
				if(dis[j]>dis[u]+1)
					dis[j]=dis[u]+1,q.push(j);
		}
		for(int j=1;j<=n;++j)
			if(dis[j]<INF)
				ans[bln[i]]=max(ans[bln[i]],dis[j]);
	}
	for(int i=1;i<=tp;++i)
		out+=ans[i];
	cout << out << "\n";
}