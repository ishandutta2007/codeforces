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
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

ll n;
string s, t;

struct NODE{
	ll ans;
	NODE(): ans(0) {}
};

NODE tree[4*N+8];

NODE combine(NODE a, NODE b){
	NODE c;
	c.ans = a.ans + b.ans;
	return c;
}

void build(int node, int start, int end){
	if(start == end){
		tree[node] = NODE();
		tree[node].ans = 0;
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = combine(tree[2*node], tree[2*node+1]);
	}
}

void update(int node, int start, int end, int idx, ll val){
	if(start == end){
		tree[node].ans += val;
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
	cin >> n >> s >> t;
	string s1 = s;
	sort(all(s1));
	if (s1 >= t) {
		deb1(-1)
		return;
	}
	deque <ll> v[26];
	for (int i = 0; i < n; i++) {
		v[s[i] - 'a'].pb(i);
	}
	ll ans = INF, res = 0;
	build(1, 0, n);
	for (int i = 0; i < n; i++) {
		ll mn = INF;
		for (int j = 0; j < t[i] - 'a'; j++) {
			if (v[j].size() == 0) continue;
			mn = min(mn, v[j][0] + query(1, 0, n, v[j][0], n).ans - i);
		}
		ans = min(ans, mn + res);
		if (v[t[i] - 'a'].size() == 0) break;
		res += v[t[i] - 'a'][0] - i + query(1, 0, n, v[t[i] - 'a'][0], n).ans;
		update(1, 0, n, v[t[i] - 'a'][0], 1);
		v[t[i] - 'a'].pop_front();
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