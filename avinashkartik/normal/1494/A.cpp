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

int n;
string s, t;

bool ch(char x, char y){
	string t1 = t;
	int j = -1;
	for(int i = 0; i < n; i++){
		if(t1[i] != '(' && j == -1) j = i;
		if(j != -1 && s[i] == s[j]) t1[i] = x;
	}
	j = -1;
	for(int i = 0; i < n; i++){
		if((t1[i] != '(' && t1[i] != ')') && j == -1) j = i;
		if(j != -1 && s[i] == s[j]) t1[i] = y;
	}
	int ct = 0;
	for(int i = 0; i < n; i++){
		if(t1[i] == '(') ct++;
		else ct--;
		if(ct < 0) return 0;
	}
	return ct == 0;
}

void solve(){
	cin >> s;
	n = s.size();
	t = s;
	for(int i = 0; i < n; i++){
		if(s[i] == s[0]) t[i] = '(';
	}
	int ans = ch('(', ')') | ch(')', '(') | ch(')', ')');
	if(ans) deb1("YES")
	else deb1("NO")
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