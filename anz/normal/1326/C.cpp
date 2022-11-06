#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll MOD = 998244353;
ll n, k;
ll p[200001];
ll idx[200001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		idx[p[i]] = i;
	}

	vector <int> v;
	ll ans = 0;
	for (int i = 0; i < k; i++)
	{
		ans += n - i;
		v.push_back(idx[n - i]);
	}

	ll sum = 1;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size() - 1; i++)
	{
		sum *= (v[i + 1] - v[i]);
		sum %= MOD;
	}
	
	cout << ans << ' ' << sum;
}