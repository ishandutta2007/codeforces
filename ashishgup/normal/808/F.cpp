#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=105;
const int M=2e5+5;

struct edge
{
	int from, to, cap, flow, index;
	edge(int from, int to, int cap, int flow, int index):
		from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct PushRelabel
{
	int n;
	vector<vector<edge> > g;
	vector<long long> excess;
	vector<int> height, active, count;
	queue<int> Q;

	PushRelabel(int n):
		n(n), g(n), excess(n), height(n), active(n), count(2*n) {}

	void addEdge(int from, int to, int cap)
	{
		g[from].push_back(edge(from, to, cap, 0, g[to].size()));
		if(from==to)
			g[from].back().index++;
		g[to].push_back(edge(to, from, 0, 0, g[from].size()-1));
	}

	void enqueue(int v)
	{
		if(!active[v] && excess[v] > 0)
		{
			active[v]=true;
			Q.push(v);
		}
	}

	void push(edge &e)
	{
		int amt=(int)min(excess[e.from], (long long)e.cap - e.flow);
		if(height[e.from]<=height[e.to] || amt==0)
			return;
		e.flow += amt;
		g[e.to][e.index].flow -= amt;
		excess[e.to] += amt;
		excess[e.from] -= amt;
		enqueue(e.to);
	}

	void relabel(int v)
	{
		count[height[v]]--;
		int d=2*n;
		for(auto &it:g[v])
		{
			if(it.cap-it.flow>0)
				d=min(d, height[it.to]+1);
		}
		height[v]=d;
		count[height[v]]++;
		enqueue(v);
	}

	void gap(int k)
	{
		for(int v=0;v<n;v++)
		{
			if(height[v]<k)
				continue;
			count[height[v]]--;
			height[v]=max(height[v], n+1);
			count[height[v]]++;
			enqueue(v);
		}
	}

	void discharge(int v)
	{
		for(int i=0; excess[v]>0 && i<g[v].size(); i++)
			push(g[v][i]);
		if(excess[v]>0)
		{
			if(count[height[v]]==1)
				gap(height[v]);
			else
				relabel(v);
		}
	}

	long long max_flow(int source, int dest)
	{
		count[0] = n-1;
		count[n] = 1;
		height[source] = n;
		active[source] = active[dest] = 1;
		for(auto &it:g[source])
		{
			excess[source]+=it.cap;
			push(it);
		}

		while(!Q.empty())
		{
			int v=Q.front();
			Q.pop();
			active[v]=false;
			discharge(v);
		}

		long long max_flow=0;
		for(auto &e:g[source])
			max_flow+=e.flow;

		return max_flow;
	}
};

int n, k;
int p[N], c[N], l[N], sieve[M];

void precompute()
{
	fill(sieve+2, sieve+M, 1);
	for(int i=2;i<N;i++)
	{
		if(!sieve[i])
			continue;
		for(int j=2;i*j<N;j++)
			sieve[i*j]=0;
	}
}

int check(int x)
{	
	int sum=0, sumones=0, bestone=0;
	vector<pair<int, int> > odds, evens;
	for(int i=1;i<=n;i++)
	{
		if(l[i]<=x)
		{
			sum+=p[i];
			if(c[i]==1)
			{
				sumones+=p[i];
				bestone=max(bestone, p[i]);
			}
			else if(c[i]%2)
				odds.push_back({p[i], c[i]});
			else
				evens.push_back({p[i], c[i]});
		}
	}
	if(bestone)
	{
		sum=sum-sumones+bestone;
		odds.push_back({bestone, 1});
	}
	PushRelabel flow(odds.size()+evens.size()+2);
	int asz=odds.size(), bsz=evens.size();
	for(int i=0;i<asz;i++)
	{
		flow.addEdge(0, i+1, odds[i].first);
		for(int j=0;j<bsz;j++)
		{
			if(i==0)
				flow.addEdge(j+asz+1, asz+bsz+1, evens[j].first);
			if(sieve[odds[i].second+evens[j].second])
				flow.addEdge(i+1, j+asz+1, 1e9);
		}
	}
	int ans=sum - flow.max_flow(0, asz+bsz+1);
	return ans>=k;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)/2;
		if(check(mid))
			hi=mid;
		else
			lo=mid+1;
	}
	return lo;
}

int32_t main()
{
	IOS;
	precompute();
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i]>>c[i]>>l[i];
	int ans=binsearch(1, 100);
	if(!check(ans))
		ans=-1;
	cout<<ans<<endl;
	return 0;
}