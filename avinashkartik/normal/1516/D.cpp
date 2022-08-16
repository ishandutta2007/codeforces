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

const ll   N     =  3e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

int n, q, a[N], l[N], st[N][LEVEL], m[N], p[N];

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i], l[i] = n + 1;
	for (int i = 1; i <= n; i++) {
		while (a[i] > 1) {
			int x = p[a[i]];
			while (a[i] % x == 0) {
				a[i] /= x;
			}
			if (m[x]) {
				l[m[x]] = min(l[m[x]], i);
			}
			m[x] = i;
		}
	}
	for (int i = n - 1; i >= 1; i--) l[i] = min(l[i], l[i + 1]);
	mset(st, -1);
	for (int j = 0; j < LEVEL; j++) {
		for (int i = 1; i <= n; i++) {
			if (j == 0 && l[i]) st[i][j] = l[i];
			else if (j && st[i][j - 1] != -1) st[i][j] = st[st[i][j - 1]][j - 1];
		}
	}
	for (int i = 1; i <= q; i++) {
		int l, r, ans = 0; cin >> l >> r;
		for (int i = LEVEL - 1; i >= 0; i--) {
			if (st[l][i] != -1 && st[l][i] <= r) {
				ans += (1 << i);
				l = st[l][i];
			}
		}
		deb1(ans + 1)
	}
}

int main() {
	GODSPEED;
	mset(p, 0);
	for (int i = 2; i * i < N; i++) {
		if (p[i] == 1) continue;
		for (int j = i * i; j < N; j += i) {
			if (p[j] == 0) p[j] = i;
		}
	}
	for (int i = 1; i < N; i++) if (!p[i]) p[i] = i;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}