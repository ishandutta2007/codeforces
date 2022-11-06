#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <cmath>
#include <climits>
#include <complex>
#include <ctime>
#include <random>
#include <functional>
#include <chrono>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[5001];

int fr[5001], bk[5001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		memset(fr, 0, sizeof fr);
		memset(bk, 0, sizeof bk);

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			bk[a[i]]++;
		}

		bool ans = false;
		for (int i = 0; i < n; i++)
		{
			int x = a[i];
			bk[a[i]]--;

			for (int j = 1; j <= n; j++)
			{
				if (fr[j] && bk[j])
				{
					ans = true;
					break;
				}
			}

			fr[x]++;
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}