#include <bits/stdc++.h>

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
typedef  unsigned long long    ull;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  3e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, m, dp[32][32];
vector <int> v1, v2;

int mem(int i, int j){
	if(i == v1.size() && j == v2.size()) return 1;
	if(i == v1.size() || j == v2.size()) return 0;
	if(dp[i][j] != -1) return dp[i][j];
	if(v1[i] > v2[j]) return 0;
	if(v1[i] == v2[j]) dp[i][j] = mem(i + 1, j + 1);
	else dp[i][j] = mem(i + 1, j) | mem(i + 1, j + 1);
	return dp[i][j];
}

void solve(){
	mset(dp, -1);
	v1.clear();
	v2.clear();
	cin >> n >> m;
	for(int i = 29; i >= 0; i--){
		ll x = (1ll << i);
		if(n&x) v1.pb(i);
		if(m&x) v2.pb(i);
	}
	if(mem(0, 0)) deb1("YES")
	else deb1("NO")
}

int main(){
	GODSPEED;
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}