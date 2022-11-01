#include <bits/stdc++.h>
using namespace std;
#define N ((int)301*1000)
#define INF ((int)1e9)

int n,_x[N],_y[N];
vector <pair<int,int> > vec[N];

int m,comp[N];
vector <int> e[N],e2[N],ver[N];

int mm,cent_ver[N],sz[N];
bool dead[N];
vector <pair<int,pair<int,int> > > cents[N];

vector <int> fen[N][2];

void update(int p,int x,int val)
{
	for(int y=x+1;y<=fen[p][0].size();y+=y&-y)
		fen[p][0][y-1]=min(fen[p][0][y-1],val-x);
	x=(int)fen[p][0].size()-1-x;
	for(int y=x+1;y<=fen[p][1].size();y+=y&-y)
		fen[p][1][y-1]=min(fen[p][1][y-1],val-x);
}

int query(int p,int x)
{
	int res=INF;
	for(int y=x+1;y;y-=y&-y)
		res=min(res,fen[p][0][y-1]+x);
	int sz=fen[p][0].size();
	for(int y=(sz-1-x)+1;y;y-=y&-y)
		res=min(res,fen[p][1][y-1]+(sz-1)-x);
	return res;
}

void pre_dfs(int x,int par=0)
{
	sz[x]=ver[x].size();
	for(auto u:ver[x])cents[u].push_back({mm,{N,0}});
	for(auto u:e[x])
		if(u!=par && !dead[u])
			pre_dfs(u,x),
			sz[x]+=sz[u];
}

int find_roid(int x,int all,int par=0)
{
	for(auto u:e[x])
		if(u!=par && !dead[u] && sz[u]>all/2)
			return find_roid(u,all,x);
	return x;
}

void solve(int x)
{
	mm++;
	pre_dfs(x);
	int v=find_roid(x,sz[x]);
	cent_ver[mm]=v;dead[v]=1;
	for(int i=0;i<ver[v].size();i++)fen[mm][0].push_back(INF),fen[mm][1].push_back(INF);
	queue <int> q;
	for(int i=0;i<ver[v].size();i++)
		cents[ver[v][i]].back().second={0,i},
		q.push(ver[v][i]);
	while(q.size())
	{
		int x=q.front();q.pop();
		int dis=cents[x].back().second.first,id=cents[x].back().second.second;
		for(auto u:e2[x])
			if(!dead[comp[u]] && cents[u].back().second.first>dis+1)
				cents[u].back().second={dis+1,id},
				q.push(u);
	}
	for(auto u:e[v])
		if(!dead[u])
			solve(u);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&_x[i],&_y[i]);
		vec[_x[i]].push_back({_y[i],i});
	}
	for(int i=1;i<N;i++)
	{
		sort(vec[i].begin(),vec[i].end());
		for(int lst=0,j=0,p=0;j<vec[i].size();j++)
		{
			if(j!=(int)vec[i].size()-1 && vec[i][j].first==vec[i][j+1].first-1)continue;
			m++;
			for(int k=lst;k<=j;k++)
			{
				comp[vec[i][k].second]=m;
				ver[m].push_back(vec[i][k].second);
				if(k<j)
					e2[vec[i][k].second].push_back(vec[i][k+1].second),
					e2[vec[i][k+1].second].push_back(vec[i][k].second);
			}
			while(p<vec[i-1].size() && vec[i-1][p].first<=vec[i][j].first)
			{
				if(vec[i-1][p].first<vec[i][lst].first){p++;continue;}
				int id=j-(vec[i][j].first-vec[i-1][p].first);
				e2[vec[i-1][p].second].push_back(vec[i][id].second);
				e2[vec[i][id].second].push_back(vec[i-1][p].second);
				if(!e[m].size() || comp[vec[i-1][p].second]!=e[m].back())
					e[m].push_back(comp[vec[i-1][p].second]),
					e[comp[vec[i-1][p].second]].push_back(m);
				p++;
			}
			lst=j+1;
		}
	}
	solve(1);
	int q;scanf("%d",&q);
	while(q--)
	{
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		int id=lower_bound(vec[x].begin(),vec[x].end(),make_pair(y,0))->second;
		if(t==1)
		{
			for(auto u:cents[id])
				update(u.first,u.second.second,u.second.first);
		}
		if(t==2)
		{
			int res=INF;
			for(auto u:cents[id])
				res=min(res,query(u.first,u.second.second)+u.second.first);
			if(res>N)printf("-1\n");
			else printf("%d\n",res);
		}
	}
	return 0;
}