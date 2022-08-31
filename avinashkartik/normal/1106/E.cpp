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

const ll   N     =  1e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, m, k, dp[N][201];

struct NODE{
	ll w, d;
	NODE(): w(), d() {}
	NODE(ll w1, ll d1): w(w1), d(d1) {}
};

NODE tree[4*N+8], lazy[4*N+8], D[N];

NODE combine(NODE a, NODE b){
	NODE c;
	c.w = max(a.w, b.w);
	if(c.w == a.w) c.d = max(c.d, a.d);
	if(c.w == b.w) c.d = max(c.d, b.d);
	return c;
}

void pushlazy(int start, int end, int node){
	if(lazy[node].w == 0) return;
	tree[node] = combine(tree[node], lazy[node]);
	if(start != end){
		lazy[node*2] = combine(lazy[node*2], lazy[node]);
		lazy[node*2+1] = combine(lazy[node*2+1], lazy[node]);
	}
	lazy[node].w = lazy[node].d = 0;
}

void update(int node, int start, int end, int l, int r, ll w, ll d){
	pushlazy(start,end,node);
	if(start > end or start > r or end < l)
		return;
	if(start >= l and end <= r){
		lazy[node] = combine(lazy[node], NODE(w, d));
		pushlazy(start,end,node);
		return;
	}
	int mid = (start + end) / 2;
	update(node*2, start, mid, l, r, w, d);
	update(node*2 + 1, mid + 1, end, l, r, w, d);
	tree[node] = combine(tree[2*node], tree[2*node+1]);
}

NODE query(int node, int start, int end, int l, int r){
	pushlazy(start,end,node);
	if(start > end or start > r or end < l)
		return NODE();
	if(l <= start and end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	NODE p1 = query(2*node, start, mid, l, r);
	NODE p2 = query(2*node+1, mid+1, end, l, r);
	return combine(p1, p2);
}

ll mem(int i, int j){
	if(i == n + 1) return 0;
	ll &ans = dp[i][j];
	if(ans != -1) return ans;
	ans = INF;
	if(j != m){
		ans = min(ans, mem(i + 1, j + 1));
	}
	if(D[i].d) ans = min(ans, mem(D[i].d + 1, j) + D[i].w);
	else ans = min(ans, mem(i + 1, j));
	return ans;
}

void solve(){
	mset(dp, -1);
	cin >> n >> m >> k;
	for(int i = 1; i <= k; i++){
		ll s, t, d, w;
		cin >> s >> t >> d >> w;
		update(1, 1, n, s, t, w, d);
	}
	for(int i = 1; i <= n; i++){
		D[i] = query(1, 1, n, i, i);
	}
	deb1(mem(1, 0))
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}