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

ll gcd(ll a, ll b)
{
	for (; b; a %= b, swap(a, b));
	return a;
}

vector <int> ab[200001];

int main()
{
	int n; string s;
	cin >> n >> s;
	for (int i = 0; i < s.size(); i++)
	{
		ab[i].resize(26);
		if (i) ab[i] = ab[i - 1];
		ab[i][s[i] - 'a']++;
	}

	int m; scanf("%d", &m);
	while (m--)
	{
		string t; cin >> t;
		vector <int> tmp(26);
		for (int i = 0; i < t.size(); i++)
			tmp[t[i] - 'a']++;


		int lo = 0, hi = n - 1;
		while (hi > lo)
		{
			int mid = (lo + hi) / 2;
			bool flag = true;
			for (int i = 0; i < 26; i++)
			{
				if (tmp[i] > ab[mid][i])
				{
					flag = false;
					break;
				}
			}

			if (flag) hi = mid;
			else lo = mid + 1;
		}

		printf("%d\n", hi + 1);
	}
}