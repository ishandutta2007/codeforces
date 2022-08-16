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
 
const ll   N     =  1e3+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll test = 1, n, a[4];

ll query(int f){
	vll v;
	if(f == 1){
		v.pb(a[1]); v.pb(a[2]); v.pb(a[3]);
		sort(v.begin(), v.end());
		return 2*v[2]-v[1]-v[0];
	}
	if(f == 0){
		v.pb(a[1]); v.pb(a[2]); v.pb(a[3]);
		sort(v.begin(), v.end());
		return v[2]-v[1];
	}
}

void solve(){
	cin>>a[1]>>a[2]>>a[3];
	cout<<"First"<<endl;
	ll x, y;
	y = query(1);
	cout<<y<<endl;
	cin>>x;
	if(x == 0) return;
	a[x] += y;
	y = query(1);
	cout<<y<<endl;
	cin>>x;
	if(x == 0) return;
	a[x] += y;
	cout<<query(0)<<endl;
	cin>>x;
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