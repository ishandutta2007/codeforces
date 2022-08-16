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

const int  N     =  1e6+5;
const int  mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll test = 1, n, m;
string a;

struct NODE{
	int no4, no7, inc, dec;
	NODE(): no4(), no7(), inc(), dec() {} 
	NODE(int val): no4(val == 4), no7(val == 7), inc(1), dec(1) {} 
};

NODE tree[4*N+8];
int lazy[4*N+8];

NODE combine(NODE a, NODE b){
	NODE c;
	c.no4 = a.no4 + b.no4;
	c.no7 = a.no7 + b.no7;
	c.inc = max({a.inc + b.no7, a.no4 + b.inc, a.no4 + b.no4, a.no7 + b.no7});
	c.dec = max({a.dec + b.no4, a.no7 + b.dec, a.no4 + b.no4, a.no7 + b.no7});
	return c;
}

void build(int node, int start, int end){
	if(start == end){
		tree[node] = NODE(a[start]-'0');
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node + 1, mid + 1, end);
		tree[node] = combine(tree[2*node], tree[2*node+1]);
	}
}

void pushlazy(int start, int end, int node){
	if(lazy[node] == 0) return;
	swap(tree[node].inc, tree[node].dec);
	swap(tree[node].no4, tree[node].no7);
	if(start != end){
		lazy[node*2] ^= 1;
		lazy[node*2+1] ^= 1;
	}
	lazy[node] = 0;
}

void update(int node, int start, int end, int l, int r){
	pushlazy(start,end,node);
	if(start > end or start > r or end < l)
		return;
	if(start >= l and end <= r){
		lazy[node] ^= 1;
		pushlazy(start,end,node);
		return;
	}
	int mid = (start + end) / 2;
	update(node*2, start, mid, l, r);
	update(node*2 + 1, mid + 1, end, l, r);
	tree[node] = combine(tree[2*node], tree[2*node+1]);
}

void solve(){
	cin >> n >> m >> a; a = '0'+a+'0';
	build(1,1,n);
	for(int i = 1; i <= m; i++){
		string s; cin >> s;
		if(s[0] == 'c') deb1(tree[1].inc)
		else{
			int l, r; cin >> l >> r;
			update(1,1,n,l,r);
		}
	}
}

int main(){
	GODSPEED;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}