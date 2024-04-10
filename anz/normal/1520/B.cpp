#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

vector <int> v;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			int tmp = 0;
			for (int k = 0; k < i; k++)
			{
				tmp *= 10;
				tmp += j;
			}
			v.push_back(tmp);
		}
	}

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		cout << upper_bound(v.begin(), v.end(), n) - v.begin() << '\n';
	}
}