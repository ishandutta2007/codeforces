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

const ll   N     =  2e5+5;
const ll   M     =  4e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n;
string s, t;
vll v[26];

ll tree[4*N+8], lazy[4*N+8];

void build(int node, int start, int end){
	if(start == end){
		tree[node] = start;
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = tree[2*node]+tree[2*node+1];
	}
}

void pushlazy(int start, int end, int node){
	if(lazy[node] == 0) return;
	tree[node] += (end-start+1)*lazy[node];
	if(start != end){
		lazy[node*2] += lazy[node];
		lazy[node*2+1] += lazy[node];
	}
	lazy[node] = 0;
}

void update(int node, int start, int end, int l, int r, ll val){
	pushlazy(start,end,node);
	if(start > end or start > r or end < l)
		return;
	if(start >= l and end <= r){
		lazy[node] += val;
		pushlazy(start,end,node);
		return;
	}
	int mid = (start + end) / 2;
	update(node*2, start, mid, l, r, val);
	update(node*2 + 1, mid + 1, end, l, r, val);
	tree[node] = tree[2*node]+tree[2*node+1];
}

ll query(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return 0;
	pushlazy(start,end,node);
	if(l <= start and end <= r){
		return tree[node];
	}
	int mid = (start + end) / 2;
	ll p1 = query(2*node, start, mid, l, r);
	ll p2 = query(2*node+1, mid+1, end, l, r);
	return p1+p2;
}

void solve(){
	cin >> n >> s;
	t = s;
	reverse(all(t));
	vector <int> vis(n, 0);
	ll ans = 0;
	for(int i = 0; i < n; i++){
		v[s[i]-'a'].pb(i);
	}
	build(1, 0, n);
	for(int i = n-1; i >= 0; i--){
		int c = t[i] - 'a';
		int ind = v[c].back(); v[c].pop_back();
		int dind = query(1, 0, n, ind, ind);
		ans += i-dind;
		update(1, 0, n, ind, n, -1);
	}
	deb1(ans)
}

int main(){
	GODSPEED;
	int test = 1;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}