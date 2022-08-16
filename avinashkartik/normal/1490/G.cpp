#include <bits/stdc++.h>

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
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

ll n, q, a[N];

void solve(){
	cin >> n >> q;
	vector <ll> pre(n + 1, 0), mx(n + 1, -INFi);
	for(int i = 1; i <= n; i++) cin >> a[i], pre[i] = pre[i - 1] + a[i], mx[i] = max(mx[i - 1], pre[i]);
	for(int i = 1; i <= q; i++){
		ll x; cin >> x;
		if(pre[n] <= 0 && mx[n] < x) { cout << "-1 "; continue; }
		ll l = 0, r = n, ans = 0, y = ceil((ld) (x - mx[n]) / pre[n]);
		if(pre[n] > 0 && mx[n] < x){
			ans = y * n;
			x -= pre[n] * y;
		}
		while(l <= r){
			int mid = (l + r) / 2;
			if(mx[mid] < x){
				l = mid + 1;
			} else r = mid - 1;
		}
		cout << ans + l - 1 << " "; 
	}
	newl;
}

int main(){
	GODSPEED;
	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}