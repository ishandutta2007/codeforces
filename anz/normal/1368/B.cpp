#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

string cf = "codeforces";
ll cnt[10];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 0; i < 10; i++) cnt[i] = 1;

	ll k; cin >> k;
	if (k == 1)
	{
		cout << cf;
		return 0;
	}

	while (true)
	{
		for (int j = 0; j < 10; j++)
		{
			cnt[j]++;
			ll res = 1;
			for (int i = 0; i < 10; i++) res *= cnt[i];
			if (res >= k)
			{
				for (int l = 0; l < 10; l++)
				{
					for (int m = 0; m < cnt[l]; m++) cout << cf[l];
				}
				return 0;
			}
		}
	}
}