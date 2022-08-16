#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>
 
using namespace std;
 
#define  fastio         ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(10);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" "<<endl;
#define  deb1(a)        cout<<a<<" "<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<" "<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  3e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, a[N], ans[N];
map <ll,ll> ind, sortind;
set <ll> s;
vpll v;
ll tree[4*N+8];

void build(int node, int start, int end){
	if(start == end){
		tree[node] = a[start];
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = max(tree[2*node],tree[2*node+1]);
	}
}

void update(int node, int start, int end, int idx, int val){
    if(start == end){
		tree[node] = val;
    }
    else{
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
            update(2*node, start, mid, idx, val);
        else
            update(2*node+1, mid+1, end, idx, val);
        tree[node] = max(tree[2*node],tree[2*node+1]);
    }
}

ll query(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return -INFi;
	if(l <= start and end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	ll p1 = query(2*node, start, mid, l, r);
	ll p2 = query(2*node+1, mid+1, end, l, r);
	return max(p1,p2);
}

void solve(){
    cin>>n;
    for(int i = 0; i < n; i++){
        int x,h;
        cin>>x>>h;
        v.pb({x,h});
        ind[x] = i;
        a[i] = -INFi;
    }
    build(1,1,n);
    sort(v.begin(), v.end());
    for(int i = n-1; i >= 0; i--){
        sortind[v[i].f] = i;
        s.insert(v[i].f);
        auto it = s.lower_bound(v[i].f+v[i].s);
        it--;
        if(v[i].f == *it){
            ans[ind[v[i].f]] = 1;
            update(1,1,n,i,v[i].f);
        }
        else{
            ll x = query(1,1,n,i,sortind[*it]);
            update(1,1,n,i,x);
            ans[ind[v[i].f]] += sortind[x]-i+ans[ind[x]];
        }
    }
    for(int i = 0; i < n; i++) cout<<ans[i]<<" ";
}

int main(){
	fastio;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}