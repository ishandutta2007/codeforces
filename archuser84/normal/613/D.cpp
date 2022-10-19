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

const int N = 100'010;

namespace rmq
{
	vector<pii> a;
	pii b[20][2*N];
	int n;

	void build(){
		n = a.size();
		Loop(i,0,n) b[0][i] = a[i];
		for(int k = 0; k < 19; ++ k)
			for(int i = 0; i + (2<<k) <= n; ++i)
				b[k+1][i] = min(b[k][i], b[k][i+(1<<k)]);
	}

	pii get(int l, int r){
		int k = __lg(r-l);
		auto ans = min(b[k][l], b[k][r-(1<<k)]);
		return ans;
	}
}

vector<int> A[N];
vector<int> B[N];
int tim[N], dep[N];
int n;

void dfs(int v, int p, int d){
	dep[v] = d; tim[v] = rmq::a.size();
	rmq::a.emplace_back(d,v);
	for(int u : A[v]){
		if(u == p) continue;
		dfs(u,v,d+1);
		rmq::a.emplace_back(d,v);
	}
}

int lca(int v, int u){
	return rmq::get(min(tim[v],tim[u]), max(tim[v], tim[u])+1).second;
}

bool mark[N];

pii dfs2(int v){
	if(mark[v]){
		int ans = 0;
		for(int u : B[v])
			ans += dfs2(u).second;
		return {ans,ans+1};
	} else {
		int mx=0, sm1=0, sm2=0;
		for(int u : B[v]){
			auto [x, y] = dfs2(u);
			sm2 += x;
			sm1 += y;
			mx = max(mx, y-x);
		}
		return {min(1+sm2, sm1-mx), min(1+sm2,sm1)};
	}
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,1,n){
		int v, u;
		cin >> v >> u;
		--v; --u;
		A[v].push_back(u);
		A[u].push_back(v);
	}
	dfs(0,-1,0);
	rmq::build();
	int q;
	cin >> q;
	while(q--){
		int k; cin >> k;
		vector<pii> vec;
		while(k--){
			int v;
			cin >> v; --v;
			vec.emplace_back(tim[v], v);
			mark[v]=1;
		}

		sort(vec.begin(), vec.end());
		int timp = vec.size();
		Loop(i,0,timp-1){
			int v = lca(vec[i].second, vec[i+1].second);
			vec.emplace_back(tim[v], v);
		}
		sort(vec.begin(), vec.end());
		vec.resize(unique(vec.begin(), vec.end()) - vec.begin());

		vector<int> st;
		st.push_back(vec[0].second);
		bool flg = 0;
		Loop(i,1,vec.size()){
			while(lca(st.back(), vec[i].second) != st.back()) st.pop_back();
			if(mark[st.back()] && mark[vec[i].second] && dep[vec[i].second] - dep[st.back()] == 1)
				flg = 1;
			B[st.back()].push_back(vec[i].second);
			st.push_back(vec[i].second);
		}

		int ans = flg?-1:dfs2(vec[0].second).first;
		cout << ans << '\n';

		for(auto [_,i] : vec){
			B[i].clear();
			mark[i] = 0;
		}
	}
}