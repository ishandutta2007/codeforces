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

const int  N     =  1e5+5;
const int  mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll n, m;
string s;

struct NODE{
	int ct[26] = {};
	int len;
	NODE() : len() {}
};

NODE tree[4*N], c;
int lazy[4*N];

NODE combine(NODE a, NODE b){
	NODE c;
	c.len = a.len + b.len;
	for(int i = 0; i < 26; i++) c.ct[i] = a.ct[i] + b.ct[i];
	return c;
}

void build(int node, int start, int end){
	if(start == end){
		tree[node].ct[s[start] - 'a'] = 1;
		tree[node].len = 1;
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
	}
}

void func(int f, int len, int ct[], int node){
	vector <int> tmp(26, 0);
	if(f == 1){
		for(int i = 0; i < 26; i++){
			tmp[i] = min(len, ct[i]);
			len -= tmp[i];
		}
	} else {
		for(int i = 25; i >= 0; i--){
			tmp[i] = min(len, ct[i]);
			len -= tmp[i];
		}
	}
	for(int i = 0; i < 26; i++) tree[node].ct[i] = tmp[i];
}

void func2(int f, int len, int node){
	vector <int> tmp(26, 0);
	if(f == 1){
		for(int i = 0; i < 26; i++){
			tmp[i] = min(len, c.ct[i]);
			len -= tmp[i];
			c.ct[i] -= tmp[i];
		}
	} else {
		for(int i = 25; i >= 0; i--){
			tmp[i] = min(len, c.ct[i]);
			len -= tmp[i];
			c.ct[i] -= tmp[i];
		}
	}
	for(int i = 0; i < 26; i++) tree[node].ct[i] = tmp[i];
}

void pushlazy(int start, int end, int node){
	if(lazy[node] == 0) return;
	if(start != end){
		func(lazy[node], tree[2 * node].len, tree[node].ct, 2 * node);
		func(-lazy[node], tree[2 * node + 1].len, tree[node].ct, 2 * node + 1);
		lazy[2 * node] = lazy[2 * node + 1] = lazy[node];
	}
	lazy[node] = 0;
}

void update(int node, int start, int end, int l, int r, int val){
	pushlazy(start,end,node);
	if(start > end or start > r or end < l)
		return;
	if(start >= l and end <= r){
		func2(val, tree[node].len, node);
		lazy[node] = val;
		pushlazy(start,end,node);
		return;
	}
	int mid = (start + end) / 2;
	update(node*2, start, mid, l, r, val);
	update(node*2 + 1, mid + 1, end, l, r, val);
	tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
}

NODE query(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return NODE();
	pushlazy(start, end, node);
	if(l <= start and end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	NODE p1 = query(2*node, start, mid, l, r);
	NODE p2 = query(2*node+1, mid+1, end, l, r);
	return combine(p1, p2);
}


void solve(){
	cin >> n >> m >> s;
	build(1, 0, n - 1);
	for(int i = 1; i <= m; i++){
		int l, r, f; cin >> l >> r >> f;
		l--, r--;
		if(f == 0) f = -1;
		c = query(1, 0, n - 1, l, r);
		update(1, 0, n - 1, l, r, f);
	}
	for(int i = 0; i < n; i++){
		c = query(1, 0, n - 1, i, i);
		int v = 0;
		for(int i = 0; i < 26; i++) v += i * c.ct[i];
		char ch = v + 'a';
		cout << ch;
	}
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