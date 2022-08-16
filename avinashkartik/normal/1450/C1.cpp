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
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll n;
string s[305];

void convert(int cx, int co){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){	
			if(s[i][j] == '.') continue;
			if(s[i][j] == 'O' && (i + j) % 3 == co) s[i][j] = 'X';
			if(s[i][j] == 'X' && (i + j) % 3 == cx) s[i][j] = 'O';
		}
	}
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		s[i] = '.' + s[i] + '.';
	}
	s[0] = s[n + 1] = string(n + 2, '.');
	vector <int> x(3, 0), o(3, 0);
	int tot = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){	
			if(s[i][j] == '.') continue;
			if(s[i][j] == 'X') x[(i + j) % 3]++;
			else o[(i + j) % 3]++;
			tot++;
		}
	}
	int f = 0;
	for(int i = 0; i < 3; i++){
		if(f) break;
		for(int j = 0; j < 3; j++){
			if(i == j) continue;
			if((x[i] + o[j]) * 3 <= tot){
				convert(i, j);
				f = 1;
				break;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){	
			cout << s[i][j];
		}
		newl;
	}
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