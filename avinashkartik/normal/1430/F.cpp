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

const ll   N     =  2e3+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, k, a[N], l[N], r[N], dp[N][N][2];

ll mem(int i, int j, int f, ll left){
	if(i == n) return 0;
	if(dp[i][j][f] != -1) return dp[i][j][f];
	dp[i][j][f]	= INF;
	ll d = r[i] - l[i] + 1 - f;
	if(left >= a[i]){
		if(d == 0) return INF;
		if(d == 1){
			dp[i][j][f] = min(dp[i][j][f], mem(i+1, j, 0, left - a[i]));
			dp[i][j][f] = min(dp[i][j][f], mem(i+1, i, (l[i+1] == r[i]), k) + left - a[i]);
		} else {
			dp[i][j][f] = min(dp[i][j][f], mem(i+1, j, 0, left - a[i]));
			dp[i][j][f] = min(dp[i][j][f], mem(i+1, i, 0, k) + left - a[i]);
		}
	} else {
		int t = ceil((ld)(a[i] - left) / k) + 1;
		if(t > d) return INF;
		ll nl = (k - (a[i] - left) % k) % k;
		if(t == d){
			dp[i][j][f] = min(dp[i][j][f], mem(i+1, j, 0, nl));
			dp[i][j][f] = min(dp[i][j][f], mem(i+1, i, (l[i+1] == r[i]), k) + nl);
		} else {
			dp[i][j][f] = min(dp[i][j][f], mem(i+1, j, 0, nl));
			dp[i][j][f] = min(dp[i][j][f], mem(i+1, i, 0, k) + nl);
		}
	}
	return dp[i][j][f];
}

void solve(){
	mset(dp, -1);
	cin >> n >> k;
	ll sum = 0;
	for(int i = 0; i < n; i++){
		cin >> l[i] >> r[i] >> a[i];
		sum += a[i];
	}
	ll x = mem(0, n, 0, k);
	if(x >= INF) deb1(-1)
	else deb1(x + sum)
}

int main(){
	GODSPEED;
	int test = 1;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}