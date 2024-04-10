#include <bits/stdc++.h>
using namespace std;
#define ll int
#define N ((ll)910)

ll n,m;
vector <ll> e1[N],e2[N],e2r[N];
vector <pair<ll,ll> > ed;
stack <ll> topol;
bool mark[N];
bool is_ed[N][N];

ll cp_num[N],cp_cnt,cnt;
vector <ll> e[N],cp_v[N];
deque <ll> strt;

vector <pair<ll,ll> > ans;

void dfs1(ll x,ll par=0)
{
	mark[x]=1;
	for(auto u:e1[x])
	{
		if(u==par)continue;
		if(mark[u]!=2)e2[x].push_back(u),e2r[u].push_back(x);
		if(!mark[u])dfs1(u,x);
	}
	mark[x]=2;
}

void dfs2(ll x)
{
	mark[x]=1;
	for(auto u:e2[x])
		if(!mark[u])
			dfs2(u);
	topol.push(x);
}

void dfs3(ll x)
{
	mark[x]=1;cp_num[x]=cp_cnt;cp_v[cp_cnt].push_back(x);
	for(auto u:e2r[x])
		if(!mark[u])
			dfs3(u);
}

void dfs4(ll x)
{
	mark[x]=1;cnt++;
	if(e[x].size()==1)strt.push_back(x);
	sort(e[x].begin(),e[x].end());
	for(auto u:e[x])
		if(!mark[u])
			dfs4(u);
}

void put_edge(ll x,ll y)
{
	ll x1=cp_v[x][0],y1=cp_v[y][0];
	if(!is_ed[x1][y1]){ans.push_back({x1,y1});return ;}
	if(cp_v[x].size()>1)ans.push_back({cp_v[x][1],y1});
	else ans.push_back({x1,cp_v[y][1]});
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;
		is_ed[v][u]=is_ed[u][v]=1;
		ed.push_back({v,u});
		e1[v].push_back(u);
		e1[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
		if(!mark[i])
			dfs1(i);
	memset(mark,0,sizeof mark);
	for(int i=1;i<=n;i++)
		if(!mark[i])
			dfs2(i);
	memset(mark,0,sizeof mark);
	while(topol.size())
	{
		ll x=topol.top();topol.pop();
		if(mark[x])continue;
		cp_cnt++;
		dfs3(x);
	}
	for(auto u:ed)
	{
		ll x=cp_num[u.first],y=cp_num[u.second];
		if(x!=y)
			e[x].push_back(y),
			e[y].push_back(x);
	}
	memset(mark,0,sizeof mark);
	for(int i=1;i<=cp_cnt;i++)
		if(!mark[i])
		{
			cnt=0;
			dfs4(i);
			if(cnt==1)continue;
			if(cnt==2 && cp_v[i].size()==1 && cp_v[e[i][0]].size()==1)return cout<<-1,0;
			for(int i=0;i<(ll)strt.size()/2;i++)
				put_edge(strt[i],strt[i+(ll)strt.size()/2]);
			if((ll)strt.size()%2)put_edge(strt[0],strt[(ll)strt.size()-1]);
			strt.clear();
		}
	cout<<ans.size()<<"\n";
	for(auto u:ans)cout<<u.first<<" "<<u.second<<"\n";
	return 0;
}