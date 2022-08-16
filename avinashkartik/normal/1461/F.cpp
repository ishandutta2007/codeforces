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

ll n, a[N];
char ans[N];
string s;

void calc(int l, int r){
	if(l > r) return;
	for(int i = l; i <= r; i++){
		l = i;
		if(a[i] != 1) break;
		ans[i - 1] = ans[i] = '+';
	}
	for(int i = r; i >= l; i--){
		r = i;
		if(a[i] != 1) break;
		ans[i - 1] = ans[i] = '+';
	}
	ll p = 1, s = 0;
	for(int i = l; i <= r; i++){
		if(p > 2 * (r - l + 1)) break;
		p *= a[i];
	}
	if(p > 2 * (r - l + 1)) return;
	if(l >= r) return;
	vector <int> v;
	vpll seg;
	p = 1, s = 0;
	int prv = l;
	for(int i = l; i <= r; i++){
		if(a[i] != 1){
			if(p == 1 && s) {
				v.pb(s), s = 0;
				seg.pb({prv, i - 1});
				prv = i;
			}
			p *= a[i];
		} else {
			if(s == 0) {
				v.pb(p), p = 1;
				seg.pb({prv, i - 1});
				prv = i;
			}
			s += a[i];
		}
	}
	v.pb(p);
	seg.pb({prv, n});
	ll best = -1, anss = 0;
	int len = v.size() / 2;
	for(int msk = 0; msk < (1 << len); msk++){
		p = v[0], s = 0;
		for(int j = 0; j < len; j++){
			if(msk & (1 << j)){
				p *= v[2 * (j + 1)];
			} else {
				s += p + v[2 * j + 1];
				p = v[2 * (j + 1)];
			}
		}
		s += p;
		if(s > anss) anss = s, best = msk;
	}
	for(int j = 0; j < len; j++){
		if(best & (1 << j)){
		} else {
			int st = seg[2 * j + 1].f, en = seg[2 * j + 1].s;
			for(int i = st - 1; i <= en; i++) ans[i] = '+';
		}
	}
}

void solve(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], ans[i] = '*';
	cin >> s;
	sort(all(s));
	if(s == "+-") s = "+";
	if(s == "*+-") s = "*+";
	if(s.size() == 1){
		for(int i = 1; i < n; i++) cout << a[i] << s[0];
		cout << a[n] << "\n";
	} else if(s == "*-"){
		for(int i = 1; i < n; i++) {
			if(a[i + 1]) cout << a[i] << '*';
			else cout << a[i] << '-';
		}
		cout << a[n] << "\n";
	} else {
		int l = 1;
		for(int i = 1; i <= n; i++){
			if(a[i] == 0){
				calc(l, i - 1);
				l = i + 1;
				ans[i] = '+';
				ans[i - 1] = '+';
			}
		}
		if(a[n]) calc(l, n);
		for(int i = 1; i < n; i++) {
			cout << a[i] << ans[i];
		}
		cout << a[n] << "\n";
	}
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