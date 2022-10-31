#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
ll InP_NuM;char ArR[20];int OuP_NuM;
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
inline void inp(ll &x){while((ArR[0]=getchar())<'0' || ArR[0]>'9');for(InP_NuM=ArR[0]-'0';(ArR[0]=getchar())>='0' && ArR[0]<='9';InP_NuM*=10,InP_NuM+=ArR[0]-'0');x=InP_NuM;}
inline void oup(ll x){while(x)ArR[OuP_NuM++]=(x%10)+'0',x/=10;while(OuP_NuM)putchar(ArR[--OuP_NuM]);}
const ll INF=((ll)1e9);
const ll MOD=((ll)1e9+7);
const ll N =501*1000;

ll n,m,sz[N],dis[N],q[N][26];
char s[N];
vector <ll> e[N];
vector <pair<ll,ll> > query[N];
bool ans[N],mark[N];

void dfs_rdy(ll x)
{
	sz[x]=1;
	for(int i=0;i<e[x].size();i++)
		dis[e[x][i]]=dis[x]+1,dfs_rdy(e[x][i]),sz[x]+=sz[e[x][i]];
}

void add(ll x,ll p)
{
	q[dis[x]][s[x]-'a']+=p;
	for(int i=0;i<e[x].size();i++)
		if(!mark[e[x][i]])
			add(e[x][i],p);
}

void dfs(ll x,bool keep)
{
	ll maxi_id=0;
	for(int i=0;i<e[x].size();i++)
		maxi_id=((sz[maxi_id]<sz[e[x][i]])?e[x][i]:maxi_id);
	for(int i=0;i<e[x].size();i++)
		if(e[x][i]!=maxi_id)
			dfs(e[x][i],0);
	if(maxi_id)dfs(maxi_id,1),mark[maxi_id]=1;
	add(x,1);
	for(int i=0;i<query[x].size();i++)
	{
		ll odd=0;
		for(int j=0;j<26 && dis[x]<=query[x][i].second;j++)
			if(q[query[x][i].second][j]&1)
				odd++;
		if(odd<=1)ans[query[x][i].first]=1;
	}
		
	
	if(maxi_id)mark[maxi_id]=0;
	if(keep==0)add(x,-1);
}

int main() 
{
	inp(n);inp(m);
	for(int i=2;i<=n;i++)
	{
		ll x;
		inp(x);
		e[x].push_back(i);
	}
	for(int i=1;i<=n;i++)scanf(" %c",&s[i]);
	for(int i=0;i<m;i++)
	{
		ll v,h;
		inp(v);inp(h);
		query[v].push_back({i,--h});
	}
	dfs_rdy(1);
	dfs(1,0);
	for(int i=0;i<m;i++)
	{
		if(ans[i])printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}