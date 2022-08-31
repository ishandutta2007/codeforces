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

int test = 1, n, ans[N];

void solve(){
	cin>>n;
	int x,y,z;
	cout<<"? 1 2"<<endl;
	cin>>x;
	cout<<"? 2 3"<<endl;
	cin>>y;
	cout<<"? 1 3"<<endl;
	cin>>z;
	int t = (x+y+z)/2;
	ans[1] = t-y;
	ans[2] = t-z;
	ans[3] = t-x;
	for(int i = 4; i <= n; i++){
		cout<<"? "<<i-1<<" "<<i<<endl;
		cin>>x;
		ans[i] = x - ans[i-1];
	}
	cout<<"! ";
	for(int i = 1; i <= n; i++) cout<<ans[i]<<" "; cout<<endl;
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