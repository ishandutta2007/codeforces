#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define all(x) x.begin(),x.end()
#define Bit(x,k) ((x >> k) & 1)
#define Mod1 1000000007
#define Mod2 998244353
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Kill(x) {cout << x << '\n'; return 0;}
#define YN(flag) (flag? "YES": "NO")
using namespace std;

const int N = 300010;
int a[N];
int n, z;

int findMax(int n)
{
	int maax = a[0] + a[1];
	int ans = 0;
	Loop(i, 1, n)
	{
		if (a[i] + a[i + 1] > maax)
		{
			maax = a[i] + a[i + 1];
			ans = i;
		}
	}
	return ans;
}

int main()
{
	FAST;
	int t;
	cin >> t;
	while (t--)
	{
		int k;
		cin >> n >> k >> z;
		Loop(i, 0, n)
			cin >> a[i];
		n = k + 1;
		ll sum = 0;
		Loop(i, 0, n)
			sum += a[i];
		ll ans = sum;
		Loop(i, 1, z + 1)
		{
			if (n - 2 * i <= 0)
				break;
			int p = findMax(n - 2 * i);
			sum -= a[n - 2 * i + 1] + a[n - 2 * i];
			ans = max(ans, sum + i * (a[p] + a[p + 1]));
		}
		/*while (z)
		{
			auto x = findMax();
			sum += a[x] + a[x + 1];
			sum -= a[n - 2] + a[n - 1];
			n -= 2;
			z--;
			ans = max(ans, sum);
		}*/
		cout << ans << '\n';
	}
}