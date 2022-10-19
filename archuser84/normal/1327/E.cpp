#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

int main()
{
	FAST;
	ll pow[200020];
	pow[0] = 1;
	Loop(i, 1, 200020)
	{
		pow[i] = (10 * pow[i - 1]) % Mod2;
	}
	int n;
	cin >> n;
	Loop(i, 1, n)
	{
		ll cnt = 0;
		cnt += (2 * 9LL * pow[n - i]) % Mod2;
		cnt = (cnt + (ll)(n - i - 1) * ((81LL * pow[n - i - 1]) % Mod2)) % Mod2;
		cout << cnt << ' ';
	}
	cout << 10;
}