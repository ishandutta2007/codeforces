#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

string a, b;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> a >> b;
		int g = gcd(a.size(), b.size());

		bool flag = false;
		for (int i = 0; i < a.size(); i += g)
		{
			if (a.substr(i, g) != a.substr(0, g)) flag = true;
		}

		for (int i = 0; i < b.size(); i += g)
		{
			if (b.substr(i, g) != b.substr(0, g)) flag = true;
		}

		if (a.substr(0, g) != b.substr(0, g)) flag = true;

		if (flag)
		{
			cout << "-1\n";
			continue;
		}

		//cout << "ANS:";
		string res = a.substr(0, g);
		int cnt = a.size() * b.size() / g / g;
		for (int i = 0; i < cnt; i++) cout << res;
		cout << '\n';
	}
}