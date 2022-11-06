#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> cpdb;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int ett[10001];
vector <int> p;
int a[200001];

int n, k;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	for (int i = 2; i <= 10000; i++)
	{
		if (ett[i] == 0)
		{
			p.push_back(i);
			for (int j = i + i; j <= 10000; j += i) ett[j] = 1;
		}
	}

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		for (int i = 0; i < n; i++) cin >> a[i];

		set <int> st;
		int ans = 1;
		for (int i = 0; i < n; i++)
		{
			int c = a[i];
			for (int j = 0; j < p.size() && p[j] * p[j] <= a[i]; j++)
			{
				while (c % (p[j] * p[j]) == 0) c /= p[j] * p[j];
			}

			if (st.find(c) != st.end())
			{
				ans++;
				st.clear();
			}

			st.insert(c);
		}

		cout << ans << '\n';
	}
}