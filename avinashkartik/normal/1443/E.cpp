#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
 
template<typename has_less>
using ordered_set = tree<has_less, null_type, less<has_less>, rb_tree_tag, tree_order_statistics_node_update>;
 
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

const ll   N     =  5e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int f3[15], n, q;

struct NODE{
	ll v;
};

NODE Tree[4*N+8];

NODE combine(NODE a, NODE b){
	NODE c;
	c.v = a.v + b.v;
	return c;
}

void build(int node, int start, int end){
	if(start == end){
		Tree[node].v = start;
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		Tree[node] = combine(Tree[2*node], Tree[2*node+1]);
	}
}

void update(int node, int start, int end, int idx, ll val){
	if(start == end){
		Tree[node].v = val;
	}
	else{
		int mid = (start + end) / 2;
		if(start <= idx and idx <= mid)
			update(2*node, start, mid, idx, val);
		else
			update(2*node+1, mid+1, end, idx, val);
		Tree[node] = combine(Tree[2*node], Tree[2*node+1]);
	}
}

NODE query(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return NODE();
	if(l <= start and end <= r)
		return Tree[node];
	int mid = (start + end) / 2;
	NODE p1 = query(2*node, start, mid, l, r);
	NODE p2 = query(2*node+1, mid+1, end, l, r);
	return combine(p1, p2);
}

void factoradix(ll cur){
	ordered_set <int> s;
	for(int i = 0; i < 15; i++){
		f3[15 - i - 1] = cur % (i + 1);
		cur /= (i + 1);
	}
	for(int i = 0; i < 15; i++) s.insert(i);
	for(int i = 0; i < 15; i++){
		int val = *s.find_by_order(f3[i]);
		update(1, 1, n, n - 14 + i, n - 14 + val);
		s.erase(val);
	}
}

void solve(){
	cin >> n >> q;
	ll cur = 0;
	build(1, 1, n);
	for(int i = 1; i <= q; i++){
		int x, y, z; cin >> x;
		if(x == 1){
			cin >> y >> z;
			deb1(query(1, 1, n, y, z).v)
		} else {
			cin >> y;
			cur += y;
			factoradix(cur);
		}
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