#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
ll a[200001];
string s;
vector <int> b, r;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		b.clear(), r.clear();

		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		cin >> s;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == 'B') b.push_back(a[i]);
			else r.push_back(a[i]);
		}

		sort(b.begin(), b.end());
		sort(r.begin(), r.end());
		reverse(r.begin(), r.end());

		bool ans = true;
		for (int i = 0; i < b.size(); i++)
		{
			if (b[i] < i + 1) ans = false;
		}
		for (int i = 0; i < r.size(); i++)
		{
			if (r[i] > n - i) ans = false;
		}

		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}
}