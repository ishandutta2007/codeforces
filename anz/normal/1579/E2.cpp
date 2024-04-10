#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[200001];
vector <int> v;

int segTree[200001];
void update(int i, int x)
{
	while (i <= n)
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

	int T; cin >> T;
	while (T--)
	{
		cin >> n;
		v.clear();
		fill(segTree, segTree + n + 1, 0);

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			v.push_back(a[i]);
		}

		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());

		ll ans = 0;
		for (int i = 0; i < n; i++)
		{
			a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
			int fr = getVal(a[i] - 1);
			int bk = getVal(n) - getVal(a[i]);
			ans += min(fr, bk);
			update(a[i], 1);
		}

		//cout << "ANS: ";
		cout << ans << '\n';
	}
}