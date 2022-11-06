#include <bits/stdc++.h>
#include <random>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[200001];

int segTree[200001];
void update(int ptr, int x)
{
	while (ptr <= n)
	{
		segTree[ptr] += x;
		ptr += ptr & -ptr;
	}
}

int getVal(int ptr)
{
	int res = 0;
	while (ptr)
	{
		res += segTree[ptr];
		ptr -= ptr & -ptr;
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++) segTree[i] = 0, cin >> a[i];

		ll ans = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] < i)
			{
				ans += getVal(max(0, a[i] - 1));
				update(i, 1);
			}
		}

		cout << ans << '\n';
	}
}