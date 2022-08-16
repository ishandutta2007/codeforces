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

ll n, x, a[N];

void print(){
	cout << "! ";
	for(int i = 1; i <= n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
 
void solve(){
	cin >> n;
	a[n] = 1;
	for (int i = 2; i <= n; i++) {
		cout << "? ";
		for (int j = 1; j < n; j++) cout << 1 << " ";
		cout << i << endl;
		cin >> x;
		if (x == 0) {
			a[n] = n + 2 - i;
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i == a[n]) continue;
		cout << "? ";
		for (int j = 1; j < n; j++) cout << a[n] << " ";
		cout << i << endl;
		cin >> x;
		a[x] = i;
	}
	print();
}

int main(){
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}