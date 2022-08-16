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
typedef  pair<ll, ll>           pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  1e5 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, a[N];

void solve() {
	cin >> n;
	set <int> s;
	for(int i = 1; i <= n; i++) cin >> a[i], s.insert(i);
	queue <int> q;
	vector <int> ans;
	for(int i = 1; i <= n; i++) {
		if(s.find(i) != s.end()) {
			auto it = s.upper_bound(i);
			if(it == s.end()) it = s.begin();
			if(__gcd(a[i], a[*it]) == 1){
				ans.pb(*it);
				s.erase(*it);
				q.push(i);
			}
		}
	}
	while(q.size()) {
		int i = q.front();
		q.pop();
		if(s.find(i) != s.end()) {
			auto it = s.upper_bound(i);
			if(it == s.end()) it = s.begin();
			if(__gcd(a[i], a[*it]) == 1){
				ans.pb(*it);
				s.erase(*it);
				q.push(i);
			}
		}
	}
	cout << ans.size() << " ";
	debv(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}