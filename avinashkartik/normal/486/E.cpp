#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const int  N     =  4e5+5;
const int  mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll n, a[N], dp[N], mx[N];
vll s[N];

ll tree[4*N+8];

void update(int node, int start, int end, int idx, ll val){
	if(start == end){
		tree[node] = val;
	}
	else{
		int mid = (start + end) / 2;
		if(start <= idx and idx <= mid)
			update(2*node, start, mid, idx, val);
		else
			update(2*node+1, mid+1, end, idx, val);
		tree[node] = max(tree[2*node], tree[2*node+1]);
	}
}

ll query(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return 0;
	if(l <= start and end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	ll p1 = query(2*node, start, mid, l, r);
	ll p2 = query(2*node+1, mid+1, end, l, r);
	return max(p1, p2);
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		dp[i] = query(1, 1, N, 1, a[i]-1) + 1;
		if(dp[i] > query(1, 1, N, a[i], a[i])){
			update(1, 1, N, a[i], dp[i]);
		}
	}
	int lis = tree[1];
	vll ans(n+1, 1);
	for(int i = n; i >= 1; i--){
		if(dp[i] == lis){
			s[dp[i]].pb(i);
			mx[dp[i]] = max(mx[dp[i]], a[i]);
			continue;
		}
		if(s[dp[i]+1].size() == 0) continue;
		if(a[i] >= mx[dp[i]+1]) continue;
		s[dp[i]].pb(i);
		mx[dp[i]] = max(mx[dp[i]], a[i]);
	}
	for(int i = 1; i <= lis; i++){
		int val = (s[i].size() == 1) ? 3 : 2;
		for(auto it : s[i]) ans[it] = val;
	}
	for(int i = 1; i <= n; i++) cout << ans[i];
	newl;
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}