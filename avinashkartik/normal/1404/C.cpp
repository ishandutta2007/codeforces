#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;

template<typename has_less>
using ordered_set =
tree<has_less,
    null_type,
    less_equal<has_less>,
    rb_tree_tag,
    tree_order_statistics_node_update>;


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

ll n, q, a[N], prv[N], vis[N], ans[N];
vll adj[N];

ordered_set <int> s;

ll tree1[4*N] = {};

ll combine(ll a, ll b){
	return a+b;
}

void update(int node, int start, int end, int idx, ll val){
	if(start == end){
		tree1[node] = val;
	}
	else{
		int mid = (start + end) / 2;
		if(start <= idx and idx <= mid)
			update(2*node, start, mid, idx, val);
		else
			update(2*node+1, mid+1, end, idx, val);
		tree1[node] = combine(tree1[2*node], tree1[2*node+1]);
	}
}

int query(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return 0;
	if(l <= start and end <= r)
		return tree1[node];
	int mid = (start + end) / 2;
	int p1 = query(2*node, start, mid, l, r);
	int p2 = query(2*node+1, mid+1, end, l, r);
	return combine(p1, p2);
}

void solve(){
	int ct = 0;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++){
		if(a[i] > i) continue;
		if(a[i] == i){
			update(1, 1, n, i, 1);
			s.insert(i);
			ct++;
			continue;
		}
		if(i-a[i] > ct) continue;
		int ind = *s.find_by_order(ct+a[i]-i);
		adj[ind].pb(i);
		ct++;
		s.insert(ind);
		update(1, 1, n, i, 1);
	}
	vector <pair <ll, pll>> Q;
	for(int i = 1; i <= q; i++){
		int x, y; cin >> x >> y;
		Q.pb({x, {y, i}});
	}
	sort(all(Q));
	int j = 1;
	for(auto it : Q){
		while(j <= it.f){
			for(auto to : adj[j]){
				update(1, 1, n, to, 0);
			}
			j++;
		}
		ans[it.s.s] = query(1, 1, n, it.f+1, n-it.s.f);
	}
	for(int i = 1; i <= q; i++) deb1(ans[i]);
}

int main(){
	GODSPEED;
	int test = 1;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}