#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

ll n, k;
string s;
vector <vector <int> > ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	cin >> s;

	ll cnt = 0;
	while (true)
	{
		vector <int> res;
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i - 1] == 'R' && s[i] == 'L')
				res.push_back(i);
		}

		if (res.empty()) break;

		ans.push_back(res);
		cnt += res.size();

		for (int i : res) swap(s[i - 1], s[i]);
	}

	if (k < ans.size() || k > cnt)
	{
		cout << -1;
		return 0;
	}

	int sub = k - ans.size();
	for (auto& vec : ans)
	{
		if (sub && vec.size() > 1)
		{
			int tmp = min(sub, (int)vec.size() - 1);
			for (int i = 0; i < tmp; i++)
			{
				cout << 1 << ' ' << vec[i] << '\n';
			}

			cout << vec.size() - tmp << ' ';
			for (int i = tmp; i < vec.size(); i++)
				cout << vec[i] << ' ';
			cout << '\n';

			sub -= tmp;
		}
		else
		{
			cout << vec.size() << ' ';
			for (auto i : vec)
				cout << i << ' ';
			cout << '\n';
		}
	}
}