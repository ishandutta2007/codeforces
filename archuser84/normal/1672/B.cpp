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

int main()
{
	cin.tie(0) -> sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int a[2] = {};
		bool bad = 0;
		for (char c : s) {
			a[c == 'A']++;
			bad |= a[1] < a[0];
		}
		cout << (s.back() =='B' && !bad?
		    "YES\n": "NO\n");
	}
}