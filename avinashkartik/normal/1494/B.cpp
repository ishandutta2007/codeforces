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
const ll   LEVEL =  log2(N)+1;

int n, u, r, d, l;

bool ch(int x, int u, int d, int r, int l){
	for(int i = 0; i < 4; i++){
		if(x&(1 << i)){
			if(i == 0) u--, r--;
			if(i == 1) u--, l--;
			if(i == 2) d--, r--;
			if(i == 3) d--, l--;
		}
	}
	if(u > n - 2 || u < 0) return 0;
	if(d > n - 2 || d < 0) return 0;
	if(r > n - 2 || r < 0) return 0;
	if(l > n - 2 || l < 0) return 0;
	return 1;
}

void solve(){
	cin >> n >> u >> r >> d >> l;
	int f = 0;
	for(int i = 0; i < 16; i++){
		f |= ch(i, u, d, r, l);
	}
	if(f) deb1("YES")
	else deb1("NO")
}

int main(){
	GODSPEED;
	int test = 1;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}