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

int n, a[N], c[3];

void solve(){
	cin >> n;
	mset(c, 0);
	for(int i = 1; i <= n; i++) cin >> a[i], c[a[i] % 3]++;
	set <pll> s;
	for(int i = 0; i < 3; i++) s.insert({c[i], i});
	int ans = 0;
	while(1){
		auto p = *s.rbegin();
		if(p.f == n / 3) break;
		s.erase(p);
		s.erase({c[(p.s + 1) % 3], (p.s + 1) % 3});
		c[p.s]--;
		c[(p.s + 1) % 3]++;
		s.insert({c[p.s], p.s});
		s.insert({c[(p.s + 1) % 3], (p.s + 1) % 3});
		ans++;
	}
	deb1(ans)
}

int main(){
	GODSPEED;
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}