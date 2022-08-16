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

const ll   N     =  1e5 + 5;
const ll   mod   =  1e9 + 7;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
const ll   LEVEL =  log2(N) + 1;

ll n, m;

void solve() {
	cin >> n >> m;
	int ans = 0, f = 1;
	for (int i = 31; i >= 0; i--) {
		int n1 = (n >> i)&1, m1 = (m >> i)&1;
		// deb3(i, n1, m1)
		if (n1 == m1) continue;
		else if (n1 == 1 && m1 == 0) {
			f = 0;
			break;
		} else if (n1 == 0 && m1 == 1) ans += (1 << i);
	}
	if (f == 1) {
		for (int i = 0; i <= 31; i++) {
			int m1 = (m >> i)&1;
			if (m1 == 0) {
				ans += (1 << i);
				for (int j = i - 1; j >= 0; j--) {
					if ((ans >> j)&1) ans -= (1 << j);
				}
				break;
			}
		}
	}
	deb1(ans)
}

int main() {
	int test = 1;
	cin >> test;
	for (int i = 1; i <= test; i++) {
		solve();
	}
}