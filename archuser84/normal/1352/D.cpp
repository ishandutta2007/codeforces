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

const int N = 200010;
ll a[N];
int n;

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		Loop(i, 0, n)
		{
			cin >> a[i];
		}
		ll al = a[0], bo = 0;
		ll l = a[0];
		int ans = 1;
		int p1 = 1, p2 = n - 1;
		bool turn = 1;
		if (n == 1)
		{
			cout << ans << ' ' << al << ' ' << bo << '\n';
			continue;
		}
		while (true)
		{
			ans++;
			if (turn == 1)
			{
				ll c = 0;
				while (c <= l)
				{
					c += a[p2];
					p2--;
					if (p2 < p1)
					{
						bo += c;
						goto End;
					}
				}
				bo += c;
				l = c;
			}
			else
			{
				ll c = 0;
				while (c <= l)
				{
					c += a[p1];
					p1++;
					if (p2 < p1)
					{
						al += c;
						goto End;
					}
				}
				al += c;
				l = c;
			}
			turn = !turn;
		}
	End:
		cout << ans << ' ' << al << ' ' << bo << '\n';
	}
}