#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              f                 
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

const ll   N     =  5e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n1, m, a[N], b[N], ind[N], vis[N], nxt[N], prv[N];

void make(ll n){
	for(int i = 0; i <= n + 1; i++){
		nxt[i] = i;
		prv[i] = i;
	}
}

int find(ll x, int f){
	if(f == 1) return (prv[x] == x)? x: prv[x] = find(prv[x], f);
	else return (nxt[x] == x)? x: nxt[x] = find(nxt[x], f);
}

void solve(){
	cin >> n1 >> m;
	for(int i = 1; i <= n1; i++) cin >> a[i], ind[a[i]] = i, vis[i] = 1;
	for(int i = 1; i <= m; i++) cin >> b[i], vis[b[i]] = 0;
	vis[0] = vis[n1 + 1] = 0;
	make(n1);
	ll ans = 1;
	for(int i = 1; i <= m; i++){
		int idx = ind[b[i]];
		ll res = 0;
		ll p = find(idx - 1, 1);
		ll n = find(idx + 1, 0);
		if(p and vis[a[p]] == 1) res++;
		if(n != n1 + 1 and vis[a[n]] == 1) res++;
		ans = ans * res % mod;
		if(res == 2){
			nxt[idx] = idx + 1;
			prv[idx] = idx - 1;
		} else if(vis[a[p]]){
			nxt[p] = p + 1;
			prv[p] = p - 1;
		} else if(vis[a[n]]){
			nxt[n] = n + 1;
			prv[n] = n - 1;
		}
		vis[b[i]] = 1;
	}
	deb1(ans)
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