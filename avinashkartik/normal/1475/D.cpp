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

ll n, m, a[N], b[N];

void solve(){
	cin >> n >> m;
	ll sum = 0;
	for(int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	if(sum < m){
		deb1(-1)
		return;
	}
	vector <ll> s1, s2;
	s2.pb(0);
	for(int i = 1; i <= n; i++){
		if(b[i] == 1) s1.pb(a[i]);
		else s2.pb(a[i]);
	}
	vector <ll> pre(s2.size(), 0);
	sort(all(s1), greater<>());
	sort(all(s2), greater<>());
	pre[0] = 0;
	for(int i = 1; i < s2.size(); i++) pre[i] = pre[i - 1] + s2[i - 1];
	int ans = 2 * n;
	ll cur = 0;
	for(int i = 0; i < s1.size(); i++){
		int res = (lower_bound(all(pre), m - cur) - pre.begin());
		cur += s1[i];
		if(res == s2.size()) continue;
		ans = min(ans, 2 * res + i);
	}
	int res = (lower_bound(all(pre), m - cur) - pre.begin());
	ans = min(ans, 2 * res + (int)s1.size());
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