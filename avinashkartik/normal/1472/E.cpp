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

const ll   N     =  4e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll n, a[N];

void solve(){
	cin >> n;
	vector <pair <ll, pll>> v;
	vector <int> ans(n, -1);
	for(int i = 1; i <= n; i++){
		int h, w; cin >> h >> w;
		if(h > w) swap(h, w);
		v.pb({h, {w, i}});
	}
	sort(all(v));
	int j = 0;
	int mn = -1;
	for(int i = 0; i < n; i++){
		//deb1(v[i].s.s)
		while(j < n && v[j].f < v[i].f){
			if(mn == -1 || v[j].s.f < v[mn].s.f) mn = j;
			j++;
		}
		if(mn != -1 && v[mn].s.f < v[i].s.f) ans[v[i].s.s - 1] = v[mn].s.s;
	}
	debv(ans)
}

int main(){
	GODSPEED;
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}