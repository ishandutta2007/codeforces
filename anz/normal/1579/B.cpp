#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[51];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		vector <pair<pii, int> > ans;

		for (int i = 0; i < n; i++)
		{
			int idx = min_element(a + i, a + n) - a;
			if (i == idx) continue;
			
			ans.push_back({ {i + 1,idx + 1},idx - i });
			int tmp = a[idx];
			for (int j = idx; j > i; j--) a[j] = a[j - 1];
			a[i] = tmp;
		}

		cout << ans.size() << '\n';
		for (auto it : ans)
			cout << it.first.first << ' ' << it.first.second << ' '
			<< it.second << '\n';
	}
}