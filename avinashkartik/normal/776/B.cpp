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

const ll   N     =  2e5 + 5;
const ll   mod   =  1e9 + 6;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, a[N], cnt[N], inc[N], spf[N], sub[N], ans[N];
vector <int> fact[N];

void solve() {
	cin >> n;
	if (n < 3) deb1(1)
	else deb1(2)
	for (int i = 2; i <= n + 1; i++) {
		if (spf[i] == i) cout << 1 << " ";
		else cout << 2 << " ";
	}
	newl;
}

int main() {
	GODSPEED;
	for (int i = 1; i < N; i++) {
		for (int j = i; j < N; j += i) fact[j].push_back(i);
		spf[i] = fact[i][1];
		if (i == 1) inc[i] = 1;
		else if ((i / spf[i]) % spf[i] == 0) inc[i] = 0;
		else inc[i] = - inc[i / spf[i]];
		reverse(all(fact[i]));
	}
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}