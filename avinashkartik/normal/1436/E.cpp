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

const ll   N     =  2e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, a[N];

struct NODE{
	int mex;
	NODE(): mex(0){}
	NODE(int v): mex(v) {}
};

NODE tree[4*N+8];

NODE combine(NODE a, NODE b){
	NODE c;
	c.mex = min(a.mex, b.mex);
	return c;
}

void build(int node, int start, int end){
	if(start == end){
		tree[node] = NODE();
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
		tree[node].mex = val;
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
		return NODE(INFi);
	if(l <= start and end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	NODE p1 = query(2*node, start, mid, l, r);
	NODE p2 = query(2*node+1, mid+1, end, l, r);
	return combine(p1, p2);
}

void solve(){
	cin >> n;
	build(1, 1, n);
	vector <int> ok(n + 5, 0);
	vector <int> last(n + 5, 0);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] != 1){
			ok[1] = 1;
			NODE c = query(1, 1, n, 1, a[i] - 1);
			if(c.mex > last[a[i]]) ok[a[i]] = 1;
		} else ok[2] = 1;
		update(1, 1, n, a[i], i);
		last[a[i]] = i;
	}
	for(int i = 2; i <= n + 1; i++){
		NODE c = query(1, 1, n, 1, i - 1);
		if(c.mex > last[i]) ok[i] = 1;
	}
	for(int i = 1; i <= n + 2; i++){
		if(!ok[i]){
			deb1(i)
			break;
		}
	}
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}