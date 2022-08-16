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
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N)+1;

int n, m, k;

bool comp(pll p, pll q){
	return (p.f + p.s) / 2 < (q.s + q.f) / 2;
}

void solve(){
	cin >> n >> m >> k;
	vector <pair <int, int>> v;
	for(int i = 1; i <= m; i++){
		int l, r;
		cin >> l >> r;
		v.pb({l, r});
	}
	sort(all(v), comp);
	vector <int> suf(m, 0);
	for(int i = n - k + 1; i > 0; i--){
		int cur = 0;
		for(int j = m - 1; j >= 0; j--){
			cur += max(0, min(v[j].s, i + k - 1) - max(v[j].f, i) + 1);
			suf[j] = max(suf[j], cur);
		}
	}
	for(int j = m - 2; j >= 0; j--){
		suf[j] = max(suf[j], suf[j + 1]);
	}
	int ans = 0;
	for(int i = 1; i <= n - k + 1; i++){
		vector <int> pre(m, 0);
		int cur = 0;
		for(int j = 0; j < m; j++){
			cur += max(0, min(v[j].s, i + k - 1) - max(v[j].f, i) + 1);
			pre[j] = cur;
		}
		for(int j = 0; j < m - 1; j++){
			ans = max(ans, pre[j] + suf[j + 1]);
		}
		ans = max(ans, pre[m - 1]);
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
	#ifndef ONLINE_JUDGE
	cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
	#endif
}