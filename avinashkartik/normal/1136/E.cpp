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
typedef  unsigned long long    ull;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  3e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, m, a[N], b[N], k[N], pre[N];

struct NODE{
	ll sum, mx, minus;
	NODE(): sum(0), mx(-INF), minus(0) {}
	NODE(ll v, ll u): sum(v), mx(v), minus(u) {}
};
 
NODE tree[4*N+8];
ll lazy[4*N+8];
 
NODE combine(NODE a, NODE b){
	NODE c;
	c.sum = a.sum + b.sum;
	c.mx = max(a.mx, b.mx);
	c.minus = a.minus + b.minus;
	return c;
}
 
void build(int node, int start, int end){
	lazy[node] = -INF;
	if(start == end){
		tree[node] = NODE(a[start] - pre[start-1], pre[start-1]);
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = combine(tree[2*node], tree[2*node+1]);
	}
}
 
void pushlazy(int start, int end, int node){
	if(lazy[node] == -INF) return;
	tree[node].sum = (end - start + 1) * lazy[node];
	tree[node].mx = lazy[node];
	if(start != end){
		lazy[node*2] = lazy[node];
		lazy[node*2+1] = lazy[node];
	}
	lazy[node] = -INF;
}
 
void update(int node, int start, int end, int l, int r, ll val){
	pushlazy(start,end,node);
	if(start > end or start > r or end < l)
		return;
	if(start >= l and end <= r){
		lazy[node] = val;
		pushlazy(start,end,node);
		return;
	}
	int mid = (start + end) / 2;
	update(node*2, start, mid, l, r, val);
	update(node*2 + 1, mid + 1, end, l, r, val);
	tree[node] = combine(tree[2*node], tree[2*node+1]);
}
 
NODE query(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return NODE();
	pushlazy(start,end,node);
	if(l <= start and end <= r){
		return tree[node];
	}
	int mid = (start + end) / 2;
	NODE p1 = query(2*node, start, mid, l, r);
	NODE p2 = query(2*node+1, mid+1, end, l, r);
	return combine(p1, p2);
}

int bs(int l, ll val, int r = n){
	while(l < r){
		int mid = (l + r) / 2;
		NODE c = query(1, 1, n, l, mid);
		if(c.mx > val){
			r = mid;
		} else l = mid + 1;
	}
	return l - 1;
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i < n; i++) cin >> k[i];
	for(int i = 1; i < n; i++) pre[i] = pre[i - 1] + k[i];
	build(1, 1, n);
	cin >> m;
	for(int i = 1; i <= m; i++){
		char x;
		int l, r, ind;
		cin >> x >> l >> r;
		if(x == 's'){
			NODE c = query(1, 1, n, l, r);
			deb1(c.sum + c.minus)
		} else {
			NODE c = query(1, 1, n, l, l);
			NODE d = query(1, 1, n, l, n);
			if(d.mx <= c.sum + r) ind = n;
			else ind = bs(l, c.sum + r);
			update(1, 1, n, l, ind, c.sum + r);
		}
	}
}

int main(){
	GODSPEED;
	int test = 1;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}