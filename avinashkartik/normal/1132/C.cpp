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

const ll   N     =  5005;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, q, l[N], r[N], c[N], ct[N][N][2];

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= q; i++) {
		cin >> l[i] >> r[i];
		for (int j = l[i]; j <= r[i]; j++) c[j]++;
	}
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		tot += (c[i] != 0);
		for (int j = i; j <= n; j++) {
			ct[i][j][0] = ct[i][j - 1][0] + (c[j] == 1);
			ct[i][j][1] = ct[i][j - 1][1] + (c[j] == 2);
		}
	}
	int ans = 0;
	for (int i = 1; i <= q; i++) {
		for (int j = i + 1; j <= q; j++) {
			if (l[i] > r[j] || l[j] > r[i]) {
				ans = max(ans, tot - ct[l[i]][r[i]][0] - ct[l[j]][r[j]][0]);
			} else {
				ans = max(ans, tot - ct[min(l[i], l[j])][max(l[i], l[j]) - 1][0] - ct[max(l[i], l[j])][min(r[j], r[i])][1] - ct[min(r[j], r[i]) + 1][max(r[j], r[i])][0]);
			}
		}
	}
	deb1(ans)
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}