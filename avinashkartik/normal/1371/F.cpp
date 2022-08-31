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

const int  N     =  5e5+5;
const int  mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll n, q, a[N];
string s;

struct NODE{
	int len, prei, sufi, inc, dec, pred, sufd, f, l;
	NODE(): len(), prei(), sufi(), inc(), dec(), pred(), sufd(), f(), l() {}
	NODE(int v): len(1), prei(1), sufi(1), inc(1), dec(1), pred(1), sufd(1), f(v), l(v) {}
	void flip(){
		f = 1-f;
		l = 1-l;
		swap(prei, pred);
		swap(sufi, sufd);
		swap(inc, dec);
	}
};

NODE tree[4*N+8];
bool lazy[4*N+8];

NODE combine(NODE a, NODE b){
	NODE c;
	c.len = a.len + b.len;
	c.f = a.f;
	c.l = b.l;
	c.prei = a.prei;
	c.pred = a.pred;
	if(a.prei == a.len and (1-a.l)|b.f) c.prei = a.prei + b.prei;
	if(a.pred == a.len and a.l|(1-b.f)) c.pred = a.pred + b.pred;
	c.sufi = b.sufi;
	c.sufd = b.sufd;
	if(b.sufi == b.len and (1-a.l)|b.f) c.sufi = a.sufi + b.sufi;
	if(b.sufd == b.len and a.l|(1-b.f)) c.sufd = a.sufd + b.sufd;
	c.inc = max(a.inc, b.inc);
	c.dec = max(a.dec, b.dec);
	if((1-a.l)|b.f) c.inc = max(c.inc, a.sufi + b.prei);
	if(a.l|(1-b.f)) c.dec = max(c.dec, a.sufd + b.pred);
	return c;
}

void build(int node, int start, int end){
	if(start == end){
		tree[node] = NODE(a[start]);
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = combine(tree[2*node],tree[2*node+1]);
	}
}

void pushlazy(int start, int end, int node){
	if(lazy[node] == 0) return;
	tree[node].flip();
	if(start != end){
		lazy[node*2] ^= 1;
		lazy[node*2+1] ^= 1;
	}
	lazy[node] = 0;
}

void update(int node, int start, int end, int l, int r){
	pushlazy(start, end, node);
	if(start > end or start > r or end < l)
		return;
	if(start >= l and end <= r){
		lazy[node] ^= 1;
		pushlazy(start, end, node);
		return;
	}
	int mid = (start + end) / 2;
	update(node*2, start, mid, l, r);
	update(node*2 + 1, mid + 1, end, l, r);
	tree[node] = combine(tree[2*node],tree[2*node+1]);
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

void solve(){
	cin >> n >> q >> s;
	for(int i = 1; i <= n; i++){
		a[i] = (s[i-1] == '<');
	}
	build(1, 1, n);
	for(int i = 1; i <= q; i++){
		int l, r; cin >> l >> r;
		update(1, 1, n, l, r);
		deb1(query(1, 1, n, l, r).inc)
	}
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