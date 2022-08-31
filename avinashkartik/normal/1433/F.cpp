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

const ll   N     =  75;
const ll   M     =  4e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, m, K, a[N][N], dp[N][N][N][N];

ll mem(int i, int j, int ct, int k){
	if(i == n+1){
		if(k == 0) return 0;
		return -INFi;
	}
	ll &ans = dp[i][j][ct][k];
	if(ans != -1) return ans;
	ans = -INF;
	if(j == m){
		ans = max(ans, mem(i+1, 1, 0, k));
		if(ct != m/2) ans = max(ans, mem(i+1, 1, 0, (k + a[i][j])%K) + a[i][j]);
	} else {
		ans = max(ans, mem(i, j+1, ct, k));
		if(ct != m/2) ans = max(ans, mem(i, j+1, ct+1, (k + a[i][j])%K) + a[i][j]);
	}
	return ans;
}

void solve(){
	mset(dp, -1);
	cin >> n >> m >> K;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> a[i][j];
		}
	}
	deb1(mem(1, 1, 0, 0))
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}