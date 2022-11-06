#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
vector <int> a[11];

set <vector <int> > st;
vector <vector <int> > ban;

int vn = 0;
vector <int> pool[5000001];
pii insert(vector <int> v)
{
	if (st.find(v) != st.end()) return { -1, -1 };

	st.insert(v);
	int sum = 0;
	for (int i = 0; i < v.size(); i++) sum += a[i][v[i]];

	pool[vn] = v;
	return { sum, vn++ };
}

bool find(vector <int> v)
{
	return binary_search(ban.begin(), ban.end(), v);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int c; cin >> c;
		for (int j = 0; j < c; j++)
		{
			int x; cin >> x;
			a[i].push_back(x);
		}
	}

	cin >> m;
	while (m--)
	{
		ban.emplace_back();
		for (int i = 0; i < n; i++)
		{
			int b; cin >> b;
			ban.back().push_back(b - 1);
		}
	}

	sort(ban.begin(), ban.end());

	priority_queue <pii> pq;
	vector <int> vec;
	for (int i = 0; i < n; i++) vec.push_back(a[i].size() - 1);
	pq.push(insert(vec));

	while (true)
	{
		auto it = pq.top(); pq.pop();
		int sum = it.first, num = it.second;
		if (!find(pool[num]))
		{
			for (int i = 0; i < n; i++) cout << pool[num][i] + 1 << ' ';
			break;
		}

		vector <int> nv = pool[num];
		for (int i = 0; i < n; i++)
		{
			if (nv[i] == 0) continue;
			--nv[i];
			auto it = insert(nv);
			++nv[i];
			if (it.first == -1) continue;

			pq.push(it);
		}
	}
}