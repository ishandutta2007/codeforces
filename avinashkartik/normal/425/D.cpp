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

const ll   N     =  2e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const int  LEVEL =  log2(N) + 1;

int n, m, k;
int a[101][101];

void solve() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	if (n > k) {
		int ans = INFi;
		for (int r = 1; r <= n; r++) {
			int res = 0;
			for (int i = 1; i <= n; i++) {
				vector <int> ct(2, 0);
				for (int j = 1; j <= m; j++) {
					ct[a[r][j] ^ a[i][j]]++;
				}
				res += min(ct[0], ct[1]);
			}
			ans = min(ans, res);
		}
		if (ans <= k) deb1(ans)
		else deb1(-1)
	} else {
		int ans = INFi;
		for (int r = 0; r < (1 << n); r++) {
			int res = 0;
			for (int i = 1; i <= m; i++) {
				vector <int> ct(2, 0);
				for (int j = 1; j <= n; j++) {
					ct[((r >> (j - 1)) & 1) ^ a[j][i]]++;
				}
				res += min(ct[0], ct[1]);
			}
			ans = min(ans, res);
		}
		if (ans <= k) deb1(ans)
		else deb1(-1)
	}
}

int main() {
	GODSPEED;
	int test = 1;
	// cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}