///
///   There's a reason for your defeat, DIO. One simple reason...
///   You pissed me off.
///

#include <bits/stdc++.h>
#define Loop(x,l,r) for(ll x = ll(l); x < ll(r); ++x)
#define LoopR(x,l,r) for(ll x = ll(r)-1; x >= ll(l); --x)
#define Kill(x) exit((cout << (x) << '\n', 0))
typedef long long ll;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
using namespace std;

const int N = 200'010;
int a[N], b[N];
int rem[N];
int n;

void solve()
{
	cin >> n;
	Loop (i,0,n+5) rem[i] = 0;
	Loop (i,0,n) {
		cin >> a[i];
	}
	Loop (i,0,n) cin >> b[i];
	int i = n-1;
	int j = n-1;
	while (j >= 0) {
		while (a[i] != b[j]) {
			if (rem[a[i]]) {
				--rem[a[i]];
				--i;
			} else {
//				cout << i << ' ' << j << '\n';
				cout << "NO\n";
				return;
			}
		}
		--rem[a[i]];
		while (j >= 0 && b[j] == a[i]) {
			--j;
			++rem[a[i]];
		}
		--i;
	}
	cout << "YES\n";
}

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) solve();
}