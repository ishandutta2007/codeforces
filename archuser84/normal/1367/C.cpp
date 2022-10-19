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
#define Kill(x) {cout << x << '\n'; return 0;}
using namespace std;

const int N = 200010;
char a[N];
int b[N];

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		int n, k; cin >> n >> k >> a; k++;
		int l = -2 * k - 10;
		Loop(i, 0, n)
		{
			if (a[i] - '0')
				l = i;
			b[i] = i - l;
		}
		l = n + 2 * k + 10;
		LoopR(i, 0, n)
		{
			if (a[i] - '0')
				l = i;
			b[i] = min(b[i], l - i);
		}
		int ans = 0;
		int cnt = 0;
		Loop(i, 0, n)
		{
			if (b[i] < k)
			{
				ans += cnt / k + (bool)(cnt % k);
				cnt = 0;
			}
			else
				cnt++;
		}
		ans += cnt / k + (bool)(cnt % k);
		printf("%i\n", ans);
	}
}