#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

string a;
vector <int> idx[4];

int segTree[100001];
void update(int i, int x)
{
	while (i <= a.size())
	{
		segTree[i] += x;
		i += i & -i;
	}
}
int getVal(int i)
{
	int res = 0;
	while (i)
	{
		res += segTree[i];
		i -= i & -i;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		for (int i = 0; i < 4; i++) idx[i].clear();

		cin >> a;
		for (int i = 0; i < a.size(); i++)
		{
			char c = a[i];
			if (c == 'A') idx[0].push_back(i + 1);
			else if (c == 'N') idx[1].push_back(i + 1);
			else if (c == 'O') idx[2].push_back(i + 1);
			else if (c == 'T') idx[3].push_back(i + 1);
		}

		ll ans = -1;
		vector <int> ans_perm;

		vector <int> perm = { 0,1,2,3 };
		do
		{
			for (int i = 0; i < a.size(); i++)
			{
				update(i + 1, 1);
			}

			ll res = 0;
			ll ai = 1;
			for (int i = 0; i < perm.size(); i++)
			{
				for (auto x : idx[perm[i]])
				{
					ll ci = getVal(x - 1) + ai;
					res += llabs(ci - ai);
					++ai;

					update(x, -1);
				}
			}

			if (res > ans)
			{
				ans = res;
				ans_perm = perm;
			}
		}
		while (next_permutation(perm.begin(), perm.end()));

		for (int x : ans_perm)
		{
			for (int i = 0; i < idx[x].size(); i++)
			{
				if (x == 0) cout << 'A';
				else if (x == 1) cout << 'N';
				else if (x == 2) cout << 'O';
				else if (x == 3) cout << 'T';
			}
		}

		cout << '\n';
	}
}