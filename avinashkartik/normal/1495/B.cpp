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

int n, a[N], bl[N], br[N];

void solve(){
	mset(bl, 0);
	mset(br, 0);
	cin >> n;
	int mx = 0;
	for(int i = 1; i <= n; i++) cin >> a[i];
	bl[1] = max(bl[1], 1);
	for(int i = 2; i <= n; i++){
		if(a[i] > a[i - 1]) bl[i] = max(bl[i], bl[i - 1] + 1);
		else bl[i] = max(bl[i], 1);
		mx = max(mx, bl[i]);
	}
	br[n] = max(br[n], 1);
	for(int i = n - 1; i >= 0; i--){
		if(a[i] > a[i + 1]) br[i] = max(br[i], br[i + 1] + 1);
		else br[i] = max(br[i], 1);
		mx = max(mx, br[i]);
	}
	set <int> s;
	for(int i = 1; i <= n; i++){
		if(bl[i] == mx) s.insert(i);
		if(br[i] == mx) s.insert(i);
	}
	if(s.size() > 1){
		deb1(0)
	} else {
		int i = *s.begin();
		if(bl[i] == br[i]) deb1((mx % 2))
		else deb1(0)
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