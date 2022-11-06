#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[65537];

map<int, vector<int> > mp;

int query(string s, int i, int j)
{
	cout << s << ' ' << i << ' ' << j << endl;
	int res; cin >> res;
	return res;
}

int main()
{
	ios::sync_with_stdio(0);
	//cin.tie(0), cout.tie(0);

	cin >> n;

	mp[0].push_back(1);

	for (int i = 1; i < n; i++)
	{
		int res = query("XOR", i, i + 1);
		a[i + 1] = a[i] ^ res;
		mp[a[i + 1]].push_back(i + 1);
	}

	bool hasAns = false;
	for (auto& it : mp)
	{
		if (it.second.size() > 1)
		{
			int i = it.second[0];
			int j = it.second[1];

			int res = query("OR", i, j);
			int d = a[i] ^ res;

			cout << "!";
			for (int i = 1; i <= n; i++) cout << ' ' << (a[i] ^ d);
			cout << endl;

			hasAns = true;
			break;
		}
	}

	if (hasAns) return 0;

	int i = 1;
	int j = mp[n - 1][0];

	int k = 2;
	if (j == 2) k = 3;

	int r1 = query("AND", i, k);
	int r2 = query("AND", j, k);

	int d = a[k] ^ (r1 | r2);

	cout << "!";
	for (int i = 1; i <= n; i++) cout << ' ' << (a[i] ^ d);
	cout << endl;
}