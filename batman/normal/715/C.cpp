#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)101*1000)
#define INF ((ll)1e9)
#define K ((ll)20)
int tvn[5*N];
ll tavan(ll a,ll b,ll mod){if(b<5*N)return tvn[b];ll res=1;while(b){res*=b%2?a:1;res%=mod;a*=a;a%=mod;b/=2;}return res;}

int n;
int sz[K][N],phi=1,num[N];
ll m,ans;
vector <pair<int,int> > e[N];
bool mark[N];

void pre_dfs(int x,int h,int par=0)
{
	sz[h][x]=1;
	for(int i=0;i<e[x].size();i++)
	{
		int v=e[x][i].first;
		if(v==par || mark[v])continue;
		pre_dfs(v,h,x);
		sz[h][x]+=sz[h][v];
	}
}

int find_centroid(int x,int h,int size,int par=0)
{
	int child=0;
	for(int i=0;i<e[x].size();i++)
	{
		int v=e[x][i].first;
		if(v==par || mark[v])continue;
		if(sz[h][v]>size/2)child=v;
	}
	if(!child)return x;
	return find_centroid(child,h,size,x);
}

void calc(int x,int par,unordered_map <int,int> &mp,int h=1)
{
	ll ex=1LL*-num[x]*tavan(10,(1LL*h*(phi-1))%phi,m);ex%=m;ex+=m;ex%=m;
	ans+=mp[ex];
	//cout<<x<<" "<<mp[ex]<<"\n";
	for(int i=0;i<e[x].size();i++)
	{
		int v=e[x][i].first,w=e[x][i].second;
		if(v==par || mark[v])continue;
		num[v]=(1LL*num[x]*10+w)%m;
		calc(v,x,mp,h+1);
	}
}

void add(int x,int par,unordered_map <int,int> &mp,int h=1)
{
	mp[num[x]]++;
	//if(num[x]==2)cout<<x<<"\n";
	for(int i=0;i<e[x].size();i++)
	{
		int v=e[x][i].first,w=e[x][i].second;
		if(v==par || mark[v])continue;
		num[v]=(1LL*num[x]+1LL*w*tavan(10,h,m))%m;
		add(v,x,mp,h+1);
	}
}

void solve(int x,int h=0)
{
	pre_dfs(x,h);
	x=find_centroid(x,h,sz[h][x]);
	//cout<<x<<"|||||||| \n";
	unordered_map <int,int> mp;
	mark[x]=1;
	mp[0]=1;
	for(int i=0;i<e[x].size();i++)
	{
		int v=e[x][i].first,w=e[x][i].second;
		if(mark[v])continue;
		num[v]=w%m;
		calc(v,x,mp);
		add(v,x,mp);
		//cout<<x<<" "<<v<<" "<<mp[3]<<"\n";
	}
	mp.clear();
	for(int i=(ll)e[x].size()-1;i>=0;i--)
	{
		int v=e[x][i].first,w=e[x][i].second;
		if(mark[v])continue;
		num[v]=w%m;
		calc(v,x,mp);
		add(v,x,mp);
	}
	ans+=mp[0];
	mp.clear();
	for(int i=0;i<e[x].size();i++)
	{
		int v=e[x][i].first;
		if(mark[v])continue;
		solve(v,h+1);
	}
}

void calc_phi()
{
	ll m2=m;
	for(ll i=2;i*i<=m2;i++)
		if(m2%i==0)
		{
			phi*=(i-1);m2/=i;
			while(m2%i==0)phi*=i,m2/=i;
		}
	if(m2>1)phi*=(m2-1);
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	tvn[0]=1;
	for(int i=1;i<5*N;i++)tvn[i]=(1LL*tvn[i-1]*10)%m;
	calc_phi();
	for(int i=0;i<n-1;i++)
	{
		int v,u,w;
		cin>>v>>u>>w;v++;u++;
		e[v].push_back({u,w});
		e[u].push_back({v,w});
	}
	solve(1);
	cout<<ans<<"\n";
	return 0;
}