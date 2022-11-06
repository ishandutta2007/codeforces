#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
ll ans[1001];

int bt[1000];
vector <int> query[13];
ll res[13];

ll getVal(vector <int> v)
{
	if (v.empty()) return 0;

	cout << "? " << v.size();
	for (int i : v) cout << ' ' << i;
	cout << endl;

	ll res; cin >> res;
	return res;
}

int main()
{
	cin >> n;

	int cnt = 0;
	for (int i = 0; i < (1 << 13) && cnt < n; i++)
	{
		int bc = 0;
		for (int j = 0; j < 13; j++)
			if (i & (1 << j)) bc++;
		if (bc != 6) continue;

		bt[cnt++] = i;
		for (int j = 0; j < 13; j++)
			if (!(i & (1 << j))) query[j].push_back(cnt);
	}

	for (int i = 0; i < 13; i++) res[i] = getVal(query[i]);

	cout << "!";
	for (int i = 0; i < n; i++)
	{
		ll ans = 0;

		for (int j = 0; j < 13; j++)
			if (bt[i] & (1 << j)) ans |= res[j];
		
		cout << ' ' << ans;
	}
	cout << endl;
}