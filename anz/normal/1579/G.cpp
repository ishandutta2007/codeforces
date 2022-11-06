#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int a[10001];

void insert(set <pii>& st, pii x)
{
	if (x.first > x.second) swap(x.first, x.second);
	if (x.first + x.second > 2000) return;

	auto it = st.lower_bound(x);
	if (it != st.begin())
	{
		auto p = *prev(it);
		if (p.second <= x.second) return;
	}

	while (true)
	{
		auto it = st.lower_bound(x);
		if (it == st.end()) break;
		if (it->second >= x.second) st.erase(it);
		else break;
	}

	st.insert(x);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];

		vector <pii> v;
		v.push_back({ 0,0 });
		for (int i = 0; i < n; i++)
		{
			vector <pii> nv;
			for (auto it : v)
			{
				int l = it.first, r = it.second;

				int nl = max(0, l - a[i]);
				int nr = r + a[i];
				if (nl > nr) swap(nl, nr);

				if (nl + nr <= 2000)
					nv.push_back({ nl, nr });

				nl = l + a[i];
				nr = max(0, r - a[i]);
				if (nl > nr) swap(nl, nr);

				if (nl + nr <= 2000)
					nv.push_back({ nl, nr });
			}

			sort(nv.begin(), nv.end());
			v.clear();
			for (auto it : nv)
			{
				if (!v.empty() && v.back().second <= it.second) continue;
				v.push_back(it);
			}
		}

		int ans = 1e9;
		for (auto it : v) ans = min(ans, it.first + it.second);

		//cout << "ANS: ";
		cout << ans << '\n';
	}
}