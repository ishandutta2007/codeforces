#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int isPrime[500001];

int n;
int cnt[500001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 2; i * i <= 500000; i++)
	{
		if (isPrime[i] == 0)
		{
			isPrime[i] = i;
			for (int j = i + i; j <= 500000; j += i)
			{
				if (isPrime[j] == 0) isPrime[j] = i;
				else isPrime[j] = min(isPrime[j], i);
			}
		}
	}

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (isPrime[i] == 0) isPrime[i] = i;
		cnt[i / isPrime[i]]++;
	}

	for (int i = 1; i <= n; i++)
	{
		int j = 0;
		if (i == 1) j = 1;
		for (; j < cnt[i]; j++) cout << i << ' ';
	}
}