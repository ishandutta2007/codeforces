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

const int N = 200001;

int n, m;
set <pii> s;
int a[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		s.insert({ a[i],-i });
	}

	cin >> m;
	while (m--)
	{
		int tmp[N];
		memcpy(tmp, a, sizeof a);

		int k, pos;
		cin >> k >> pos;

		auto it = s.begin();
		for (int i = 0; i < n - k; i++)
		{
			tmp[-it->second] = 0;
			it++;
		}

		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (tmp[i] == 0) continue;
			cnt++;
			if (cnt == pos)
			{
				cout << tmp[i] << '\n';
				break;
			}
		}
	}
}