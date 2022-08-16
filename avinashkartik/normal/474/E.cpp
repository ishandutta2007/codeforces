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

ll n, d, a[N], dp[N], par[N];
vll v;

pll tree[4*N+8];

pll combine(pll a, pll b){
	if(a.f > b.f) return a;
	return b;
}

void update(int node, int start, int end, int idx, ll val1, ll val2){
	if(start == end){
		tree[node] = {val1, val2};
	}
	else{
		int mid = (start + end) / 2;
		if(start <= idx and idx <= mid)
			update(2*node, start, mid, idx, val1, val2);
		else
			update(2*node+1, mid+1, end, idx, val1, val2);
		tree[node] = combine(tree[2*node], tree[2*node+1]);
	}
}

pll query(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return {0, 0};
	if(l <= start and end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	pll p1 = query(2*node, start, mid, l, r);
	pll p2 = query(2*node+1, mid+1, end, l, r);
	return combine(p1, p2);
}

void solve(){
	cin >> n >> d;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		v.pb(a[i]);
	}
	sort(all(v));
	uniq(v);
	for(int i = 1; i <= n; i++){
		int l = lower_bound(all(v), a[i] - d + 1) - v.begin() - 1;
		int r = lower_bound(all(v), a[i] + d) - v.begin();
		pll p = combine(query(1, 0, n-1, 0, l), query(1, 0, n-1, r, n-1));
		dp[i] = p.f + 1;
		par[i] = (p.s == 0) ? i : p.s;
		l = lower_bound(all(v), a[i]) - v.begin();
		if(dp[i] > query(1, 0, n-1, l, l).f){
			update(1, 0, n-1, l, dp[i], i);
		}
	}
	deb1(tree[1].f)
	int ind = tree[1].s;
	vll ans;
	while(par[ind] != ind){
		ans.pb(ind);
		ind = par[ind];
	}
	ans.pb(ind);
	reverse(all(ans));
	debv(ans)
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