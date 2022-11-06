#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 200001;

int n;
ll a[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	set <pll> st;

	int ans = 0;
	ll sum = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
		st.insert({ a[i], i });

		ans++;
		if (sum < 0)
		{
			ans--;
			auto it = st.begin();
			sum -= it->first;
			st.erase(it);
		}
	}

	cout << ans;
}