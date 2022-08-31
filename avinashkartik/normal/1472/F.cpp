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

ll n, m, a[N];

void solve(){
	cin >> n >> m;
	vpll v;
	for(int i = 1; i <= m; i++){
		int r, c; cin >> r >> c;
		v.pb({c, r});
	}
	v.pb({n + 1, 1});
	v.pb({n + 1, 2});
	sort(all(v));
	if(m&1){
		deb1("NO")
		return;
	}
	int f = 2;
	for(int i = 0; i <= m; i++){
		//deb2(i, f)
		if(f == 2){
			if(v[i].f == v[i + 1].f){
				i++;
				continue;
			}
			if(v[i].s == 1) f = (v[i].f % 2) ^ 1;
			else f = (v[i].f % 2);
		} else {
			if(v[i].f == v[i + 1].f){
				deb1("NO")
				return;
			}
			if(v[i].f % 2 == f){
				if(v[i].s == 1) f = 2;
				else{
					deb1("NO")
					return;
				}
			} else {
				if(v[i].s == 2) f = 2;
				else{
					deb1("NO")
					return;
				}
			}
		}
	}
	deb1("YES")
}

int main(){
	GODSPEED;
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}