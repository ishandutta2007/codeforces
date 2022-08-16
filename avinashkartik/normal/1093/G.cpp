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

const ll   N     =  2e5 + 5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, k, q, mx;
multiset <int> s[40];

struct pt{
	int c[6];
};

vector <pt> v;

struct NODE{
	int st[40], en[40];
	NODE(){
		for(int i = 0; i < 40; i++){
			st[i] = INFi;
			en[i] = -INFi;
		}
	}
};

NODE tree[4*N+8];

void calc(pt p, int node){
	for(int ii = 0; ii < mx; ii++){
		int res = 0;
		for(int j = 0; j < k; j++){
			int x = ((ii >> j)&1);
			if(x == 0) res += p.c[j];
			else res -= p.c[j]; 
		}
		tree[node].st[ii] = tree[node].en[ii] = res;
	}
}


NODE combine(NODE a, NODE b){
	NODE c;
	for(int i = 0; i < mx; i++){
		c.st[i] = min(a.st[i], b.st[i]);
		c.en[i] = max(a.en[i], b.en[i]);
	}
	return c;
}

void build(int node, int start, int end){
	if(start == end){
		tree[node] = NODE();
		calc(v[start], node);
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = combine(tree[2*node], tree[2*node+1]);
	}
}

void update(int node, int start, int end, int idx){
	if(start == end){
		tree[node] = NODE();
		calc(v[start], node);
	}
	else{
		int mid = (start + end) / 2;
		if(start <= idx and idx <= mid)
			update(2*node, start, mid, idx);
		else
			update(2*node+1, mid+1, end, idx);
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
    cin >> n >> k;
    mx = (1 << (k - 1));
    for(int i = 1; i <= n; i++){
    	pt p;
    	for(int j = 0; j < k; j++){
    		cin >> p.c[j];
    	}
    	v.pb(p);
    }
    build(1, 0, n - 1);
    cin >> q;
    for(int ii = 1; ii <= q; ii++){
    	int x; cin >> x;
    	if(x == 1){
    		int i; cin >> i; i--;
	    	for(int j = 0; j < k; j++){
	    		cin >> v[i].c[j];
	    	}
	    	update(1, 0, n - 1, i);
    	} else {
    		int l, r; cin >> l >> r; l--, r--;
    		NODE c = query(1, 0, n - 1, l, r);
    		int ans = -INFi;
    		for(int i = 0; i < mx; i++){
    			ans = max(ans, c.en[i] - c.st[i]);
    		}
    		deb1(ans)
    	}
    }
}

int main(){
    GODSPEED;
    int test = 1;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
}