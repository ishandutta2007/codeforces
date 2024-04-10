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

const int N = 200010;
int gnd[N];
bitset<N> smipr;
bitset<N> bs[128];
int smitof[N];

void sieve()
{
	for (ll x = 1; x < N; ++x) {
		for (ll y = x; y < N; y += x)
			smitof[y]++;
		for (ll y = x*x; y < N; y += x*x)
			smitof[y]++;
	}
	Loop (i,2,N)
		smipr[i] = smitof[i] <= 5;
}

int n, f;

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	sieve();
	cin >> n >> f;
	smipr[f] = 0;
	Loop (i,0,N) {
		Loop (k,0,128) {
			if (!bs[k][i]) {
				gnd[i] = k;
				break;
			}
		}
		bs[gnd[i]] |= smipr << i;
	}
	int ans = 0;
	while (n--) {
		int x, y, z;
		cin >> x >> y >> z;
		ans ^= gnd[z-y-1];
		ans ^= gnd[y-x-1];
	}
	cout << (ans? "Alice": "Bob") << '\n';
	cout << (ans? "Bob": "Alice") << '\n';
}