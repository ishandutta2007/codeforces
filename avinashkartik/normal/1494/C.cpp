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

int n, m, a[N], b[N];

int calc(vector <int> a, vector <int> b){
	int n = a.size(), m = b.size();
	vector <int> suf(m + 1, 0);
	for(int i = m - 1; i >= 0; i--){
		suf[i] = suf[i + 1];
		auto it = lower_bound(all(a), b[i]);
		if(it != a.end() && *it == b[i]) suf[i]++;
	}
	int ans = suf[0];
	for(int i = 0; i < m; i++){
		auto it = upper_bound(all(a), b[i]); it--;
		it = lower_bound(all(b), b[i] + (int) (a.begin() - it));
		ans = max(ans, suf[i + 1] + (int) (b.begin() + i - it + 1));
	}
	return ans;
}

void solve(){
	vector <int> al, ar, bl, br;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] > 0) ar.pb(a[i]);
		else al.pb(-a[i]);
	}
	for(int i = 1; i <= m; i++){
		cin >> b[i];
		if(b[i] > 0) br.pb(b[i]);
		else bl.pb(-b[i]);
	}
	reverse(all(al));
	reverse(all(bl));
	int ans = calc(al, bl) + calc(ar, br);
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