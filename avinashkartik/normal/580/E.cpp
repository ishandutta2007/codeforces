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

const ll   N     =  2e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, m, k;
ull v1[N], pre1[N];
ll v2[N], pre2[N];
string s;

struct NODE{
	ull val1;
	ll val2, len;
	NODE(): val1(), val2(), len() {}
	NODE(int v): val1(v), val2(v), len(1) {}
};

NODE tree[4*N+8];
int lazy[4*N+8];

NODE combine(NODE a, NODE b){
	NODE c;
	c.len = a.len + b.len;
	c.val1 = a.val1 + b.val1 * v1[a.len];
	c.val2 = (a.val2 + b.val2 * v2[a.len]) % mod;
	return c;
}

void build(int node, int start, int end){
	if(start == end){
		tree[node] = NODE(s[start] - '0');
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = combine(tree[2*node], tree[2*node+1]);
	}
}

void pushlazy(int start, int end, int node){
	if(lazy[node] == -1) return;
	tree[node].val1 = pre1[tree[node].len - 1] * lazy[node];
	tree[node].val2 = pre2[tree[node].len - 1] * lazy[node] % mod;
	if(start != end){
		lazy[node*2] = lazy[node];
		lazy[node*2+1] = lazy[node];
	}
	lazy[node] = -1;
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

void solve(){
	mset(lazy, -1);
	cin >> n >> m >> k;
	v1[0] = pre1[0] = 1, v2[0] = 1, pre2[0] = 1;
	for(int i = 1; i <= n; i++){
		v1[i] = v1[i-1] * 31;
		pre1[i] = pre1[i-1] + v1[i];
		v2[i] = v2[i-1] * 39 % mod;
		pre2[i] = (pre2[i-1] + v2[i]) % mod;
	}
	cin >> s;
	build(1, 0, n-1);
	for(int i = 0; i < m + k; i++){
		int x, l, r, d; cin >> x >> l >> r >> d; l--, r--;
		if(x == 1){
			update(1, 0, n-1, l, r, d);
		} else {
			NODE q1 = query(1, 0, n-1, l+d, r);
			NODE q2 = query(1, 0, n-1, l, r-d);
			if(q1.val1 == q2.val1 && q1.val2 == q2.val2) deb1("YES")
			else deb1("NO")
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