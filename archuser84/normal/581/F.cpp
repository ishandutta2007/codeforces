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

const int N = 5'010;
vector<int> A[N];

vector<int> dfs(int v, int p)
{
	vector<int> ans={0};
	for(int u : A[v]){
		if(A[u].size()==1){
			ans.push_back(N);
			LoopR(i,0,ans.size()-1) ans[i+1] = min(ans[i+1],ans[i]+1);
		} else if(u != p){
			auto vec = dfs(u, v);
			vector<int> nans(ans.size()+vec.size()-1, N);
			Loop(i,0,ans.size()) Loop(j,0,vec.size())
				nans[i+j] = min(nans[i+j], ans[i]+vec[j]);
			Loop(i,0,ans.size()) Loop(j,0,vec.size())
				nans[i+vec.size()-j-1] = min(nans[i+vec.size()-j-1], ans[i]+vec[j]+1);
			ans = nans;
		}
	}
	return ans;
}
int n;

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,0,n-1){
		int v, u;
		cin >> v >> u;
		--v; --u;
		A[v].push_back(u);
		A[u].push_back(v);
	}
	if(n==2) Kill(1);
	int rt=0;
	while(A[rt].size()==1) ++rt;
	auto ans = dfs(rt, -1);
	cout << ans[ans.size()/2] << '\n';
}