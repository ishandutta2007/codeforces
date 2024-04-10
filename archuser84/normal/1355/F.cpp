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

const ll qs[16] = { 614889782588491410LL, 38655288426304091LL, 22125549654501673LL, 316773187163046517LL, 9879251463499721LL, 39049078408188253LL, 108538288030848139LL, 309619196508457007LL, 796229312542859009LL, 4064625951224869LL, 6860596063872959LL, 10626236358872441LL, 17092564102090369LL, 30150641449095443LL, 43889293834596251LL, 234118799LL, };
const ll e18 = 1000000000000000000LL;
const int e9 = 1000000000;

queue<ll> Q1;
void factor1(ll x)
{
	for (ll i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			Q1.push(i);
			x /= i;
		}
	}
	if (x > 1)
		Q1.push(x);
}

queue<int> Q2;
int sum = 0;
void factor2(ll x)
{
	for (ll i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			int cnt = 0;
			while (x % i == 0)
			{
				cnt++;
				x /= i;
			}
			sum += cnt;
			Q2.push(cnt + 1);
		}
	}
	if (x > 1)
	{
		sum++;
		Q2.push(2);
	}
}

ll getMax(ll x)
{
	ll y = 1;
	while (y <= e9 / x)
		y *= x;
	return y;
}

void Solve()
{
	for (auto x : qs)
	{
		ll y;
		printf("? %lli\n", x);
		fflush(stdout);
		scanf("%lli", &y);
		factor1(y);
	}
	while (!Q1.empty())
	{
		ll a = Q1.front(); Q1.pop();
		ll b = e9 + 1;
		if (!Q1.empty())
		{
			b = Q1.front(); Q1.pop();
		}
		ll y;
		printf("? %lli\n", getMax(a) * getMax(b));
		fflush(stdout);
		scanf("%lli", &y);
		factor2(y);
	}
	if (sum < 2)
	{
		sum = 0;
		while (!Q2.empty())
			Q2.pop();
		printf("! 8\n");
		fflush(stdout);
		return;
	}
	sum = 0;
	ll ans = 2;
	while (!Q2.empty())
	{
		ans *= Q2.front();
		Q2.pop();
	}
	printf("! %lli\n", ans);
	fflush(stdout);
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Solve();
	}
}