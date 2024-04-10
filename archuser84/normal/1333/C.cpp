#define _CRT_SECURE_NO_WARNINGS
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

const int N = 200000;
unordered_map<ll, int> vis;

int main()
{
	FAST;
	ll ans = 0;
	int n;
	cin >> n;
	vis[0] = -1;
	ll sum = 0;
	int last = -2;
	Loop(i, 0, n)
	{
		int x;
		cin >> x;
		sum += x;
		if (vis.count(sum))
			last = max(last, vis[sum]);
		ans += i - last - 1;
		vis[sum] = i;
	}
	cout << ans << '\n';
}