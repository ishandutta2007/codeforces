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

const int N = 1e6+10;

int ans1[N], ans2[N];
vector<int> A[N];
int n, k;

int dfs(int v, int h){
	if(A[v].size() == 0){
		ans1[v] = ans2[v] = 1;
		return h;
	}
	int mnh = N;
	int mxdif=0;
	ans1[v] = 0;
	for(int u : A[v]){
		mnh = min(dfs(u, h+1), mnh);
		mxdif = max(mxdif, ans1[u]-ans2[u]),
		ans1[v] += ans2[u];
		ans2[v] += ans2[u];
	}
	ans1[v] += mxdif;
	if(mnh-h >= k) ans2[v] = 0;
	return mnh;
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> k;
	Loop(i,1,n){
		int p;
		cin >> p;
		A[p-1].push_back(i);
	}
	dfs(0, 0);
	cout << ans1[0] << '\n';
}