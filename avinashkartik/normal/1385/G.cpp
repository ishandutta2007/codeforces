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

int test = 1, n, a[N], b[N], ct[N], c1[N], c2[N], vis[N];
vll res;

int find(int val, int ind){
	if(c1[val] == ind) return c2[val];
	return c1[val];
}

void calc(int c){
	int p = a[c];
	vll black, white;
	while(!vis[c]){
		vis[c] = 1;
		if(a[c] == p) p = b[c], c = find(b[c],c);
		else p = a[c], c = find(a[c],c);
		if(a[c] == p) black.pb(c);
		else white.pb(c); 
	}
	if(black.size() < white.size()) for(auto it : black) res.pb(it);
	else for(auto it : white) res.pb(it);
}

void solve(){
	res.clear();
	cin>>n;
	for(int i = 1; i <= n; i++) ct[i] = 0, c1[i] = c2[i] = -1, vis[i] = 0;
	for(int i = 1; i <= n; i++) cin>>a[i], ct[a[i]]++;
	for(int i = 1; i <= n; i++) cin>>b[i], ct[b[i]]++;
	for(int i = 1; i <= n; i++) if(ct[i] != 2){ deb1(-1); return;}
	for(int i = 1; i <= n; i++){
		if(c1[a[i]] == -1) c1[a[i]] = i;
		else c2[a[i]] = i;
		if(c1[b[i]] == -1) c1[b[i]] = i;
		else c2[b[i]] = i;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == b[i]) continue;
		if(!vis[i]) calc(i);
	}
	deb1(res.size())
	debv(res)
}

int main(){
	GODSPEED;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}