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

int n, a[N];

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	vector <int> v;
	v.pb(a[1]);
	for(int i = 2; i <= n; i++) if(a[i] != v.back()) v.pb(a[i]);
	n = v.size();
	int ans = n, p = 0;
	set <int> s; 
	for(int i = 0; i < n; i++){
		if(s.find(v[i]) != s.end()){
			s.clear();
			s.insert(v[i]);
			p = v[i - 1];
			ans--;
		} else if(v[i] == p){
			s.clear();
			s.insert(v[i - 1]);
			ans--;
		} else s.insert(v[i]);
		//deb3(i, p, ans)
	}
	deb1(ans)
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}