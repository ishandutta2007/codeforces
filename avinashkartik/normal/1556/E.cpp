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

const ll   N     =  1e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, q, a[N], b[N];

struct NODE{
	ll pp, pn, np, nn;
	NODE(): pp(0), pn(0), np(0), nn(0) {}
};

NODE tree[4*N+8];

NODE combine(NODE a, NODE b){
	NODE c;

	//pp
	ll pp1 = min(a.pp, b.np);
	a.pp -= pp1, b.np -= pp1;

	ll pp2 = min(a.pn, b.pp);
	a.pn -= pp2, b.pp -= pp2;

	//pn
	ll pn1 = min(a.pp, b.nn);
	a.pp -= pn1, b.nn -= pn1;

	ll pn2 = min(a.pn, b.pn);
	a.pn -= pn2, b.pn -= pn2;

	//np
	ll np1 = min(a.np, b.np);
	a.np -= np1, b.np -= np1;

	ll np2 = min(a.nn, b.pp);
	a.nn -= np2, b.pp -= np2;

	//nn
	ll nn1 = min(a.np, b.nn);
	a.np -= nn1, b.nn -= nn1;

	ll nn2 = min(a.nn, b.pn);
	a.nn -= nn2, b.pn -= nn2;

	c.pp = pp1 + pp2 + a.pp + b.pp;
	c.pn = pn1 + pn2 + a.pn + b.pn;
	c.np = np1 + np2 + a.np + b.np;
	c.nn = nn1 + nn2 + a.nn + b.nn;
	return c;
}

void build(int node, int start, int end){
	if(start == end){
		tree[node] = NODE();
		ll d = b[start] - a[start];
		if (d < 0) {
			tree[node].nn = -d;
		} else tree[node].pp = d;
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
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	build(1, 1, n);
	for (int i = 1; i <= q; i++) {
		int l, r; cin >> l >> r;
		NODE q = query(1, 1, n, l, r);
		if (q.np > 0 || q.nn > 0 || q.pp > 0) deb1(-1)
		else deb1(q.pn)
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