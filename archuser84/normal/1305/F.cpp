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
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

const int N = 200000;
int n;
ll a[N];
int Ans;
const int t = 30;

ll getAns(ll p)
{
	ll ans = 0;
	Loop(i, 0, n)
	{
		if (a[i] < p)
			ans += p - a[i] % p;
		else
			ans += min(a[i] % p, p - a[i] % p);
	}
	return ans;
}

queue<ll> fac;
void factor(ll x)
{
	ll y = x;
	for (ll i = 2; i * i <= y; i++)
	{
		if (y % i == 0)
		{
			fac.push(i);
			while (y % i == 0)
				y /= i;
		}
	}
	if (y > 1)
		fac.push(y);
}

void Do(int k)
{
	ll ans;

	factor(a[k] - 1);
	while (!fac.empty())
	{
		ll p = fac.front();
		fac.pop();
		ans = getAns(p);
		if (ans < Ans)
			Ans = ans;
	}

	factor(a[k]);
	while (!fac.empty())
	{
		ll p = fac.front();
		fac.pop();
		ans = getAns(p);
		if (ans < Ans)
			Ans = ans;
	}

	factor(a[k] + 1);
	while (!fac.empty())
	{
		ll p = fac.front();
		fac.pop();
		ans = getAns(p);
		if (ans < Ans)
			Ans = ans;
	}
}

int main()
{
	cin >> n;
	Ans = n;
	Loop(i, 0, n)
		cin >> a[i];
	if (n <= t)
	{
		Loop(i, 0, n)
			Do(i);
	}
	else
	{
		int x = (n + t - 1) / t - 1;
		int i = 0;
		Loop(j, 0, t)
		{
			Do(i);
			i += x;
		}
		Do(n - 1);
	}
	cout << Ans;
}