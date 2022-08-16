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

int n, ind[N], p[N];

void make(ll n){
	for(int i = 1; i <= n; i++){
		p[i] = i;
	}
}

int find(ll x){
	return (p[x] == x)? x: p[x] = find(p[x]);
}

void solve(){
	cin >> n;
	make(2*n);
	vector <int> ans(2*n+1, 0);
	set <int> s;
	for(int i = 1; i <= 2*n; i++) {
		char x; int v; cin >> x;
		if(x == '-'){
			cin >> v;
			ind[v] = i;
		} else s.insert(i);
	}
	for(int i = 1; i <= n; i++){
		int idx = find(ind[i]-1);
		if(s.find(idx) == s.end()){
			deb1("NO")
			return;
		}
		ans[idx] = i;
		s.erase(idx);
		p[idx] = idx-1;
		p[ind[i]] = ind[i]-1;
	}
	deb1("YES")
	for(int i = 1; i <= 2*n; i++) if(ans[i]) cout << ans[i] << " ";
	newl;
}

int main(){
	GODSPEED;
	int test = 1;
	//cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}