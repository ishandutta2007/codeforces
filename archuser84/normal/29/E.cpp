///
///    Hashire sori yo 
///    Kaze no you ni  
///    Tsukimihara wo  
///    PADORU PADORU   
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 510;

vector<int> A[N];
int d[N][N][2];
tuple<int,int,int> p[N][N][2];
int n, m;

void bfs()
{
	queue<tuple<int,int,int>> q;
	q.emplace(0,n-1,0);
	d[0][n-1][0]=0;
	while(q.size())
	{
		auto [v, u, t] = q.front(); q.pop();
		if(t==0){
			for(int w : A[v]){
				if(d[w][u][1] >= 0) continue;
				d[w][u][1] = d[v][u][0]+1;
				p[w][u][1] = {v,u,0};
				q.emplace(w,u,1);
			}
		} else {
			for(int w : A[u]){
				if(d[v][w][0] >= 0 || v==w) continue;
				d[v][w][0] = d[v][u][1]+1;
				p[v][w][0] = {v,u,1};
				q.emplace(v,w,0);
			}
		}
	}
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	memset(d,-1,sizeof d);
	cin >> n >> m;
	while(m--){
		int v, u;
		cin >> v >> u;
		--v; --u;
		A[v].push_back(u);
		A[u].push_back(v);
	}
	bfs();
	if(d[n-1][0][0]<0) Kill(-1);
	cout << d[n-1][0][0]/2 << '\n';
	vector<int> a, b;
	int v=n-1, u=0;
	while(v!=0||u!=n-1)
	{
		a.push_back(v);
		b.push_back(u);
		int t=0;
		tie(v,u,t) = p[v][u][t];
		tie(v,u,t) = p[v][u][t];
	}
	a.push_back(0); b.push_back(n-1);
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(int x : a) cout << x+1 << ' '; cout << '\n';
	for(int x : b) cout << x+1 << ' '; cout << '\n';
}