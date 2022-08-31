#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
          
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;

const ll   N     =  1e6+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, m, val[20] = {1,2,3,4,5,6,7,8,9,10,9,8,7,6,5,4,3,2,1,0};
string s;

struct NODE{
	ll a,b,c,d,sz;
};  // a - full, b - without r, c - without l, d - without both

NODE tree[4*N+8];

NODE merge(NODE A, NODE B, int i){
	NODE C;
	C.a = (A.a*B.a)%mod;
	C.b = (A.a*B.b)%mod;
	C.c = (A.c*B.a)%mod;
	C.d = (A.c*B.b)%mod;
	C.sz = A.sz+B.sz;
	int t = (s[i]-'0')*10+s[i+1]-'0';
	if(t > 9 and t < 20){
		C.a = (C.a + A.b*B.c%mod*val[t])%mod;
		if(B.sz > 1) C.b = (C.b + A.b*B.d%mod*val[t])%mod;
		if(A.sz > 1) C.c = (C.c + A.d*B.c%mod*val[t])%mod;
		if(C.sz > 3) C.d = (C.d + A.d*B.d%mod*val[t])%mod;
	}
	return C;
}

void build(int node, int start, int end){
	if(start == end){
		int o = s[start]-'0';
		tree[node] = {val[o],1,1,1,1};
	}
	else{
		int mid = (start + end) / 2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = merge(tree[2*node],tree[2*node+1],mid);
	}
}

void update(int node, int start, int end, int idx, int v){
    if(start == end){
    	s[start] = v+'0';
		int o = s[start]-'0';
		tree[node] = {val[o],1,1,1,1};
    }
    else{
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
            update(2*node, start, mid, idx, v);
        else
            update(2*node+1, mid+1, end, idx, v);
        tree[node] = merge(tree[2*node],tree[2*node+1],mid);
    }
}

void solve(){
	cin>>n>>m>>s;
	s = '#'+s;
	build(1,1,n);
	while(m--){
		int u,v;
		cin>>u>>v;
		update(1,1,n,u,v);
		deb1(tree[1].a)
	}
}

int main(){
    GODSPEED;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}