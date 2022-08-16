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

const ll   N     =  2e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

int n, m;

void solve(){
	cin >> n >> m;
	vector <string> s(n), t(n, string(m, '.'));
	for(int i = 0; i < n; i++) cin >> s[i];
	for(int j = 0; j < n; j += 3) 
		for(int i = 0; i < m; i++)
			s[j][i] = 'X';
	vector <pll> v;
	if(n % 3 == 0) {
		for(int j = 0; j < m; j++){
			if(s[n - 1][j] == 'X') v.pb({n - 1, j});
		}
	}
	vector <int> w(m, floor((n - 1) / 3) * 3);
	for(auto it : v){
		int x = it.f, y = it.s;
		int mx = y;
		if(y != 0 && w[y - 1] > w[mx]) mx = y - 1;
		if(y != m - 1 && w[y + 1] > w[mx]) mx = y + 1;
		for(int i = w[mx] + 1; i <= x; i++) s[i][mx] = 'X';
		w[mx] = x;
	}
	for(int j = 0; j < floor((n - 1) / 3) * 3; j += 3){
		int f = 0;
		for(int i = 0; i < m; i++){
			if(s[j + 1][i] == 'X' || s[j + 2][i] == 'X'){
				s[j + 1][i] = 'X', s[j + 2][i] = 'X';
				f = 1;
				break;
			}
		}
		if(f == 0) s[j + 1][0] = 'X', s[j + 2][0] = 'X';
	}
	for(int i = 0; i < n; i++) deb1(s[i])
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