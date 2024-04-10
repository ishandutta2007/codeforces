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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
vector <string> s, t;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string tmp; cin >> tmp;
		s.push_back(tmp);
	}
	for (int i = 0; i < m; i++)
	{
		string tmp; cin >> tmp;
		t.push_back(tmp);
	}

	int q; cin >> q;
	while (q--)
	{
		int y; cin >> y;
		y--;
		y %= n * m;

		int np = 0, mp = 0;
		for (int i = 0; i < y; i++)
		{
			np++, mp++;
			if (np >= n) np = 0;
			if (mp >= m) mp = 0;
		}
		cout << s[np] << t[mp] << '\n';
	}
}