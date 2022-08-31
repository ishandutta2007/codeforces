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
typedef  unsigned long long    ull;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  1e6+5;
const ll   mod   =  998244353 ;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, a[N], m[N], m1[N];
ll q;

void solve(){
	cin >> n;
	vector <int> u;
	u.pb(1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		int v = 1;
		for(int j = 2; j * j <= a[i]; j++){
			int ct = 0;
			while(a[i] % j == 0){
				ct++;
				a[i] /= j;
			}
			if(ct&1) v *= j;
		}
		if(a[i] > 1) v *= a[i];
		m[v]++;
		u.pb(v);
	}
	sort(all(u));
	uniq(u);
	int ans0 = 0, ans = 0;
	for(auto it : u){
		ans0 = max(ans0, m[it]);
		if(m[it] % 2 == 0) m1[1] += m[it];
		else m1[it] += m[it];
	}
	for(auto it : u){
		ans = max(ans, m1[it]);
	}
	cin >> q;
	for(int i = 1; i <= q; i++){
		ll w; cin >> w;
		if(w) deb1(ans)
		else deb1(ans0)
	}
	for(auto it : u){
		m[it] = 0, m1[it] = 0;
	}
}

int main(){
	GODSPEED;
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}