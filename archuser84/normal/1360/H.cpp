#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES": "NO")
#define all(x) x.begin(),x.end()
#define ll long long
#define pii pair<int,int>
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

ll inbin(int s)
{
	static char temp[100];
	cin >> temp;
	ll ans = 0;
	Loop(i, 0, s)
	{
		ans <<= 1;
		ans += temp[i] - '0';
	}
	return ans;
}
void outbin(int s, ll x)
{
	LoopR(i, 0, s)
		cout << Bit(x, i);
	cout << '\n';
}

int main()
{
	FAST;
	int q;
	cin >> q;
	while (q--)
	{
		map<ll, bool> X;
		int m, n;
		cin >> n >> m;
		ll ans = (1LL << (m - 1)) - 1;
		while (true)
		{
			ll x = inbin(m);
			X[x] = true;
			if (x <= ans)
				do
					++ans; while (X[ans]);
			if (!--n)
				break;
			x = inbin(m);
			X[x] = true;
			if(x >= ans)
				do
					--ans; while (X[ans]);
			if (!--n)
				break;
		}
		outbin(m, ans);
	}
}