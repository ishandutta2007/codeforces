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
typedef  vector<pll>           vpll;
 
const ll   N     =  1e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, a[N];

int q(int i){
	if(a[i] != -1) return a[i];
	cout << "? " << i << endl;
	cin >> a[i];
	return a[i];
}

void solve(){
	mset(a, -1);
	cin >> n;
	a[0] = a[n + 1] = INFi;
	int l = 1, r = n;
	while(l <= r){
		int mid = (l + r) / 2;
		if(q(mid) < q(mid - 1) && q(mid) < q(mid + 1)){
			cout << "! " << mid << endl;
			return;
		}
		if(q(mid) < q(mid - 1)) l = mid + 1;
		else r = mid - 1;
	}
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