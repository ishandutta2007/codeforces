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
const ll   LEVEL =  log2(N)+1;

ll n, add[N], rem[N], l[N], r[N];
vector <int> points;

void compress(){
	sort(all(points));
	uniq(points);
	for(int i = 1; i <= n; i++){
		l[i] = lower_bound(all(points), l[i]) - points.begin();
		r[i] = lower_bound(all(points), r[i]) - points.begin();
	}
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
		points.pb(l[i]);
		points.pb(r[i]);
	}
	compress();
	vpll p;
	for(int i = 1; i <= n; i++){
		add[l[i]]++;
		rem[r[i] + 1]++;
		p.pb({l[i], r[i]});
	}
	sort(all(p));
	vector <int> pre(3 * n, 0);
	pre[0] = add[0];
	for(int i = 1; i < 3 * n; i++) pre[i] = pre[i - 1] + add[i];
	ll ans = INFi;
	int j = 0;
	multiset <int> s;
	for(int i = 0; i < n; i++){
		while(s.size() && *s.begin() < p[i].f) s.erase(s.begin());
		while(j < n && p[i].f == p[j].f) s.insert(p[j++].s);
		ll sz = s.size() + pre[p[i].s] - pre[p[i].f];
		ans = min(ans, n - sz);
	}
	deb1(ans)
	for(int i = 0; i <= 3 * n; i++) add[i] = rem[i] = 0;
	points.clear();
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