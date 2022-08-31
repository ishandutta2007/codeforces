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
const ll   M     =  4e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, a[N], prv[N], d[N], ans[N];

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		prv[i] = 0;
		ans[i] = INFi;
		d[i] = 0;
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		d[a[i]] = max(d[a[i]], i - prv[a[i]]);
		prv[a[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		d[i] = max(d[i], n+1 - prv[i]);
		ans[d[i]] = min(ans[d[i]], i);
	}
	for(int i = 2; i <= n; i++) ans[i] = min(ans[i], ans[i-1]);
	for(int i = 1; i <= n; i++) cout << ((ans[i] == INFi)? -1 : ans[i]) << " ";
	newl;
}

int main(){
	GODSPEED;
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}