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

void solve(){
	int x;
	string y;
	do{
		cout<<"next 0"<<endl;
		cin>>x;
		for(int i = 0; i < x; i++) cin>>y;
		cout<<"next 0 1"<<endl;
		cin>>x;
		for(int i = 0; i < x; i++) cin>>y;
	}while(x != 2);
	do{
		cout<<"next 0 1 2 3 4 5 6 7 8 9"<<endl;
		cin>>x;
		for(int i = 0; i < x; i++) cin>>y;
	}while(x != 1);
	cout<<"done"<<endl;
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