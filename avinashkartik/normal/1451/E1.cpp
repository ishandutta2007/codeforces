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

ll n, ans[N];

int XOR(int i, int j){
	deb3("XOR", i, j)
	int ans;
	cin >> ans;
	return ans;
}

int AND(int i, int j){
	deb3("AND", i, j)
	int ans;
	cin >> ans;
	return ans;
}
 
void solve(){
	cin >> n;
	int x12 = XOR(1, 2), a12 = AND(1, 2);
	int x23 = XOR(2, 3), a23 = AND(2, 3);
	int x13 = x12 ^ x23, a13 = AND(1, 3);
	int s12 = x12 + 2 * a12;
	int s23 = x23 + 2 * a23;
	int s13 = x13 + 2 * a13;
	ans[1] = (s12 + s23 + s13) / 2 - s23;
	ans[2] = (s12 + s23 + s13) / 2 - s13;
	ans[3] = (s12 + s23 + s13) / 2 - s12;
	set <int> s;
	for(int i = 0; i < n; i++) s.insert(i);
	for(int i = 4; i <= n; i++){
		ans[i] = ans[1] ^ XOR(1, i);
	}
	cout << '!' << " ";
	for(int i = 1; i <= n; i++) cout << ans[i] << " ";
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