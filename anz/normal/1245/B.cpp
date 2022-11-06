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

int n, a, b, c;
vector <int> brps[3];
int ans[101];

int main()
{
	int T; cin >> T;
	while (T--)
	{
		cin >> n;
		cin >> a >> b >> c;
		for (int i = 0; i < 3; i++) brps[i].clear();
		memset(ans, -1, sizeof ans);
		string bob; cin >> bob;
		for (int i = 0; i < n; i++)
		{
			if (bob[i] == 'R') brps[0].push_back(i);
			if (bob[i] == 'P') brps[1].push_back(i);
			if (bob[i] == 'S') brps[2].push_back(i);
		}

		int wa, wb, wc;
		int canWin = 0;
		wa = min((int)brps[0].size(), b);
		wb = min((int)brps[1].size(), c);
		wc = min((int)brps[2].size(), a);

		if (wa + wb + wc > (n - 1) / 2)
		{
			cout << "YES\n";
			for (int i = 0; i < wa; i++)
				ans[brps[0][i]] = 1;
			for (int i = 0; i < wb; i++)
				ans[brps[1][i]] = 2;
			for (int i = 0; i < wc; i++)
				ans[brps[2][i]] = 0;

			b -= wa;
			c -= wb;
			a -= wc;

			for (int i = 0; i < n; i++)
			{
				if (ans[i] == -1)
				{
					if (b)
					{
						ans[i] = 1;
						b--;
					}
					else if (c)
					{
						ans[i] = 2;
						c--;
					}
					else if (a)
					{
						ans[i] = 0;
						a--;
					}
				}
			}

			for (int i = 0; i < n; i++)
			{
				if (ans[i] == 0) cout << 'R';
				if (ans[i] == 1) cout << 'P';
				if (ans[i] == 2) cout << 'S';
			}

			cout << '\n';
		}
		else cout << "NO\n";
	}
}