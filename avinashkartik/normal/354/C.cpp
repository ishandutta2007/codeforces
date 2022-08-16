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

const ll   N     =  1e6 + 5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n, k, a[N], ct[N];

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i], ct[a[i]]++;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= 1e6; i++) ct[i] += ct[i - 1];
	for (int g = a[1]; g > min(a[1], k + 1); g--) {
		int tot = 0;
		for (int j = g, i = 1; j <= a[n]; j += g) {
			tot += ct[min(1000000, j + k)] - ct[j - 1];
		}
		if (tot == n) {
			deb1(g)
			return;
		}
	}
	deb1(min(a[1], k + 1))
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}