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
 
const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, a[N];

void solve(){
	cin >> n;
	int i = 1, j = 2, cur = 2;
	while(cur <= n){
		int x, y;
		deb3('?',i,j);
		cin >> x;
		deb3('?',j,i)
		cin >> y;
		if(x > y){
			a[i] = x;
			i = ++cur;
		} else {
			a[j] = y;
			j = ++ cur;
		}
	}
	if(i <= n) a[i] = n;
	else a[j] = n;
	cout << "! ";
	for(int i = 1; i <= n; i++) cout << a[i] << " ";
	cout << endl;
	cin >> n;
}

int main(){
	int test = 1;
    //cin>>test;
    for(int i = 1; i <= test; i++){
        solve();
    }
    #ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}