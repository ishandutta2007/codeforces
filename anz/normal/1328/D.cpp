#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int t[200001];
vector <int> stk;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int q; cin >> q;
	while (q--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> t[i];
		stk.clear();

		stk.push_back(t[0]);

		bool hasDouble = false;
		for (int i = 1; i < n; i++)
		{
			if (t[i] != stk.back()) stk.push_back(t[i]);
			else hasDouble = true;
		}

		if (stk.size() > 1 && stk.front() == stk.back())
		{
			//stk.pop_back();
			hasDouble = true;
		}

		if (stk.size() == 1)
		{
			cout << "1\n";
			for (int i = 0; i < n; i++) cout << "1 ";
			cout << '\n';
			continue;
		}
		else
		{
			if (n % 2 == 0)
			{
				cout << "2\n";
				for (int i = 0; i < n; i++) cout << i % 2 + 1 << ' ';
				cout << '\n';
			}
			else
			{
				if (hasDouble)
				{
					cout << "2\n";
					int flag = 0;
					for (int i = 0; i < n; i++)
					{
						if (!flag && i && t[i - 1] == t[i]) flag = 1;
						cout << (i + flag) % 2 + 1 << ' ';
					}
					cout << '\n';
				}
				else
				{
					cout << "3\n";
					for (int i = 0; i < n - 1; i++) cout << i % 2 + 1 << ' ';
					cout << "3\n";
				}
			}
		}
	}
}