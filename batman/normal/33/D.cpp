#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N (1010)
#define INF ((ll)1e14)
#define MOD ((ll)1e9+17)

ll n,m,k,c_id[N],d[N][N];
bool mark[N],mark_out[N];
pair <ll,ll> a[N];
pair <ll,pair<ll,ll> > c[N];
vector <ll> e[N];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
		cin>>a[i].first>>a[i].second;
	for(int i=0;i<m;i++)
		cin>>c[i].first>>c[i].second.first>>c[i].second.second;
	sort(c,c+m);
	for(int i=0;i<m;i++)
	{
		ll r=c[i].first,x=c[i].second.first,y=c[i].second.second;
		for(int j=0;j<n;j++)
			if(!mark[j] && x-r<=a[j].first && a[j].first<=x+r && y-r<=a[j].second && a[j].second<=y+r)
				mark[j]=1,c_id[j]=i;
		for(int j=0;j<i;j++)
		{
			ll r1=c[j].first,x1=c[j].second.first,y1=c[j].second.second;
			if(!mark_out[j] && x-r<=x1-r1 && x1+r1<=x+r && y-r<=y1-r1 && y1+r1<=y+r)
				mark_out[j]=1,e[j].push_back(i),e[i].push_back(j);
		}			
	}
	for(int i=0;i<n;i++)if(!mark[i])c_id[i]=m;
	for(int i=0;i<m;i++)if(!mark_out[i])e[m].push_back(i),e[i].push_back(m);
	for(int i=0;i<=m;i++)
	{
		d[i][i]=1;
		queue <ll> q;q.push(i);
		while(q.size())
		{
			ll x=q.front();q.pop();
			for(int j=0;j<e[x].size();j++)
				if(!d[i][e[x][j]])
					d[i][e[x][j]]=d[i][x]+1,q.push(e[x][j]);
		}
	}
	while(k--)
	{
		ll v,u;
		cin>>v>>u;
		cout<<d[c_id[v-1]][c_id[u-1]]-1<<"\n";
	}
    return 0;
}