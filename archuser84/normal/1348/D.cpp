#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) (flag? "YES\n": "NO\n")
#define all(x) x.begin(),x.end()
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
#define Bit(x,k) ((x >> k) & 1)
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll sum = 1;
		ll x = 2;
		vector<int> ans; ans.push_back(1);
		while (sum < n)
		{
			if (sum + x <= n)
			{
				sum += x;
				ans.push_back(x);
				x <<= 1;
			}
			else
			{
				ll tem1 = ans.back();
				ll tem2 = n - sum;
				if (tem1 <= tem2)
				{
					ans.push_back(tem2);
				}
				else
				{
					ans.pop_back();
					ans.push_back((tem1 + tem2) / 2);
					ans.push_back((tem1 + tem2 + 1) / 2);
				}
				sum = n;
			}
		}
		cout << ans.size() - 1 << '\n';
		Loop(i, 1, ans.size())
			cout << ans[i] - ans[i - 1] << ' ';
		cout << '\n';
	}
}