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

const ll   N     =  1e6+3;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, x, y, c[10];

ll calc(int i, int j){
	if(i == 1){
		if(j == 2){
			if(x > y || x < 0) return INF;
			return abs(x * c[i]) + abs((y - x) * c[j]);
		} else if(j == 3){
			if(x >= 0){
				if(y < x) return INF;
				return abs(x * c[i]) + abs((y - x) * (c[i] + c[j]));
			} else {
				if(y < 0) return INF;
				return abs(x * c[j]) + abs(y * (c[i] + c[j]));
			}
		} else if(j == 5){
			if(x < y || x < 0) return INF;
			return abs(x * c[i]) + abs((x - y) * c[j]);
		} else if(j == 6){
			if(y > x || y < 0) return INF;
			return abs(y * c[i]) + abs((x - y) * c[j]);
		}
	} else if(i == 2){
		if(j == 3){
			if(x > 0 || y < 0) return INF;
			return abs(x * c[j]) + abs(y * c[i]);
		} else if(j == 4){
			if(x > 0 || y < x) return INF;
			return abs(x * c[j]) + abs((y - x) * c[i]);
		} else if(j == 6){
			if(x < 0 || y < 0) return INF;
			return abs(x * c[j]) + abs(y * c[i]);
		}
	} else if(i == 3){
		if(j == 4){
			if(y < x || y > 0) return INF;
			return abs(y * c[j]) + abs((y - x) * c[i]);
		} else if(j == 5){
			if(x > 0 || y > 0) return INF;
			return abs(x * c[i]) + abs(y * c[j]);
		}
	} else if(i == 4){
		if(j == 5){
			if(x < y || x > 0) return INF;
			return abs(x * c[i]) + abs((x - y) * c[j]);
		} else if(j == 6){
			if(x <= 0){
				if(y > x) return INF;
				return abs(x * c[i]) + abs((y - x) * (c[i] + c[j]));
			} else {
				if(y > 0) return INF;
				return abs(x * c[j]) + abs(y * (c[i] + c[j]));
			}
		}
	} else {
		if(x < 0 || y > 0) return INF;
		return abs(x * c[j]) + abs(y * c[i]);
	}
	return INF;
}

void solve(){
	cin >> x >> y;
	for(int i = 1; i <= 6; i++) cin >> c[i];
	ll ans = INF;
	for(int i = 1; i <= 6; i++){
		for(int j = i + 1; j <= 6; j++){
			//deb3(i, j, calc(i, j))
			ans = min(ans, calc(i, j));
		}
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
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}