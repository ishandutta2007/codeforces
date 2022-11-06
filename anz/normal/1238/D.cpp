#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n;
string s;

int nxtA[300001], nxtB[300001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	memset(nxtA, -1, sizeof nxtA);
	memset(nxtB, -1, sizeof nxtB);

	cin >> n >> s;
	int lA = -1, lB = -1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == 'A')
		{
			nxtA[i] = lA, lA = i;
			nxtB[i] = lB;
		}
		else
		{
			nxtA[i] = lA;
			nxtB[i] = lB, lB = i;
		}
	}

	ll ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		ll ca = nxtA[i];
		ll cb = nxtB[i];

		if (s[i] == 'A')
		{
			if (s[i + 1] != s[i])
			{
				if (ca == -1) continue;
				ans += n - ca;
			}
			else
			{
				if (cb == -1)
				{
					ans += n - i - 1;
				}
				else
				{
					ans += n - i - 2;
				}
			}
		}
		else
		{
			if (s[i + 1] != s[i])
			{
				if (cb == -1) continue;
				ans += n - cb;
			}
			else
			{
				if (ca == -1)
				{
					ans += n - i - 1;
				}
				else
				{
					ans += n - i - 2;
				}
			}
		}
	}

	cout << ans;
}