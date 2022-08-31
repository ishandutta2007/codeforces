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

const ll   N     =  4e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll n, q, l[N], r[N], ans[N], pre[N];
string s;

struct NODE{
	int ans;
	NODE(): ans(-INFi) {}
};

NODE tree[4*N+8];

NODE combine(NODE a, NODE b){
	NODE c;
	c.ans = max(a.ans, b.ans);
	return c;
}

void build(int node, int start, int end){
	if(start == end){
		tree[node] = NODE();
		tree[node].ans = pre[start];
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

void calc(char ch){
	int cur = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == ch) cur++;
		else cur--;
		pre[i] = cur;
	}
	build(1, 0, n - 1);
	for(int i = 0; i < q; i++){
		int m1 = query(1, 0, n - 1, 0, l[i] - 1).ans, p = - pre[r[i]];
		if(l[i]) p += pre[l[i] - 1];
		int m2 = query(1, 0, n - 1, r[i] + 1, n - 1).ans;
		ans[i] += max({0, m1, p + m2});
	}
}

void solve(){
	cin >> n >> q >> s;
	for(int i = 0; i < q; i++){
		cin >> l[i] >> r[i];
		ans[i] = 0;
		l[i]--, r[i]--;
	}
	calc('+');
	calc('-');
	for(int i = 0; i < q; i++){
		deb1(ans[i] + 1)
	}
}

int main(){
	GODSPEED;
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}