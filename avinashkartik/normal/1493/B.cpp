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

const ll   N     =  1e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll H, M;
string s;

bool ch(int h, int m){
	vector <int> v = {(h / 10) % 10, h % 10, (m / 10) % 10, m % 10};
	int f = 0;
	for(auto x : v){
		if(x == 0 || x == 1 || x == 2 || x == 5 || x == 8){
			continue;
		} else f = 1;
	}
	if(f == 1) return 0;
	for(int i = 0; i < 4; i++){
		if(v[i] == 2) v[i] = 5;
		else if(v[i] == 5) v[i] = 2;
	}
	int h1 = 10 * v[3] + v[2], m1 = 10 * v[1] + v[0];
	if(h1 < H && m1 < M) return 1;
	return 0;
}

void solve(){
	cin >> H >> M >> s;
	int h1 = 10 * (s[0] - '0') + s[1] - '0', m1 = 10 * (s[3] - '0') + s[4] - '0';
	while(ch(h1, m1) == 0){
		m1++;
		if(m1 == M){
			m1 = 0;
			h1 = (h1 + 1) % H;
		}
	}
	if(h1 < 10) cout << "0";
	cout << h1;
	cout << ":";
	if(m1 < 10) cout << "0";
	cout << m1;
	newl;
}

int main(){
	GODSPEED;
	int test = 1;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}