#pragma optimization_level 3
#pragma GCC optimize("Ofast")   //Comment optimisations for an interatcive problem - use endl
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" "<<endl;
#define  deb1(a)        cout<<a<<" "<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, q, d[N], h[N], pre[N];

struct val{
	pll l,r;
	int li,ri;
};

val tree[4*N+8];

pll compute(pll p1, pll p2){
	vll v;
	v.pb(p1.f);
	v.pb(p1.s);
	v.pb(p2.f);
	v.pb(p2.s);
	sort(v.begin(), v.end());
	return {v[3],v[2]};
}

int check(pll p, pll p1){
	if(p.f == p1.f) return 1;
	return 0;
}

void build(int node, int start, int end){
	if(start == end){
		tree[node].l = {2*h[start]-pre[start-1],-INF};
		tree[node].li = start;
		tree[node].r = {2*h[start]+pre[start-1],-INF};
		tree[node].ri = start;
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node].l = compute(tree[2*node].l,tree[2*node+1].l);
		if(check(tree[node].l,tree[2*node].l))
			tree[node].li = tree[2*node].li;
		else
			tree[node].li = tree[2*node+1].li;
		tree[node].r = compute(tree[2*node].r,tree[2*node+1].r);
		if(check(tree[node].r,tree[2*node].r))
			tree[node].ri = tree[2*node].ri;
		else
			tree[node].ri = tree[2*node+1].ri;
	}
}

/*void update(int node, int start, int end, int ind){
	if(start == end){
		tree[node] = n+1;
	}
	else{
		int mid = (start + end) / 2;
		if(start <= ind and ind <= mid)
			update(2*node, start, mid, ind);
		else
			update(2*node+1, mid+1, end, ind);
		tree[node] = min(tree[2*node],tree[2*node+1]);
	}
}*/

val query(int node, int start, int end, int l, int r){
	if(r < start or end < l)
		return {{-INF,-INF},{-INF,-INF},-1,-1};
	if(l <= start and end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	val p1 = query(2*node, start, mid, l, r);
	val p2 = query(2*node+1, mid+1, end, l, r);
	val v;
	v.l = compute(p1.l,p2.l);
	if(check(v.l,p1.l))
		v.li = p1.li;
	else
		v.li = p2.li;
	v.r = compute(p1.r,p2.r);
	if(check(v.r,p1.r))
		v.ri = p1.ri;
	else
		v.ri = p2.ri;
	return v;
}

void solve(){
	cin>>n>>q;
	for(int i = 1; i <= n; i++) cin>>d[i];
	for(int i = 1; i <= n; i++) cin>>h[i];
	for(int i = n+1; i <= 2*n; i++) h[i] = h[i-n], d[i] = d[i-n];
	for(int i = 1; i <= 2*n; i++) pre[i] = pre[i-1]+d[i];
    build(1,1,2*n);
	while(q--){
		int a,b;
		cin>>a>>b;
		if(a <= b){
			val v = query(1,1,2*n,b+1,n+a-1);
			if(v.li == v.ri)
				deb1(max(v.l.s+v.r.f,v.l.f+v.r.s))
			else
				deb1(v.l.f+v.r.f)
		}
		else{
			val v = query(1,1,2*n,b+1,a-1);
			if(v.li == v.ri)
				deb1(max(v.l.s+v.r.f,v.l.f+v.r.s))
			else
				deb1(v.l.f+v.r.f)
		}
	}
}

int main(){
	fastio;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}