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

ll n;
string s;

void solve(){
	set <ll> o, m;
	vll v;
	int ct = 0, f = -1;
	cin >> n >> s;
	for(int i = 0; i < n; i++){
		int c = s[i] - '0';
		if(c == f){
			ct++;
		} else {
			if(ct) v.pb(ct);
			ct = 1;
			f = c;
		}
	}
	v.pb(ct);
	for(int i = 0; i < v.size(); i++){
		if(v[i] > 1) m.insert(i);
		else o.insert(i);
	}
	int ans = 0;
	for(int i = 0; i < v.size(); i++){
		if(v[i] == 0) continue;
		ans++;
		if(v[i] == 1) o.erase(i);
		else m.erase(i);
		if(v[i] == 1) {
			if(m.size()){
				int ind = *m.begin();
				m.erase(ind);
				v[ind]--;
				if(v[ind] == 1) o.insert(ind);
				else m.insert(ind);
			} else if(o.size()){
				int ind = *o.begin();
				o.erase(ind);
				v[ind]--;
			}
		}
	}
	deb1(ans)
}

int main(){
	GODSPEED;
	int test = 1;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}