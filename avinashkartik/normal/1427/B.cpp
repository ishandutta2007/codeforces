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
const ll   M     =  4e6+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, k;
string s;

void solve(){
	vll v;
	cin >> n >> k >> s;
	int f = 0, ct = 0, w = 0, ans = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'W'){
			if(f == 1) v.pb(ct);
			f = 1;
			ct = 0;
			w++;
			if(i == 0 or s[i-1] == 'L') ans++;
			else ans += 2;
		} else ct++;
	}
	int l = n-w;
	if(l <= k) deb1(2*n-1)
	else {
		sort(all(v));
		for(auto it : v){
			if(it == 0) continue;
			if(k >= it){
				ans += 2*it+1;
				k -= it;
				l -= it;
			} else {
				ans += 2*k;
				l -= k;
				k = 0;
			}
		}
		int f = 0;
		if(l == n) f = -1;
		if(l and k) ans += min(l, k)*2 + f;
		deb1(ans)
	}
}

int main(){
	GODSPEED;
	int test = 1;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}