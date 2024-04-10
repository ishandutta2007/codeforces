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

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int INF = 987654321;
const int N = 200001;
int n;
string s;
set <int> idx[26];
int ans[N];

int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		idx[s[i] - 'a'].insert(i);
	}

	int color = 1;
	for (int i = 0; i < n; i++)
	{
		if (ans[i]) continue;
		int ci = i;
		while (true)
		{
			int c = s[ci] - 'a';
			ans[ci] = color;
			idx[c].erase(ci);
			
			int nxt = INF;
			for (int j = c; j < 26; j++)
			{
				auto res = idx[j].upper_bound(ci);
				if (res == idx[j].end()) continue;
				nxt = min(nxt, *res);
			}

			if (nxt == INF) break;
			ci = nxt;
		}

		color++;
	}

	cout << color - 1 << '\n';
	for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}