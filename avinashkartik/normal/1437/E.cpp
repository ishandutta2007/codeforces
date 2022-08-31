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

const ll   N     =  5e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, k, a[N], b[N];

int calc(int l, int r){
	if(l > r) return 0;
	int ch = 0;
	int st = a[l - 1] - l + 1, en = a[r + 1] - r - 1;
	multiset <int> s;
	for(int i = l; i <= r; i++){
		if(a[i] - i < st || a[i] - i > en) continue;
		s.insert(a[i] - i);
		auto it = s.upper_bound(a[i] - i);
		if(it != s.end()) s.erase(it);
	}
	return r - l + 1 - s.size();
}

void solve(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	a[n + 1] = INFi;
	a[0] = -INFi;
	int ans = 0;
	for(int i = 1; i <= k; i++) cin >> b[i];
	for(int i = 1; i < k; i++){
		if(a[b[i + 1]] - a[b[i]] < b[i + 1] - b[i]){
			deb1(-1)
			return;
		}
	}
	b[0] = 0, b[k + 1] = n + 1;
	for(int i = 0; i <= k; i++){
		ans += calc(b[i] + 1, b[i + 1] - 1);
		//deb2(b[i], ans)
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