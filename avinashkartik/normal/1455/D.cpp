#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  

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

#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> 

const ll   N     =  1e6+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, x, a[N], b[N];
string s;

ll calc(vector <int> b, int x){
	vector <int> c(n + 1, 0);
	for(int i = 1; i <= n; i++) c[i] = a[i];
	int ct = 0;
	for(int i = 1; i <= n; i++){
		if(b[i] == x){
			if(c[i] < x) return INF;
			else {
				swap(x, c[i]);
				if(c[i] != x) ct++;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		if(c[i] < c[i - 1]) return INF;
	}
	return ct;
}

void solve(){
	cin >> n >> x;
	for(int i = 1; i <= n; i++) cin >> a[i];
	a[0] = 0;
	ll ans = INF;
	int f = 1;
	for(int i = 1; i <= n; i++){
		if(a[i] < a[i - 1]) f = 0;
	}
	if(f == 1){
		deb1(0)
		return;
	}
	for(int i = 1; i <= n; i++){
		vector <int> b(n + 1, 0);
		for(int j = 1; j <= n; j++) b[j] = a[j];
		if(a[i] > x){
			b[i] = x;
			sort(all(b));
			ans = min(ans, calc(b, x));
		}
	}
	if(ans == INF) ans = -1;
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