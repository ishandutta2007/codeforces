#include<bits/stdc++.h>

using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                
#define  s              second
#define  newl           cout<<"\n";
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";newl;
#define  deb1(a)        cout<<a<<"\n";
#define  deb2(a,b)      cout<<a<<" "<<b<<"\n";
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<"\n";
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
#define  uniq(a)        a.resize(unique(a.begin(), a.end()) - a.begin());
#define  all(a)         a.begin(),a.end()           
 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  1e3+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, m;
string a[N], b[N];

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] = '1' + a[i] + '1';
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
		b[i] = '1' + b[i] + '1';
	}
	vector <int> f(n + 1, 0);
	for(int i = 1; i <= n; i++){
		if(a[1][i] != b[1][i]) f[i] = 1;
	}
	int ok = 1;
	for(int i = 1; i <= n; i++){
		int okk = 1, okk1 = 1;
		for(int j = 1; j <= n; j++){
			if((a[i][j] - '0')^f[j] != (b[i][j] - '0')) okk = 0;
			else okk1 = 0;
		}
		if(okk == 0 && okk1 == 0) ok = 0;
	}
	if(ok) deb1("Yes")
	else deb1("No")
}

int main(){
	GODSPEED;
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}