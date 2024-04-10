#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int win[100001], lose[100001];

int isWin(ll s, ll e)
{
	if (e % 2)
	{
		if (s % 2) return 0;
		else return 1;
	}
	else
	{
		if (s > e / 2)
		{
			if (s % 2) return 1;
			else return 0;
		}
		else if (s > e / 4) return 1;
		else return isWin(s, e / 4);
	}
}

int isLose(ll s, ll e)
{
	if (s > e / 2) return 1;
	return isWin(s, e / 2);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int cw = 0, cl = 1;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ll s, e; cin >> s >> e;
		win[i] = isWin(s, e);
		lose[i] = isLose(s, e);

		if (cw == cl) break;
		if (cl)
		{
			cw = win[i];
			cl = lose[i];
		}
		else
		{
			cw = 1 - win[i];
			cl = 1 - lose[i];
		}
	}

	cout << cw << ' ' << cl;
}