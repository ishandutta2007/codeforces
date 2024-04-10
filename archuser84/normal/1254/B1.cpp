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

const int N = 1000010;

int n;
ll a[N];
ll sum;

ll find(ll d)
{
	ll ans = 0;
	ll s = 0;
	ll e;
	ll r = a[0] % d;
	while (true)
	{
		ll tmp = r;
		ll tmp2 = 0;
		Loop(i, s + 1, n)
		{
			tmp += a[i];
			tmp2 += ((ll)a[i]) * (i - s);
			if (tmp >= d)
			{
				e = i;
				break;
			}
		}
		if (tmp == 0)
			break;
		ll miin = tmp2;
		ll rtmp = r;
		r = tmp - d;
		tmp2 -= ((ll)r) * (e - s);
		tmp = rtmp;
		int p = s;
		while (true)
		{
			miin = min(tmp2, miin);
			tmp2 += tmp;
			tmp2 -= d - tmp;
			p++;
			if (p > e)
				break;
			tmp += a[p];
		}
		ans += miin;
		s = e;
		r = (tmp - d) % d;
	}
	return ans;
}

int main()
{
	FAST;
	cin >> n;
	Loop(i, 0, n)
	{
		cin >> a[i];
		sum += a[i];
	}
	if (sum <= 1)
	{
		cout << -1;
		return 0;
	}
	ll ans = find(sum);
	for (ll i = 2; i * i <= sum; i++)
	{
		if (sum % i == 0)
		{
			ans = min(ans, find(i));
			ans = min(ans, find(sum / i));
		}
	}
	cout << ans;
}