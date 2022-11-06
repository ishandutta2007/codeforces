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
int p[500001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) p[i] = 0;
		
		int last = -1;
		int ptr = 0;
		for (int i = 0; i < n; i++)
		{
			int tmp; cin >> tmp;
			if (i && last != tmp) ptr++;
			p[ptr]++;
			last = tmp;
		}

		int g = 0, s = 0, b = 0;

		int curSum = 0;
		for (ptr; ptr >= 0; ptr--)
		{
			curSum += p[ptr];
			if (curSum >= (n + 1) / 2)
			{
				break;
			}
		}

		if (ptr < 3)
		{
			cout << "0 0 0\n";
			continue;
		}

		g = p[0];

		int it = 1;
		for (it; it < ptr; it++)
		{
			s += p[it];
			if (s > g)
			{
				it++;
				break;
			}
		}

		for (it; it < ptr; it++)
		{
			b += p[it];
		}

		if (g >= s || g >= b)
		{
			cout << "0 0 0\n";
			continue;
		}

		cout << g << ' ' << s << ' ' << b << '\n';
	}
}