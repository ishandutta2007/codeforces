#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <unordered_map>
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
int n;

int Solve(int bob)
{
	int miin = 0;
	int sum = 0;
	int ans = 0;
	Loop(i, 0, n)
	{
		if (a[i] > bob)
		{
			miin = sum = 0;
			continue;
		}
		sum += a[i];
		miin = min(miin, sum);
		ans = max(ans, sum - miin - bob);
	}
	ans = max(ans, sum - miin - bob);
	return ans;
}

int main()
{
	FAST;
	cin >> n;
	Loop(i, 0, n)
		cin >> a[i];
	int ans = 0;
	Loop(i, 1, 31)
		ans = max(ans, Solve(i));
	cout << ans;
}