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

const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, q, a[N], f[N], l[N], ch[N];

ll tree[4*N+8];

void build(int node, int start, int end){
	if(start == end){
		tree[node] = a[start];
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = min(tree[2*node],tree[2*node+1]);
	}
}

/*void update(int node, int start, int end, int idx, int ind){
    if(start == end){
        int x = 1, y = start;
		if(ind == 1) y--;
		if(y%2 == 0) x = -1;
		tree[ind][node] = x*y*a[start];
    }
    else{
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
            update(2*node, start, mid, idx, ind);
        else
            update(2*node+1, mid+1, end, idx, ind);
        tree[ind][node] = tree[ind][2*node]+tree[ind][2*node+1];
    }
}*/

ll query(int node, int start, int end, int l, int r){
	if(start > end or start > r or end < l)
		return INF;
	if(l <= start and end <= r)
		return tree[node];
	int mid = (start + end) / 2;
	ll p1 = query(2*node, start, mid, l, r);
	ll p2 = query(2*node+1, mid+1, end, l, r);
	return min(p1,p2);
}

void solve(){
	mset(f,0);
	mset(l,0);
	mset(ch,0);
	cin>>n>>q;
	int p = -1;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		if(a[i] == 0) a[i] = q+1, p = i;
		if(!f[a[i]]) f[a[i]] = i;
		l[a[i]] = i;
	}
	a[0] = a[n+1] = 1;
	int flag = -1;
	if(!f[q]){
		if(a[1] == q+1) flag = 1;
		else flag = n;
	}
	build(1,1,n);
	ll ans = 0;
	for(int i = 1; i <= q; i++){
		if(f[i]){
			ch[f[i]] += 1;
			ch[l[i]+1] -= 1;
			ll p = query(1,1,n,f[i],l[i]);
			if(p < i){
				deb1("NO");
				return;
			}
		}
	}
	if(!f[q] && p == -1){
		deb1("NO");
		return;
	}
	for(int i = 1; i <= n; i++)
		if(a[i] == q+1) a[i] = a[i-1];
	if(!f[q]) a[p] = q;
	deb1("YES")
	for(int i = 1; i <= n; i++) cout<<a[i]<<" ";cout<<endl;
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