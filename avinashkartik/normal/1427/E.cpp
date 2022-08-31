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

ll n;
vector <pair<ll,pll>> ans;

void Euclid(ll a, ll b, ll *x, ll *y){
	if(a == 0){  
		*x = 0, *y = 1;  
		return;  
	}
	ll x1, y1; 
	Euclid(b%a, a, &x1, &y1);   
	*x = y1 - (b/a) * x1;  
	*y = x1;
}

void make(ll st, ll mul){
	int msb = log2(mul);
	ll j = st;
	for(int i = 1; i <= msb; i++, j *= 2){
		ans.pb({j, {0, j}});
	}
	j = 0;
	for(int i = 0; i <= msb; i++){
		if((mul >> i)&1){
			ans.pb({j, {0, st*(1ll << i)}});
			j += st*(1ll << i);
		}
	}
}

void print(pair<ll,pll> p){
	cout << p.f << " ";
	if(p.s.f == 0) cout << "+ ";
	else cout << "^ ";
	cout << p.s.s << "\n";
}

void solve(){
	cin >> n;
	int msb = log2(n);
	ll j = n;
	ans.pb({j, {1, j}});
	for(int i = 1; i <= msb; i++, j *= 2){
		ans.pb({j, {0, j}});
	}
	ans.pb({j, {1, n}});
	ll k = j^n;
	ll x, y;
	Euclid(k, n, &x, &y);
	x = abs(x), y = abs(y);
	make(k, x);
	make(n, y);
	if((y*n > x*k && y%2 == 0) or (y*n < x*k && x%2 == 0)){
		ans.pb({k*x, {0, n}});
		ans.pb({n*y, {0, n}});
		ans.pb({n*y + n, {1, k*x + n}});
	} else ans.pb({n*y, {1, k*x}});
	deb1(ans.size())
	for(auto it : ans) print(it);
}

int main(){
	GODSPEED;
	int test = 1;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}