#include <iostream>
#include <string.h>
#include <math.h>
#include <memory.h>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define YN(flag) cout<<(flag?"YES\n":"NO\n")
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 65;

int main()
{
	FAST;
	int cnt[N] = {};
	int ans = 0;
	bool can = 1;
	ll u, v;
	cin >> u >> v;
	for (int i = 0; i < 64; i++)
	{
		bool a = u & 1, b = v & 1;
		if (a && b)
			cnt[i]++;
		else if (a && !b)
		{
			if (i == 0)
			{
				can = false;
				break;
			}
			cnt[i - 1] += 2;
			cnt[i]++;
			v -= 2;
			if (v < 0)
			{
				can = false;
				break;
			}
		}
		else if (!a && b)
		{
			if (i == 0)
			{
				can = false;
				break;
			}
			cnt[i - 1] += 2;
		}
		u >>= 1;
		v >>= 1;
	}
	if (!can)
	{
		cout << "-1\n";
		return 0;
	}
	ll a[3] = {};
	Loop(i, 0, 64)
	{
		ans = max(ans, cnt[i]);
		a[0] += (ll)(cnt[i] > 0) << i;
		a[1] += (ll)(cnt[i] > 1) << i;
		a[2] += (ll)(cnt[i] > 2) << i;
	}
	cout << ans << '\n';
	Loop(i, 0, ans)
		cout << a[i] << ' ';
}