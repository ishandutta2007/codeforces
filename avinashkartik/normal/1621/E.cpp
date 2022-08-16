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

const ll   N     =  2e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  1e16;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n, m, a[N];

int tree[4*N+8], lazy[4*N+8];

void build(int node, int start, int end){
	lazy[node] = 0;
	if(start == end){
		tree[node] = 0;
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
	tree[node] += lazy[node];
	if(start != end){
		lazy[node*2] += lazy[node];
		lazy[node*2+1] += lazy[node];
	}
	lazy[node] = 0;
}

void update(int node, int start, int end, int l, int r, int val){
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
	tree[node] = min(tree[2*node], tree[2*node+1]);
}

int query(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return INFi;
	pushlazy(start,end,node);
	if(l <= start and end <= r){
		return tree[node];
	}
	int mid = (start + end) / 2;
	int p1 = query(2*node, start, mid, l, r);
	int p2 = query(2*node+1, mid+1, end, l, r);
	return min(p1, p2);
}

void solve() {
	cin >> n >> m;
	int mx = 1e5 + 5;
	build(1, 1, mx);
	vector <vector <ll>> v(n);
	vector <ll> sum(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		update(1, 1, mx, 1, a[i], 1);
	}
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		v[i].assign(x, 0);
		for (int j = 0; j < x; j++) {
			cin >> v[i][j];
			sum[i] += v[i][j];
		}
		ll avg = (sum[i] + x - 1) / x;
		update(1, 1, mx, 1, avg, -1);
	}
	string ans;
	for (int i = 0; i < m; i++) {
		int x = v[i].size();
		for (int j = 0; j < x; j++) {
			ll avg = (sum[i] + x - 1) / x;
			update(1, 1, mx, 1, avg, 1);
			ll s1 = sum[i] - v[i][j];
			ll a1 = (s1 + x - 2) / (x - 1);
			update(1, 1, mx, 1, a1, -1);
			if (query(1, 1, mx, 1, mx) < 0) ans += '0';
			else ans += '1';
			update(1, 1, mx, 1, a1, 1);
			update(1, 1, mx, 1, avg, -1);
		}
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}