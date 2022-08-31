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
const ll   M     =  4e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, r, dp[N], x[N], y[N], t[N];

bool go(int i, int j){
	int dist = abs(x[i] - x[j]) + abs(y[i] - y[j]), td = t[j] - t[i];
	return td >= dist;
}

void solve(){
	cin >> r >> n;
	int mx = -INFi, ans = 0;
	for(int i = 1; i <= n; i++) dp[i] = -INFi;
	x[0] = y[0] = 1;
	for(int i = 1; i <= n; i++){
		cin >> t[i] >> x[i] >> y[i];
		for(int j = i - 1; j >= max(0, i-1000); j--){
			if(go(j, i)) dp[i] = max(dp[i], dp[j] + 1);
		}
		if(i >= 1000) mx = max(mx, dp[i-1000]);
		dp[i] = max(dp[i], mx + 1);
		ans = max(ans, dp[i]);
	}
	deb1(ans)
}

int main(){
	GODSPEED;
	int test = 1;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}