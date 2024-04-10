#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int main()
{
	pll a[4];
	for (int i = 1; i <= 3; i++)
	{
		cin >> a[i].first;
		a[i].second = i;
	}

	sort(a + 1, a + 4);

	cout << "First" << endl;

	ll plus = 2 * a[3].first - a[1].first - a[2].first;
	cout << plus << endl;

	int res; cin >> res;
	int ridx = 0;
	for (int i = 1; i <= 3; i++)
	{
		if (res == a[i].second) ridx = i;
	}

	if (ridx == 3)
	{
		a[3].first += plus;
		plus = 2 * a[3].first - a[1].first - a[2].first;
		cout << plus << endl;

		cin >> res;
		for (int i = 1; i <= 3; i++)
		{
			if (res == a[i].second) ridx = i;
		}
	}

	if (ridx == 1)
		plus = a[3].first - a[2].first;
	else
		plus = a[3].first - a[1].first;

	cout << plus << endl;

	cin >> res;
	return 0;
}