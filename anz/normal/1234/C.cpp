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

int n;
string pipe[2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int q; cin >> q;
	while (q--)
	{
		cin >> n;
		cin >> pipe[0] >> pipe[1];

		bool isOk = true;

		int cd = 0;
		for (int i = 0; i < n; i++)
		{
			if (pipe[cd][i] >= '3')
			{
				cd = 1 - cd;
				if (pipe[cd][i] < '3')
				{
					isOk = false;
					break;
				}
			}
		}

		if (cd == 0) isOk = false;
		if (isOk) cout << "YES\n";
		else cout << "NO\n";
	}
}