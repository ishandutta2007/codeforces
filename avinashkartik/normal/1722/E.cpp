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

const ll   N     =  3e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;

int n, q, h[N], w[N], hs, ws1, hb, wb;
ll p[1001][1001];

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> h[i] >> w[i];
		p[h[i]][w[i]] += h[i] * w[i];
	}
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) {
			p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
		}
	}
	while (q--) {
		cin >> hs >> ws1 >> hb >> wb;
		hb--, wb--;
		ll ans = p[hs][ws1] + p[hb][wb] - p[hs][wb] - p[hb][ws1];
		deb1(ans)
	}
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= 1000; j++) {
			p[i][j] = 0;
		}
	}
}

int main() {
	GODSPEED;
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}