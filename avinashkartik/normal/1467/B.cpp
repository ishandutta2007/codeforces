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

const ll   N     =  4e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

int n, a[N], b[N];

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], b[i] = 0;
	int ct = 0, f = 0;
	a[0] = a[1], a[n + 1] = a[n], a[n + 2] = a[n];
	for(int i = 2; i < n; i++){
		if(a[i] < a[i + 1] && a[i] < a[i - 1]) ct++, b[i] = -1;
		if(a[i] > a[i + 1] && a[i] > a[i - 1]) ct++, b[i] = 1;
	}
	for(int i = 2; i < n; i++){
		if(f) break;
		if(b[i] == -1 && b[i - 1] == 1 && b[i + 1] == 1) ct -= 3, f = 1;
		if(b[i] == 1 && b[i - 1] == -1 && b[i + 1] == -1) ct -= 3, f = 1;
	}
	for(int i = 2; i < n; i++){
		if(f) break;
		if(b[i] == -1 && b[i + 1] == 1){
			int ff = 0;
			if(a[i - 1] < a[i - 2] && a[i - 1] < a[i + 1]) ff++;
			if(a[i + 2] > a[i] && a[i + 2] > a[i + 3]) ff++;
			if(ff == 2) continue;
			ct -= 2, f = 1;
		}
		if(b[i] == 1 && b[i + 1] == -1){
			int ff = 0;
			if(a[i - 1] > a[i - 2] && a[i - 1] > a[i + 1]) ff++;
			if(a[i + 2] < a[i] && a[i + 2] < a[i + 3]) ff++;
			if(ff == 2) continue;
			ct -= 2, f = 1;
		}
	}
	if(!f) ct = max(0, ct - 1);
	deb1(ct)
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