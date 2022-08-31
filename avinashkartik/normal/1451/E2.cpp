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

ll n, ans[N], val[N];
vll adj[N];

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
	mset(val, -1);
	val[1] = 0;
	adj[0].pb(1);
	cin >> n;
	int f = 0;
	for(int i = 2; i <= n; i++){
		val[i] = val[1] ^ XOR(1, i);
		adj[val[i]].pb(i);
		if(adj[val[i]].size() > 1) f = 1;
	}
	if(f == 1){
		for(int i = 0; i < n; i++){
			if(adj[i].size() > 1){
				ans[adj[i][0]] = AND(adj[i][0], adj[i][1]);
				ans[1] = ans[adj[i][0]] ^ val[adj[i][0]];
				break;
			}
		}
		for(int i = 2; i <= n; i++){
			ans[i] = ans[1] ^ val[i];
		}
	} else {
		for(int i = 2; i <= n; i++){
			if(val[i] == n - 1){
				int ind = n;
				if(i == n) ind--;
				int x12 = val[i], a12 = 0;
				int x23 = val[ind], a23 = AND(1, ind);
				int x13 = x12 ^ x23, a13 = AND(i, ind);
				int s12 = x12 + 2 * a12;
				int s23 = x23 + 2 * a23;
				int s13 = x13 + 2 * a13;
				ans[i] = (s12 + s23 + s13) / 2 - s23;
				ans[1] = (s12 + s23 + s13) / 2 - s13;
				ans[ind] = (s12 + s23 + s13) / 2 - s12;
			}
		}
		for(int i = 2; i <= n; i++){
			ans[i] = ans[1] ^ val[i];
		}
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