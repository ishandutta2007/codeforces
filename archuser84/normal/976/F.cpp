///
///   What would happen if we used assembly language for CP?
///   Sorry, that was a strange thing to ask.
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 12010;
int n1, n2, n, m;
vector<int> A[N];
tuple<int,int,int> E[N];

namespace flow
{
	int ptr[N];
	int level[N];

	void bfs(int s){
		queue<int> q;
		memset(level,-1,sizeof level);
		level[s] = 0;
		q.push(s);
		while(q.size()){
			int v = q.front(); q.pop();
			for(int e : A[v]){
				auto [_, u, cap] = E[e];
				if(!cap || level[u] != -1) continue;
				level[u] = level[v]+1;
				q.push(u);
			}
		}
	}

	int dfs(int v, int t, int f){
		if(v==t) return f;
		int ans = 0;
		for(int& i = ptr[v]; i < A[v].size(); ++i){
			int e = A[v][i];
			int e2 = e<n+m?e+n+m:e-n-m;
			auto [_, u, cap] = E[e];
			if(!cap || level[u] != level[v]+1) continue;
			int f2 = dfs(u, t, min(f, cap));
			f -= f2;
			get<2>(E[e]) -= f2;
			get<2>(E[e2]) += f2;
			ans += f2;
			if(f == 0) break;
		}
		return ans;
	}

	int flow(){
		int ans = 0;
		for(;;){
			bfs(n);
			if(level[n+1] == -1) break;
			memset(ptr,0,4*(n+2));
			ans += dfs(n,n+1,1e9);
		}
		return ans;
	}
}

int cnt[N];

bool init(int k){
	Loop(i,0,m) get<2>(E[i])=1;
	Loop(i,m,m+n1){
		auto& [_,v,cap] = E[i];
		if(cnt[v] < k) return 0;
		cap = cnt[v]-k;
	}
	Loop(i,m+n1,m+n){
		auto& [v,_,cap] = E[i];
		if(cnt[v] < k) return 0;
		cap = cnt[v]-k;
	}
	Loop(i,m+n,2*(m+n)) get<2>(E[i]) = 0;
	return 1;
}

void addedge(int i, int v, int u){
	A[v].push_back(i);
	A[u].push_back(i+m+n);
	E[i] = {v,u,0};
	E[i+m+n] = {u,v,0};
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n1 >> n2 >> m; n=n1+n2;
	Loop(i,0,m){
		int v, u;
		cin >> v >> u;
		--v; --u;
		u += n1;
		addedge(i,v,u);
		++cnt[v]; ++cnt[u];
	}
	Loop(i,m   ,m+n1) addedge(i,n  ,i-m);
	Loop(i,m+n1,m+n ) addedge(i,i-m,n+1);
	for(int d=0; init(d); ++d){
		int k = m-flow::flow();
		cout << k << ' ';
		Loop(i,0,m){
			auto [v, u, cap] = E[i];
			if(cap)
				cout << i+1 << ' ';
		}
		cout << '\n';
	}
}