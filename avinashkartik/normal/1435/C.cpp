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

int n, a[10], b[N];
vpll v;
set <int> s;
map <int, int> ct;

void solve(){
	for(int i = 1; i <= 6; i++) cin >> a[i];
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
		for(int j = 1; j <= 6; j++){
			v.pb({b[i] - a[j], i});
		}
	}
	sort(all(v));
	int st = 0, en = 0;
	for(int i = 0; i < 6*n; i++){
		en = i;
		if(s.size() == n) break;
		s.insert(v[i].s);
		ct[v[i].s]++;
	}
	ll ans = v[en-1].f - v[st].f;
	//for(auto it : v) cout << it.s << " ";
	while(st < 6*n){
		ct[v[st].s]--;
		while(en < 6*n && ct[v[st].s] == 0){
			ct[v[en].s]++;
			en++;
		}
		if(ct[v[st].s] == 0) break;
		ans = min(ans, v[en-1].f - v[st+1].f);
		st++;
	}
	deb1(ans)
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}