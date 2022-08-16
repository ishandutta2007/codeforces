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

ll n, m, k, a[N], b[N], c[N];

void solve(){
	cin >> n >> m >> k;
	ll sa = 0, sb = 0, sc = 0, ans = -INFi;
	for(int i = 1; i <= n; i++) cin >> a[i], sa += a[i];
	for(int i = 1; i <= m; i++) cin >> b[i], sb += b[i];
	for(int i = 1; i <= k; i++) cin >> c[i], sc += c[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	sort(c + 1, c + k + 1);
	vector <ll> v;
	v.pb(a[1]); 
	v.pb(b[1]); 
	v.pb(c[1]); 
	sort(all(v));
	ans = max(ans, sb + sc - sa);
	ans = max(ans, sa + sc - sb);
	ans = max(ans, sa + sb - sc);
	ans = max(ans, sa + sb + sc - 2 * (v[0] + v[1]));
	deb1(ans)
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