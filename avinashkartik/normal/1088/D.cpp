#include<bits/stdc++.h>

using namespace std;

#define  f              first                 
#define  s              second
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int test = 1;

int query(int c, int d){
	int x;
	cout<<"? "<<c<<" "<<d<<endl;
	cin>>x;
	return x;
}

void find(int c, int d){
	for(int i = 29; i >= 0; i--){
		ll y = (1ll<<i);
		if(y&c or y&d) continue;
		int x = query(c+y,d);
		if(x == -1){
			c += y, d += y;
		}
	}
	cout<<"! "<<c<<" "<<d<<endl;
}

void solve(){
	int c = 0, d = 0, x = 0;
	int f = query(c,d);
	for(int i = 29; i >= 0; i--){
		c += (1ll<<i), d += (1ll<<i);
		x = query(c,d);
		if(x == 0){
			c -= (1ll<<i), d -= (1ll<<i);
			break;
		}
		if(x*f == 1){
			c -= (1ll<<i), d -= (1ll<<i);
		}
		else{
			if(f == 1) d -= (1ll<<i);
			else c -= (1ll<<i);
			f = query(c,d);
		}
	}
	find(c,d);
}

int main(){
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}