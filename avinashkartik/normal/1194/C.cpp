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
typedef  unsigned long long    ull;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  3e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, m;
string s, t, p;

void solve(){
	cin >> s >> t >> p;
	n = s.size(), m = t.size();
	vector <int> ct(26, 0);
	int i = 0, j = 0;
	for(;j < m; j++){
		if(i < n && s[i] == t[j]) i++;
		else ct[t[j] - 'a']++;
	}
	if(i != n){
		deb1("NO")
		return;
	}
	for(int i = 0; i < p.size(); i++){
		ct[p[i] - 'a']--;
	}
	for(int i = 0; i < 26; i++){
		if(ct[i] > 0){
			deb1("NO")
			return;
		}
	}
	deb1("YES")
}

int main(){
	GODSPEED;
	int test = 1;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}