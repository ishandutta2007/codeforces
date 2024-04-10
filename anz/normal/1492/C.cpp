#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
string s, t;

vector <int> idx[26];

int mn[200001];
int mx[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	cin >> s >> t;

	for (int i = 0; i < n; i++)
		idx[s[i] - 'a'].push_back(i);

	int last = 0;
	for (int i = 0; i < m; i++)
	{
		vector <int>& cur = idx[t[i] - 'a'];
		int res = *lower_bound(cur.begin(), cur.end(), last);

		mn[i] = res;
		last = res + 1;
	}

	last = n;
	for (int i = m - 1; i >= 0; i--)
	{
		vector <int>& cur = idx[t[i] - 'a'];
		int res = *prev(lower_bound(cur.begin(), cur.end(), last));

		mx[i] = res;
		last = res;
	}

	int ans = 0;
	for (int i = 0; i < m - 1; i++)
		ans = max(ans, mx[i + 1] - mn[i]);

	cout << ans;
}