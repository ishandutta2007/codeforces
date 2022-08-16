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

ll test = 1, n, a[30][30];

ll query(){
	ll sum, i = 0, j = 0; cin >> sum;
	while(1){
		cout << i+1 << " " << j+1 << endl;
		if(a[i][j] == 0){
			if(i != n-1 and sum&a[i+1][j]) i++;
			else j++;
		} else {
			if(j != n-1 and sum&a[i][j+1]) j++;
			else i++;
		}
		if(i == n-1 and j == n-1) break;
	}
	cout << n << " " << n << endl;
}

void solve(){
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << (a[i][j] = (i%2 == 0)? 0 : (1ll << (i+j))) << " ";
		}
		cout << endl;
	}
	int q;
	cin >> q;
	while(q--) query();
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