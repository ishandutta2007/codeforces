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
typedef  pair<ll, ll>          pll;
typedef  vector<ll>            vll;
typedef  vector<pll>           vpll;

const ll   N     =  1e3 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n;

void solve() {
	cin >> n;
	vector <int> a(n + 1, 0);
	map <int, int> m;
	int ans = 2;
	for (int i = 0; i < n; i++) cin >> a[i], m[a[i]]++, ans = max(ans, m[a[i]]);
	a[n] = INFi;
	sort(all(a));
	uniq(a);
	int nn = n;
	n = a.size() - 1;

	for (int st = 0; st <= n - 2; st++) {
		int cnt = 2, next;
		ll prv = st;
		ll cur = st + 1;
		while (1) {
			next = lower_bound(a.begin(), a.end(), a[cur] + a[cur] - a[st]) - a.begin();
			if (next >= n) break;
			cnt++;
			// deb3(st, cur, next)
			prv = cur;
			cur = next;
		}
		ans = max(ans, cnt + m[a[st]] - 1);
	}
	deb1(nn - ans)
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}