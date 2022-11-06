#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, k;
bool hasAns;

void query(int x)
{
	cout << x << endl;
	int res; cin >> res;
	if (res == -1) exit(3);
	if (res == 1) hasAns = true;
}

int main()
{
	ios::sync_with_stdio(0);
	//cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		hasAns = false;
		cin >> n >> k;

		query(0);
		if (hasAns) continue;

		for (int i = 1; i < n; i++)
		{
			query(i ^ (i - 1));
			if (hasAns) break;
		}
	}
}