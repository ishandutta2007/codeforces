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
bool cmp[N];
bool vis[N];


int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int n;
	cin >> n;

	for(int x = 2; x < N; ++x){
		if(cmp[x]) continue;
		for(int y = 2*x; y < N; y += x)
			cmp[y] = 1;
	}

	vector<pii> ans;
	for(int x=n/2; x >= 2; --x){
		if(cmp[x]) continue;
		vector<int> v;
		for(int y = x; y <= n; y += x)
			if(!vis[y])
				v.push_back(y);
		if(v.size()&1) swap(v[0], v[1]);
		for(int i = v.size()&1; i < v.size(); i += 2){
			ans.emplace_back(v[i], v[i+1]);
			vis[v[i]] = vis[v[i+1]] = 1;
		}
	}

	cout << ans.size() << '\n';
	for(auto [x, y] : ans) cout << x<<' '<<y << '\n';
}