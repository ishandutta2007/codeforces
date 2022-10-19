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

const int N = 20'010;
bool vis[N];
vector<pii> A[N];

void euler(int v, vector<int>& p)
{
	vector<pii> jojo;
	for(;;){
		while(A[v].size() && vis[A[v].back().second]) A[v].pop_back();
		if(A[v].empty()) break;
		auto [u, e] = A[v].back();
		vis[e] = 1;
		jojo.emplace_back(e, u);
		v = u;
	}
	for(auto [e, v] : jojo){
		p.push_back(e);
		euler(v,p);
	}
}

int n;

vector<int> odd;

vector<vector<int>> ans0;
vector<vector<int>> ans;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n;
	Loop(i,0,n){
		int v, u;
		cin >> v >> u;
		A[v].emplace_back(u,i);
		A[u].emplace_back(v,i);
	}
	Loop(i,0,N) if(A[i].size()&1) odd.push_back(i);
	for(int i = 0; i < odd.size(); i+=2){
		A[odd[i]].emplace_back(odd[i+1], n+i);
		A[odd[i+1]].emplace_back(odd[i], n+i);
	}
	Loop(v,0,N){
		vector<int> tmp;
		euler(v,tmp);
		if(tmp.size()) ans0.push_back(tmp);
		//cout << '\n';
		//for(int z : tmp) cout << z << ' ';
		//cout << '\n';}
	}
	for(auto& v : ans0){
		vector<vector<int>> dio;
		dio.emplace_back();
		for(int e : v){
			if(e >= n) dio.emplace_back();
			else dio.back().push_back(e);
		}
		if(dio.size()>1){
			for(int e : dio.front()) dio.back().push_back(e);
			dio.front().swap(dio.back());
			dio.pop_back();
		}
		for(auto& zawarudo : dio) ans.push_back(zawarudo);
	}
	if(ans.size()>2 || n==1) Kill(-1);
	if(ans.size()==1) ans.push_back(vector<int>{ans[0].back()}), ans[0].pop_back();
	for(auto& jotaro : ans){
		cout << jotaro.size() << '\n';
		for(int x : jotaro) cout << x+1 << ' ';
		cout << '\n';
	}
}