#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
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

ll test = 1, n, m, a[N], sz = 0, tot, ch[N];
string s = "0";

ll tree[N] = {};

void update(int idx, int val){ 
    idx++;
    while (idx <= N-1){ 
        tree[idx] += val;
        idx += idx & (-idx); 
    } 
} 

ll query(int idx){
    idx++;
    ll sum = 0;
    while (idx > 0){ 
        sum += tree[idx];
        idx -= idx & (-idx); 
    } 
    return sum; 
}

int bs(int x){
	int l = 1, r = N-1, ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (query(mid) >= x) {
			ans = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	return ans;
}

void solve(){
	cin >> n >> m;
	for (int i = 1; i <= m; i++) cin>>a[i];
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (x == -1) {
			vll v;
			for (int i = 1; i <= m; i++){
				if (a[i] > sz) break;
				v.pb(bs(a[i]));
			}
			sz -= v.size();
			for(auto it : v) ch[it] = 0, update(it,-1);
		} else {
			s += x + '0';
			sz++, tot++;
			update(tot,1);
			ch[tot] = 1;
		}
	}
	if (sz == 0) deb1("Poor stack!")
	else {
		for (int i = 1; i <= tot; i++) {
			if (ch[i] == 1) cout << s[i];
		}
		newl;
	}
}

int main(){
	GODSPEED;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
	#ifndef ONLINE_JUDGE
    cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
    #endif
}