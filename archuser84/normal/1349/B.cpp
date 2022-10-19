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

const int N = 100010;
int a[N];
int n, k;

int main()
{
	FAST;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		bool ans = 0;
		Loop(i, 0, n)
		{
			cin >> a[i];
			if (a[i] == k)
				ans = 1;
		}
		if (!ans)
		{
			cout << "NO\n";
			continue;
		}

		if (n == 1)
		{
			cout << "YES\n";
			continue;
		}
		if (n == 2)
		{
			cout << YN(a[0] >= k && a[1] >= k) << '\n';
			continue;
		}
		ans = 0;
		Loop(i, 0, n - 2)
		{
			int cnt = 0;
			cnt += a[i] >= k;
			cnt += a[i + 1] >= k;
			cnt += a[i + 2] >= k;
			if (cnt >= 2)
			{
				ans = 1;
				break;
			}
		}
		cout << YN(ans) << '\n';
	}
}