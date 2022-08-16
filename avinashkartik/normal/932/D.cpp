#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
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

const int  N     =  4e5+5;
const int  mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N)+1;

ll q, last = 0, a[N], ct = 1;
ll mx[N][LEVEL], p[N][LEVEL], nxt[N][LEVEL], sum[N][LEVEL];

void add(ll r, ll w){
	a[++ct] = w;
	p[ct][0] = r;
	mx[ct][0] = a[r];
	for(int i = 1; i < LEVEL; i++){
		if(p[ct][i-1]){
			p[ct][i] = p[p[ct][i-1]][i-1];
			mx[ct][i] = max(mx[ct][i-1], mx[p[ct][i-1]][i-1]);
		}
	}
	ll y = ct;
	for(int i = LEVEL-1; i >= 0; i--){
		if(mx[y][i] < a[ct]) y = p[y][i];
	}
	nxt[ct][0] = p[y][0];
	sum[ct][0] = a[nxt[ct][0]];
	for(int i = 1; i < LEVEL; i++){
		nxt[ct][i] = nxt[nxt[ct][i-1]][i-1];
		sum[ct][i] = sum[ct][i-1] + sum[nxt[ct][i-1]][i-1];
	}
}

void query(ll x, ll w){
	if(a[x] > w){
		last = 0;
		deb1(0)
		return;
	}
	ll res = 1;
	w -= a[x];
	for(int i = LEVEL-1; i >= 0; i--){
		if(nxt[x][i] and sum[x][i] <= w){
			res += (1ll << i);
			w -= sum[x][i];
			x = nxt[x][i];
		}
	}
	last = res;
	deb1(res)
}

void solve(){
	for(int i = 0; i < N; i++)
		for(int j = 0; j < LEVEL; j++)
			mx[i][j] = INF;
	cin >> q;
	for(int i = 1; i <= q; i++){
		ll x, p, q; cin >> x >> p >> q;
		p ^= last;
		q ^= last;
		if(x == 1) add(p, q);
		else query(p, q);
	}
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}