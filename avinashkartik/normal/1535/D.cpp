#include<bits/stdc++.h>

using namespace std;

#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(12);
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

const ll   N     =  6e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n;
string s;
pll m[N];
map <pll, ll> M;

struct NODE {
	ll l, r, ind;
};

NODE tree[4 * N + 8];

void combine(int node, NODE a, NODE b) {
	tree[node].l = (s[a.ind] == '?') ? a.l + a.r : (s[a.ind] == '0') ? a.l : a.r;
	tree[node].r = (s[b.ind] == '?') ? b.l + b.r : (s[b.ind] == '0') ? b.l : b.r;
}

void build(int node, int start, int end) {
	if (end - start == 1) {
		tree[node] = NODE();
		tree[node].l = tree[node].r = 1;
	}
	else {
		int mid = (start + end) / 2;
		build(2 * node, start, mid);
		build(2 * node + 1, mid + 1, end);
		combine(node, tree[2 * node], tree[2 * node + 1]);
	}
	tree[node].ind = M[{start, end}];
}

void update(int node, int start, int end, int l, int r) {
	if (start == l && end == r) return;
	else {
		int mid = (start + end) / 2;
		if (r <= mid)
			update(2 * node, start, mid, l, r);
		else
			update(2 * node + 1, mid + 1, end, l, r);
		combine(node, tree[2 * node], tree[2 * node + 1]);
	}
}

void solve() {
	cin >> n >> s;
	for (int i = 1, ind = 0; i <= n; i++) {
		for (int j = 0; j < (1 << n); j += (1 << i)) {
			M[{j, j + (1 << i) - 1}] = ind;
			// deb3(j, j + (1 << i) - 1, ind)
			m[ind++] = {j, j + (1 << i) - 1};
		}
	}
	build(1, 0, (1 << n) - 1);
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int ind;
		char ch;
		cin >> ind >> ch;
		ind--;
		s[ind] = ch;
		update(1, 0, (1 << n) - 1, m[ind].f, m[ind].s);
		NODE a = tree[1];
		deb1(((s[a.ind] == '?') ? a.l + a.r : (s[a.ind] == '0') ? a.l : a.r))
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