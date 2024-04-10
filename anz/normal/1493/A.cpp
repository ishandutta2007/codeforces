#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, k;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> k;
		vector <int> ans;
		for (int i = n; i > k; i--) ans.push_back(i);
		for (int i = k - 1; i >= (k + 1) / 2; i--) ans.push_back(i);

		cout << ans.size() << '\n';
		for (int x : ans) cout << x << ' ';
		cout << '\n';
	}
}