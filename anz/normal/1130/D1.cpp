#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#include <deque>
#include <set>
#include <unordered_map>
#include <bitset>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll gcd(ll a, ll b)
{
	while (b)
	{
		for (; b; a %= b, swap(a, b));
		return a;
	}
	return a;
}

int n, m;
vector <pii> candy[101];

bool func(pii a, pii b)
{
	return (a.second - a.first + n) % n < (b.second - b.first + n) % n;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		candy[a].push_back({a, b });
	}

	for (int i = 1; i <= n; i++)
		sort(candy[i].begin(), candy[i].end(), func);

	for (int i = 1; i <= n; i++)
	{
		vector <pii> _candy[101];
		for (int i = 1; i <= n; i++) _candy[i] = candy[i];


		vector <pii> train;
		int station = i;
		int cnt = 0;
		int ans = 0;
		while (true)
		{
			if (!_candy[station].empty())
			{
				train.push_back(_candy[station].back());
				_candy[station].pop_back();
			}

			for (int j = 0; j < train.size();)
				if (train[j].second == station)
				{
					cnt++;
					train.erase(train.begin() + j);
				}		
				else
				{
					j++;
				}

			if (cnt >= m) break;
			ans++;
			station++;
			if (station > n) station = 1;
		}
		
		printf("%d ", ans);
	}
}