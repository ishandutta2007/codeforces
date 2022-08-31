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
typedef  pair<ll, ll>          pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  2e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, q;
string s;

struct NODE{
	int a[3][3];
	NODE() {
		a[0][0] = a[0][1] = a[0][2] = 0;
		a[1][1] = a[1][2] = 0;
		a[2][2] = 0;
	}
};

NODE tree[4*N+8];

NODE combine(NODE a, NODE b){
	NODE c;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			c.a[i][j] = n;
			for (int k = i; k <= j; k++) {
				c.a[i][j] = min(c.a[i][j], a.a[i][k] + b.a[k][j]);
			}
		}
	}
	return c;
}

void update(int node, int start, int end, int idx, int a, int b, int c){
	if(start == end){
		tree[node].a[0][0] = tree[node].a[0][1] = tree[node].a[0][2] = a;
		tree[node].a[1][0] = tree[node].a[1][1] = tree[node].a[1][2] = b;
		tree[node].a[2][0] = tree[node].a[2][1] = tree[node].a[2][2] = c;
	}
	else{
		int mid = (start + end) / 2;
		if(start <= idx and idx <= mid)
			update(2*node, start, mid, idx, a, b, c);
		else
			update(2*node+1, mid+1, end, idx, a, b, c);
		tree[node] = combine(tree[2*node], tree[2*node+1]);
	}
}

NODE query(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return NODE();
	if(l <= start and end <= r){
		return tree[node];
	}
	int mid = (start + end) / 2;
	NODE p1 = query(2*node, start, mid, l, r);
	NODE p2 = query(2*node+1, mid+1, end, l, r);
	return combine(p1, p2);
}

void solve() {
	cin >> n >> q >> s;
	s = '#' + s + '#';
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'a') {
			update(1, 1, n, i, 1, 0, 0);
		} else if (s[i] == 'b') {
			update(1, 1, n, i, 0, 1, 0);
		} else {
			update(1, 1, n, i, 0, 0, 1);
		}
	}
	for (int i = 1; i <= q; i++) {
		int x; char c;
		cin >> x >> c;
		if (c == 'a') {
			update(1, 1, n, x, 1, 0, 0);
		} else if (c == 'b') {
			update(1, 1, n, x, 0, 1, 0);
		} else {
			update(1, 1, n, x, 0, 0, 1);
		}
		int ans = n;
		for (int i = 0; i < 3; i++) {
			for (int j = i; j < 3; j++) {
				ans = min(ans, tree[1].a[i][j]);
			}
		}
		deb1(ans)
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