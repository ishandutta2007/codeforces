#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

template<typename T> T gcd(T a,T b) { if(a==0) return b; return gcd(b%a,a); }
template<typename T> T pow(T a,T b, long long m){T ans=1; while(b>0){ if(b%2==1) ans=(ans*a)%m; b/=2; a=(a*a)%m; } return ans%m; }

const int N=3e5+5;

struct data
{
	int u, v, t;
};

int n, m, s, ans1=0, ans2=0;
int vis[N];
data store[N];
vector<pair<int, int> > g[N];
map<pair<int, int>, char> m1;
map<pair<int, int>, char> m2;


void bfs1()
{
	int source=s;
	queue<int> q;
	q.push(source);
	vis[source]=1;
	ans1=1;
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		for(auto it:g[top])
		{
			if(vis[it.ff])
				continue;
			vis[it.ff]=1;
			if(it.ss==1)
			{
				q.push(it.ff);
			}
			else
			{
				q.push(it.ff);
				m1[mp(top,it.ff)]='+';
				m1[mp(it.ff,top)]='-';
			}
			ans1++;
		}
	}
}

void bfs2()
{
	memset(vis, 0, sizeof(vis));
	int source=s;
	queue<int> q;
	q.push(source);
	vis[source]=1;
	ans2=1;
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		for(auto it:g[top])
		{
			if(vis[it.ff])
				continue;
			if(it.ss==1)
			{
				vis[it.ff]=1;
				q.push(it.ff);
				ans2++;
			}
			else
			{
				m2[mp(top, it.ff)]='-';
			}
		}
	}
}

int32_t main()
{
	IOS;
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++)
	{
		int u, v, t;
		cin>>t>>u>>v;
		store[i].u=u;
		store[i].v=v;
		store[i].t=t;
		if(t==1)
		{
			g[u].pb(mp(v,t));
		}
		else
		{
			m1[mp(u, v)]='+';
			m1[mp(v, u)]='-';
			m2[mp(u, v)]='+';
			m2[mp(v, u)]='-';
			g[u].pb(mp(v,t));
			g[v].pb(mp(u,t));
		}
	}
	bfs1();
	cout<<ans1<<endl;
	for(int i=1;i<=m;i++)
	{
		if(store[i].t==1)
			continue;
		char ch=m1[mp(store[i].u, store[i].v)];
		cout<<ch;
	}
	cout<<endl;
	bfs2();
	cout<<ans2<<endl;
	for(int i=1;i<=m;i++)
	{
		if(store[i].t==1)
			continue;
		char ch=m2[mp(store[i].u, store[i].v)];
		cout<<ch;
	}
}