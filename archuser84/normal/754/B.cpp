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
	char s[4][5];
	Loop(i,0,4) cin >> s[i];
	Loop(i,0,4) Loop(j,0,2)
		if ((s[i][j] == 'x') + (s[i][j+1] == 'x') + (s[i][j+2] == 'x') == 2
		    && (s[i][j] == 'o') + (s[i][j+1] == 'o') + (s[i][j+2] == 'o') == 0)
			Kill("YES");
	Loop(i,0,2) Loop(j,0,4)
		if ((s[i][j] == 'x') + (s[i+1][j] == 'x') + (s[i+2][j] == 'x') == 2
		    && (s[i][j] == 'o') + (s[i+1][j] == 'o') + (s[i+2][j] == 'o') == 0)
			Kill("YES");
	Loop(i,0,2) Loop(j,0,2)
		if ((s[i][j] == 'x') + (s[i+1][j+1] == 'x') + (s[i+2][j+2] == 'x') == 2
		    && (s[i][j] == 'o') + (s[i+1][j+1] == 'o') + (s[i+2][j+2] == 'o') == 0)
			Kill("YES");
	Loop(i,0,2) Loop(j,2,4)
		if ((s[i][j] == 'x') + (s[i+1][j-1] == 'x') + (s[i+2][j-2] == 'x') == 2
		    && (s[i][j] == 'o') + (s[i+1][j-1] == 'o') + (s[i+2][j-2] == 'o') == 0)
			Kill("YES");
	Kill("NO");
}