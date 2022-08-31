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

const ll   N     =  40005;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

int n, m, k, dp[2][105][N], a[105], b[105];

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
		a[i] *= 2;
		b[i] *= 2;
	}
	int off = 2e4, f = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j < N; j++){
			dp[0][i][j] = dp[1][i][j] = -INFi;
		}
	}
	dp[0][0][off] = 0;
	for(int k = 1; k <= n; k++){
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= N; j++){
				if(j + a[k] - b[k] >= N) continue;
				if(j - (b[k] / 2) < 0) continue;
				dp[1 - f][i + 1][j + a[k] - b[k]] = max(dp[1 - f][i + 1][j + a[k] - b[k]], dp[f][i][j] + b[k]);
				dp[1 - f][i][j - (b[k] / 2)] = max(dp[1 - f][i][j - (b[k] / 2)], dp[f][i][j] + (b[k] / 2));
			}
		}
		f = 1 - f;
	}
	for(int i = 1; i <= n; i++){
		int ans = -INFi;
		for(int j = 0; j < N; j++){
			ans = max(ans, dp[f][i][j] - max(0, (off - j)));
		}
		cout << (ld) ans / 2.0 << " ";
	}
}

int main(){
	GODSPEED;
	ll test = 1;
	//cin >> test;
	for(ll i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}