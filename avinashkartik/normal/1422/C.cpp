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

const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, pow1[N], suf[N];
string s;

void solve(){
	cin >> s;
	n = s.size();
	s = '#' + s + '#';
	pow1[0] = 1;
	for(int i = 1; i <= n; i++) pow1[i] = (pow1[i-1] * 10) % mod;
	for(int i = 1; i <= n; i++) suf[i] = (suf[i - 1] + pow1[i - 1] * i) % mod;
	ll cur = 0, ans = 0;
	for(int i = 1; i <= n; i++){
		ans = (ans + suf[n - i] * (s[i] - '0')) % mod;
		ans = (ans + cur * (s[i] - '0') % mod * pow1[n - i]) % mod;
		cur = (cur + i) % mod;
	}
	deb1(ans)
}

int main(){
	//GODSPEED;
	int test = 1;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}