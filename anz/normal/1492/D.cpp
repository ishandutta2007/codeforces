#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int r1[200001];
int r2[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int a, b, k; cin >> a >> b >> k; b--;

	if (k == 0)
	{
		cout << "Yes\n";
		cout << 1;
		for (int i = 0; i < a; i++) cout << 0;
		for (int i = 0; i < b; i++) cout << 1;
		cout << '\n';
		cout << 1;
		for (int i = 0; i < a; i++) cout << 0;
		for (int i = 0; i < b; i++) cout << 1;

		return 0;
	}

	if (a == 0 || b == 0)
	{
		cout << "No";
		return 0;
	}

	if (k >= a + b)
	{
		cout << "No";
		return 0;
	}

	cout << "Yes\n";

	memset(r1, -1, sizeof r1);
	memset(r2, -1, sizeof r2);

	r1[0] = 1, r2[0] = 0;
	r1[k] = 0, r2[k] = 1;

	int rm = a - 1;
	for (int i = 1; i < a + b; i++)
	{
		if (i == k) continue;
		if (rm)
		{
			r1[i] = r2[i] = 0;
			rm--;
		}
		else r1[i] = r2[i] = 1;
	}

	cout << 1;
	for (int i = 0; i < a + b; i++) cout << r1[i];
	cout << '\n';

	cout << 1;
	for (int i = 0; i < a + b; i++) cout << r2[i];
	cout << '\n';
}