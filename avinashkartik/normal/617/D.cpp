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

const ll   N     =  3e5+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

void solve(){
	set <int> sx, sy;
	vector <int> x(4, 0),y(4, 0);
	for(int i = 1; i <= 3; i++){
		cin >> x[i] >> y[i];
		sx.insert(x[i]);
		sy.insert(y[i]);
	}
	int ans = min(sx.size(), sy.size());
	if(ans == 2){
		if(sx.size() == 2){
			if(x[1] == x[2]){
				if(y[3] > min(y[1], y[2]) && y[3] < max(y[1], y[2])) deb1(3)
				else deb1(2)
			} else if(x[1] == x[3]){
				if(y[2] > min(y[1], y[3]) && y[2] < max(y[1], y[3])) deb1(3)
				else deb1(2)
			} else {
				if(y[1] > min(y[2], y[3]) && y[1] < max(y[2], y[3])) deb1(3)
				else deb1(2)
			}
		} else {
			if(y[1] == y[2]){
				if(x[3] > min(x[1], x[2]) && x[3] < max(x[1], x[2])) deb1(3)
				else deb1(2)
			} else if(y[1] == y[3]){
				if(x[2] > min(x[1], x[3]) && x[2] < max(x[1], x[3])) deb1(3)
				else deb1(2)
			} else {
				if(x[1] > min(x[2], x[3]) && x[1] < max(x[2], x[3])) deb1(3)
				else deb1(2)
			}
		}
	} else deb1(ans)
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}