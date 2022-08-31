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

const ll   N     =  3e6 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int cnt[N];
int n, q, a[N];

struct NODE{
	pair<int, int> s;
	NODE(): s({0, 0}) {}
};

NODE tree[4*N+8];

NODE combine(NODE a, NODE b){
	NODE c;
	if (a.s.f == b.s.f) c.s = {a.s.f, a.s.s + b.s.s};
	else if(a.s.s > b.s.s) c.s = {a.s.f, a.s.s - b.s.s};
	else c.s = {b.s.f, b.s.s - a.s.s};;
	return c;
}

void build(int node, int start, int end){
	if(start == end){
		tree[node] = NODE();
		tree[node].s = {a[start], 1};
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
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
	cin >> n >> q;
	vector <vector <int>> pos(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i], pos[a[i]].pb(i);
	build(1, 1, n);
	while (q--) {
		int l, r; cin >> l >> r;
		NODE v = query(1, 1, n, l, r);
		int y = v.s.f;
		int x = upper_bound(all(pos[y]), r) - lower_bound(all(pos[y]), l), len = r - l + 1;
		int rest = len - x;
		int left = len - 2 * rest - 1;
		deb1(1 + max(left, 0))
	}
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}