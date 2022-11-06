#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int k[501];

bool query(int a, int b)
{
	cout << "? " << a << ' ' << b << endl;
	string res; cin >> res;
	return res == "Yes";
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> k[i];

	vector <pair<int, pii> > v;
	for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++)
	{
		int a = i, b = j;
		if (k[a] < k[b]) swap(a, b);

		v.push_back({ k[a] - k[b],{a,b} });
	}

	sort(v.rbegin(), v.rend());
	
	for (auto it : v)
	{
		int a = it.second.first, b = it.second.second;
		if (query(a, b))
		{
			cout << "! " << a << ' ' << b << endl;
			return 0;
		}
	}

	cout << "! 0 0" << endl;
}