#include <bits/stdc++.h>
using namespace std;
#define ll int
inline ll tavan(ll a,ll n,ll mod) {ll p=1;while(n>0){if(n%2){p=p*a;p%=mod;}n>>=1;a*=a;a%=mod;}return p%mod;}
#define N (301*1000)
#define K (2010)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

ll n,m,c,num[K],com[K],k;
vector <ll> e[N],first_comp,others,comp[K];
vector <pair<ll,ll> > ed;
map <ll,ll> id;
bool other[N],mark[K],e2[K][K];

bool mmm[N];
ll p,numm1;
vector <ll> ccc[N];

void dfs(ll x)
{
	mark[x]=1;com[x]=c;comp[c].push_back(x);
	for(int i=0;i<others.size();i++)
		if(!e2[x][i] && !mark[i])
			dfs(i);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	n--;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;
		v--;u--;
		if(v!=0 && u!=0)
		{
			e[v].push_back(u);
			e[u].push_back(v);
			ed.push_back({v,u});	
		}
		else
		{
			if(u==0)swap(v,u);
			mmm[u]=1;numm1++;
		}
	}
	if(n-numm1<k)return cout<<"impossible",0;
	ll mini=1;
	for(int i=2;i<=n;i++)if((ll)e[i].size()<(ll)e[mini].size())mini=i;
	for(int i=0;i<e[mini].size();i++)other[e[mini][i]]=1,id[e[mini][i]]=(ll)others.size(),others.push_back(e[mini][i]);
	for(int i=1;i<=n;i++)if(!other[i])first_comp.push_back(i);
	//for(int i=0;i<others.size();i++)cout<<others[i]<<" ";
	for(int i=0;i<others.size();i++)
		for(int j=0;j<e[others[i]].size();j++)
		{
			if(other[e[others[i]][j]])
				e2[i][id[e[others[i]][j]]]=1;
		}
	
	for(int i=0;i<others.size();i++)if(!mark[i])c++,dfs(i);
	for(int i=0;i<ed.size();i++)
	{
		if(other[ed[i].first])swap(ed[i].first,ed[i].second);
		if(other[ed[i].first] || !other[ed[i].second])continue;
		ll x=com[id[ed[i].second]];
		num[x]++;
	}
	ll nn=0,sz=(ll)first_comp.size();
	for(int i=0;i<K;i++)mark[i]=0;
	for(int i=1;i<=c;i++)
		if(num[i]!=(ll)first_comp.size()*(ll)comp[i].size())
			mark[i]=1,nn++,sz+=(ll)comp[i].size();
	
	
	
	
	
	for(int i=0;i<first_comp.size();i++)ccc[0].push_back(first_comp[i]);
	for(int i=1;i<=c;i++)
		if(mark[i])
			for(int j=0;j<comp[i].size();j++)
				ccc[0].push_back(others[comp[i][j]]);
	p++;
	for(int i=1;i<=c;i++)
		if(!mark[i])
		{
			for(int j=0;j<comp[i].size();j++)
				ccc[p].push_back(others[comp[i][j]]);
			p++;
		}
	if(p>k)return cout<<"impossible",0;
	for(int i=0;i<p;i++)
	{
		bool q=0;
		for(int j=0;j<ccc[i].size();j++)
			if(!mmm[ccc[i][j]])
				q=1;
		if(!q)return cout<<"impossible",0;
	}
	cout<<"possible";
    return 0;
}