#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll Inf = (ll) 1e18 + 9;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	vector<ll> len(n);
	for (ll &x : len)
		cin >> x;

	string type;
	cin >> type;

	map<ll, ll> mp;
	ll t = 0;
	ll mn = 0;

	for (int i = n - 1; i >= 0; --i) {
		t += len[i];
		if (type[i] == 'L')
			mn += len[i];
		else {
			const ll F = type[i] == 'W' ? 3 : type[i] == 'G' ? 5 : 0;
			assert(F != 0);

			map<ll, ll> mp2 = { { (F - 1) / 2, 2 * len[i] }, { F, Inf } };

			{
				ll sta = -len[i];

				while (sta < mn) {
					assert(!mp2.empty());
					auto it = mp2.begin();
					assert(it->first);

					const ll q = min(it->second, mn - sta);
					it->second -= q;
					sta += q;
					if (mp[it->first] < Inf)
						mp[it->first] += q;
					t += it->first * q;

					if (!it->second)
						mp2.erase(it);
				}
			}

			assert(!mp2.empty());

			while (!mp.empty() && mp2.begin()->first < mp.rbegin()->first) {

				auto it = --mp.end();
				auto it2 = mp2.begin();
				assert(it->first && it2->first);

				const ll q = min(it->second, it2->second);

				it->second -= q;
				it2->second -= q;

				assert(it->first != it2->first);

				if (mp[it2->first] < Inf)
					mp[it2->first] += q;

				t += (it2->first - it->first) * q;

				if (!it->second)
					mp.erase(it);
				if (!it2->second)
					mp2.erase(it2);

				assert(!mp2.empty());

			}

			mn = 0;
		}
	}

	cout << t;
	return 0;
}