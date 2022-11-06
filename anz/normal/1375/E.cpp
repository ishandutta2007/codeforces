#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[1001];
int cnt[1001];
int idx[1001];

vector <int> v;

set <pii> st;
vector <pii> ans;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		v.push_back(a[i]);
	}

	sort(v.begin(), v.end());

	for (int i = 1; i <= n; i++)
	{
		int res = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
		a[i] = res + cnt[res]++;

		idx[a[i]] = i;
	}

	for (int i = n; i > 0; i--)
	{
		int cur = a[i];
		for (int j = cur + 1; j <= i; j++)
		{
			ans.push_back({ idx[j], i });

			int tmp = a[i];
			swap(a[i], a[idx[j]]);
			idx[tmp] = idx[j];
			idx[j] = i;
		}
	}

	cout << ans.size() << '\n';
	for (pii it : ans) cout << it.first << ' ' << it.second << '\n';
}