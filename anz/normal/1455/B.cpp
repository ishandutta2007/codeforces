#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

vector <int> vec;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int sum = 0;
	for (int i = 1; sum <= 1000000; i++)
	{
		sum += i;
		vec.push_back(sum);
	}

	int t; cin >> t;
	while (t--)
	{
		int x; cin >> x;
		for (int i = 0; i < vec.size(); i++)
		{
			if (x <= vec[i])
			{
				if (x == vec[i] - 1) cout << i + 2 << '\n';
				else cout << i + 1 << '\n';
				break;
			}
		}
	}
}