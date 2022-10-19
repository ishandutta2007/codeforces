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
using namespace std;

const int N = 3010;
vector<ll> a[N]; int w[N];
ll dp[N][N]; int dpi = 0;
int n, k;

void up(int i){
	Loop(j,0,k+1){
		dp[dpi+1][j] = dp[dpi][j];
		if(j >= w[i]) dp[dpi+1][j] = max(dp[dpi+1][j], dp[dpi][j-w[i]] + a[i].back());
	}
	++dpi;
}

ll solve(int i){
	ll ans = 0;
	Loop(j,0,min(k+1,(int)a[i].size())){
		ans = max(ans, a[i][j]+dp[dpi][k-j]);
	}
	return ans;
}

vector<int> t[N<<2];

void add(int l, int r, int x, int i=0, int b=0, int e=n){
	if(l >= r) return;
	if(l <= b && e <= r) {t[i].push_back(x); return;}
	if(r <= b || e <= l) return;
	add(l,r,x,2*i+1,b,(b+e)/2);
	add(l,r,x,2*i+2,(b+e)/2,e);
}

ll dfs(int i=0, int b=0, int e=n){
	for(int x : t[i]) up(x);
	if(e-b == 1) {ll ans = solve(b); dpi -= t[i].size(); return ans;}
	ll ans = 0;
	ans = max(ans, dfs(2*i+1,b,(b+e)/2));
	ans = max(ans, dfs(2*i+2,(b+e)/2,e));
	dpi -= t[i].size();
	return ans;
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	cin >> n >> k;
	Loop(i,0,n){
		a[i].push_back(0);
		int c; cin >> c; w[i]=c;
		while(c--) {ll x; cin >> x; a[i].push_back(a[i].back()+x);}
	}
	Loop(i,0,n) {add(0, i, i); add(i+1, n, i);}
	cout << dfs() << '\n';
}