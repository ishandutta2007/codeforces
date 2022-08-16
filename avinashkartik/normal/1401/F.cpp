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

const int  N     =  1<<18;
const int  mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll test = 1, n, q, a[N+5], val[20];

struct NODE{
	NODE *l = {nullptr}, *r = {nullptr};
	ll sum = 0, lazy = 0;
};

NODE *tree = new NODE;

NODE *build(NODE *node, int start, int end){
	if(start == end){
		node->sum = a[start];
	}
	else{
		int mid = (start + end) / 2;
		node->l = new NODE;
		node->r = new NODE;
		node->l = build(node->l, start, mid);
		node->r = build(node->r, mid+1, end);
		node->sum = node->l->sum+node->r->sum;
	}
	return node;
}

NODE *pushlazy(NODE *node, int start, int end, int lvl){
	if(node->lazy == val[lvl]) return node;
	swap(node->l,node->r);
	node->lazy ^= 1;
	return node;
}

NODE *replace(NODE* node, int start, int end, int idx, ll val, int lvl){
	node = pushlazy(node,start,end,lvl);
	if(start == end){
		node->sum = val;
		return node;
	}
	int mid = (start + end) / 2;
	if(start <= idx and idx <= mid)
		node->l = replace(node->l, start, mid, idx, val, lvl+1);
	else
		node->r = replace(node->r, mid+1, end, idx, val, lvl+1);
	node->sum = node->l->sum+node->r->sum;
	return node;
}

NODE *query(NODE *node, int start, int end, int l, int r, int lvl){
	if(start > end or start > r or end < l)
		return new NODE;
	node = pushlazy(node,start,end,lvl);
	if(l <= start and end <= r){
		return node;
	}
	int mid = (start + end) / 2;
	NODE *p1 = query(node->l, start, mid, l, r, lvl+1);
	NODE *p2 = query(node->r, mid+1, end, l, r, lvl+1);
	NODE *p3 = new NODE; p3->sum = p1->sum + p2->sum;
	return p3;
}

void solve(){
	cin >> n >> q;
	ll m = (1 << n)-1;
	for(int i = 0; i <= m; i++) cin >> a[i];
	tree = build(tree,0,m);
	while(q--){
		int x, y, k;
		cin >> x;
		if(x == 1){
			cin >> y >> k;
			tree = replace(tree,0,m,y-1,k,0);
		} else if(x == 2){
			cin >> k;
			for(int j = n-k; j <= n; j++) val[j] ^= 1;
		} else if(x == 3){
			cin >> k;
			val[n-k-1] ^= 1;
		} else {
			cin >> y >> k;
			NODE *p = query(tree,0,m,y-1,k-1,0);
			deb1(p->sum)
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