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

const ll   N     =  3e5+5;
const ll   mod   =  1e9+7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

ll n1, t[N], x[N];

void solve(){
	cin >> n1;
	for(int i = 1; i <= n1; i++) cin >> t[i] >> x[i];
	t[n1 + 1] = INF;
	ll last = 0, cur = 0, p = 0, n = 0, ans = 0;
	for(int i = 1; i <= n1; i++){
		if(t[i] >= cur){
			cur = t[i] + abs(n - x[i]);
			p = n;
			n = x[i];
			last = t[i];
			if(t[i + 1] >= cur) ans++;
		} else {
			ll curpt;
			if(p > n){
				curpt = p - (t[i] - last);
				ll nxt = max(curpt - (t[i + 1] - t[i]), n);
				if(curpt >= x[i] && x[i] >= nxt) ans++;
			}
			else{
				curpt = p + (t[i] - last);
				ll nxt = min(curpt + (t[i + 1] - t[i]), n);
				if(curpt <= x[i] && x[i] <= nxt) ans++;
			}
		}
	}
	deb1(ans)
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