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

const ll   N     =  3e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, a[N], b[N], h[N];

struct NODE{
	ll ans;
	NODE(): ans(0) {}
};

NODE tree[4*N+8];

NODE combine(NODE a, NODE b){
	NODE c;
	c.ans = max(a.ans, b.ans);
	return c;
}

void update(int node, int start, int end, int idx, ll val){
	if(start == end){
		tree[node].ans = max(tree[node].ans, val);
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
	vector <int> v;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i] >> h[i];
		v.pb(a[i]);
		v.pb(b[i]);
	}
	sort(all(v));
	uniq(v);
	vector <int> ind(n);
	iota(all(ind), 1);
	sort(all(ind), [&](int i, int j){
		if (b[i] == b[j]) return a[i] > a[j];
		return b[i] > b[j];
	});
	ll ans = 0;
	for (auto it : ind) {
		int ai = lower_bound(all(v), a[it]) - v.begin(), bi = lower_bound(all(v), b[it]) - v.begin();
		ll val = query(1, 0, 2 * n, 0, bi - 1).ans + h[it];
		ans = max(ans, val);
		// deb4(it, ai, bi, val)
		update(1, 0, 2 * n, ai, val);
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}