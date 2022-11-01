#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)501*1000)
#define K ((ll)20)

int n,root,par[K][N],dis[N],strt[N],fnsh[N],_cnt=1;
vector <int> e[N];
vector <pair<int,int> > vec[N];
int cnt[N],dad[N];
ll fen[N],ans[N];

ll query(int x){ll res=0;for(;x>0;x-=x&-x)res+=fen[x];return res;}
void update2(int x,ll val){for(;x<N;x+=x&-x)fen[x]+=val;}
void update(int l,int r,ll val)
{
	update2(l,val);
	update2(r,-val);
}

void pre_dfs(int x)
{
	strt[x]=_cnt++;
	vec[dis[x]].push_back({strt[x],x});
	for(int i=1;i<K;i++)par[i][x]=par[i-1][par[i-1][x]];
	for(auto u:e[x])
		if(u!=par[0][x])
			par[0][u]=x,
			dis[u]=dis[x]+1,
			pre_dfs(u);
	fnsh[x]=_cnt;
}

int iPar(int x,int num)
{
	for(int i=0;i<K;i++)
		if((num&(1<<i)))
			x=par[i][x];
	return x;
}

int lca(int x,int y)
{
	if(dis[x]<dis[y])swap(x,y);
	x=iPar(x,dis[x]-dis[y]);
	if(x==y)return x;
	for(int i=K-1;i>=0;i--)
		if(par[i][x]!=par[i][y])
			x=par[i][x],y=par[i][y];
	return par[0][x];
}

void dfs(int x)
{
	ans[x]+=ans[par[0][x]];
	for(auto u:e[x])
		if(u!=par[0][x])
			dfs(u);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x)e[x].push_back(i);
		else root=i;
	}
	dis[0]=-1;
	pre_dfs(root);
	for(int i=1;;i++)
	{
		if(!vec[i].size())break;
		int ex=vec[i].size();
		for(int j=0;j<ex-1;j++)
		{
			int p=lca(vec[i][j].second,vec[i][j+1].second);
			vec[i].push_back({strt[p],p});
		}
		vec[i].push_back({strt[root],root});
		sort(vec[i].begin(),vec[i].end());vec[i].resize(unique(vec[i].begin(),vec[i].end())-vec[i].begin());
		stack <int> st;
		vector <pair<pair<int,int>,ll> > reset;
		st.push(root);
		for(int j=1;j<vec[i].size();j++)
		{
			int u=vec[i][j].second;
			while(strt[u]>=fnsh[st.top()])
			{
				int x=st.top();st.pop();
				cnt[dad[x]]+=cnt[x];
				update(strt[x],fnsh[x],1LL*cnt[x]*(dis[x]-dis[dad[x]]));
				reset.push_back({{strt[x],fnsh[x]},1LL*cnt[x]*(dis[x]-dis[dad[x]])});
			}
			dad[u]=st.top();
			st.push(u);
			if(dis[u]==i)cnt[u]=1;
		}
		while(st.size())
		{
			int x=st.top();st.pop();
			cnt[dad[x]]+=cnt[x];
			update(strt[x],fnsh[x],1LL*cnt[x]*(dis[x]-dis[dad[x]]));
			reset.push_back({{strt[x],fnsh[x]},1LL*cnt[x]*(dis[x]-dis[dad[x]])});
		}
		for(auto u:vec[i])
		{
			cnt[u.second]=0;
			if(dis[u.second]==i)
				ans[u.second]=query(strt[u.second])-1;
		}
		for(auto u:reset)
			update(u.first.first,u.first.second,-u.second);
	}
	dfs(root);
	for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}