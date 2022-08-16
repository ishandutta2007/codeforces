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
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  5e5 + 5;
const ll   mod   = 	1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, a[N], ans[N];

struct NODE{
	ll len, p, s, v, ans;
	NODE(): len(), p(), s(), v(), ans() {}
	NODE(int val): len(1), p(max(0, val)), s(max(0, val)), v(val), ans(max(0, val)) {}
};
 
NODE tree[4*N+8];
 
NODE combine(NODE a, NODE b){
	NODE c;
	c.len = a.len + b.len;
	c.p = max(a.p, a.v + b.p);
	c.s = max(b.s, a.s + b.v);
	c.v = a.v + b.v;
	c.ans = max({a.ans, b.ans, a.s + b.p});
	return c;
}
 
void build(int node, int start, int end){
	if(start == end){
		tree[node] = NODE(1);
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = combine(tree[2*node],tree[2*node+1]);
	}
}
 
void update(int node, int start, int end, int idx, ll val){
	if(start == end){
		tree[node] = NODE(val);
	}
	else{
		int mid = (start + end) / 2;
		if(start <= idx and idx <= mid)
			update(2*node, start, mid, idx, val);
		else
			update(2*node+1, mid+1, end, idx, val);
		tree[node] = combine(tree[2*node], tree[2*node+1]);
	}
}

NODE query(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return NODE();
	if(l <= start and end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	NODE p1 = query(2*node, start, mid, l, r);
	NODE p2 = query(2*node+1, mid+1, end, l, r);
	return combine(p1, p2);
}


void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector <int> ind(n);
	iota(all(ind), 1);
	sort(all(ind), [&](int i, int j) {
		return a[i] < a[j];
	});
	build(1, 1, n);
	for (int i = 0, j = 0; i < n; i++) {
		while (j < n && a[ind[i]] > a[ind[j]]) {
			update(1, 1, n, ind[j], -1);
			j++;
		}
		NODE l = query(1, 1, n, 1, ind[i]);
		NODE r = query(1, 1, n, ind[i], n);
		ans[ind[i]] = max(ans[ind[i]], (l.s + r.p - 1) / 2);
	}
	sort(all(ind), [&](int i, int j) {
		return a[i] > a[j];
	});
	build(1, 1, n);
	for (int i = 0, j = 0; i < n; i++) {
		while (j < n && a[ind[i]] < a[ind[j]]) {
			update(1, 1, n, ind[j], -1);
			j++;
		}
		NODE l = query(1, 1, n, 1, ind[i]);
		NODE r = query(1, 1, n, ind[i], n);
		ans[ind[i]] = max(ans[ind[i]], (l.s + r.p - 2) / 2);
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	newl;
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}