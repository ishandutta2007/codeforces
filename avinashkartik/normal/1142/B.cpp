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

const ll   N     =  3e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll test = 1, n, m, q, a[N], b[N];
ll st[N][LEVEL], prv[N], last[N], kpar[N];

void precalc(){
	for(int j = 1; j < LEVEL; j++){
		for(int i = 1; i <= m; i++){
			if(st[i][j-1] == -1) continue;
			st[i][j] = st[st[i][j-1]][j-1];
		}
	}
}

int kth(int x, int k){
	for(int i = 0; i < LEVEL; i++){
		if(k&(1<<i)){
			x = st[x][i];
			if(x == -1) return -1;
		}
	}
	return x;
}

void solve(){
	mset(last,-1);
	mset(st,-1);
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) prv[a[i]] = a[(i-2+n)%n+1];
	for(int i = 1; i <= m; i++){
		cin >> b[i];
		st[i][0] = last[prv[b[i]]];
		last[b[i]] = i;
	}
	precalc();
	kpar[0] = 0;
	for(int i = 1; i <= m; i++) kpar[i] = max(kpar[i-1],(ll)kth(i,n-1));
	while(q--){
		int l, r; cin >> l >> r;
		cout << (kpar[r] >= l);
	}
	newl;
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