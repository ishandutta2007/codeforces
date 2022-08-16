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

const ll   N     =  1e6+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, a[N];

struct NODE{
	ll mx, mn;
	NODE(): mx(-INF), mn(INF){}
};

NODE tree[4*N+8];

NODE combine(NODE a, NODE b){
	NODE c;
	c.mx = max(a.mx, b.mx);
	c.mn = min(a.mn, b.mn);
	return c;
}

void build(int node, int start, int end){
	if(start == end){
		tree[node] = NODE();
		tree[node].mx = tree[node].mn = a[start];
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

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	build(1, 1, n);
	for(int i = 1; i <= n - 2; i++){
		ll mx = query(1, 1, n, 1, i).mx;
		int l = i + 2, r = n, ans = n + 1;
		while(l <= r){
			int mid = (l + r) / 2;
			NODE c = query(1, 1, n, mid, n);
			if(c.mx <= mx){
				ans = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
		if(ans == n + 1) continue;
		NODE c = query(1, 1, n, i + 1, ans - 1);
		NODE d = query(1, 1, n, ans, n);
		if(d.mx != mx) continue;
		if(c.mn == mx){
			deb1("YES")
			deb3(i, ans - i - 1, n - ans + 1)
			return;
		} else {
			if(ans == n) continue;
			ans++;
			c = query(1, 1, n, i + 1, ans - 1);
			d = query(1, 1, n, ans, n);
			if(c.mn != mx || d.mx != mx) continue;
			deb1("YES")
			deb3(i, ans - i - 1, n - ans + 1)
			return;
		}
	}
	deb1("NO")
}

int main(){
	GODSPEED;
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}