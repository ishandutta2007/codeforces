#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 100010;

int n, x, y;
int b[N];
vector <int> cnt[N];

bool cmp(int a, int b)
{
	return cnt[a].size() > cnt[b].size();
}

struct ASDF
{
	int x, idx;
	bool operator <(ASDF t) const
	{
		if (cnt[x].size() != cnt[t.x].size())
			return cnt[x].size() > cnt[t.x].size();
		return x < t.x;
	}
};

int ans[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n >> x >> y;
		for (int i = 1; i <= n + 1; i++) cnt[i].clear();
		for (int i = 0; i < n; i++) ans[i] = -1;

		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
			cnt[b[i]].push_back(i);
		}

		int notUsed = -1;
		vector <int> tmp;
		for (int i = 1; i <= n + 1; i++)
		{
			if (cnt[i].size() == 0) notUsed = i;
			tmp.push_back(i);
		}

		sort(tmp.begin(), tmp.end(), cmp);

		int rm = x;

		for (int i = 0; i < tmp.size() - 1 && rm > 0; i++)
		{
			while (cnt[tmp[i]].size() != cnt[tmp[i + 1]].size() && rm > 0)
			{
				for (int j = 0; j <= i && rm > 0; j++)
				{
					int num = tmp[j];
					int idx = cnt[num].back();

					ans[idx] = num;
					rm--;

					cnt[num].pop_back();
				}
			}
		}

		vector <ASDF> vec;

		for (int i = 1; i <= n + 1; i++)
		{
			for (int idx : cnt[i])
			{
				vec.push_back({ i, idx });
			}
		}

		sort(vec.begin(), vec.end());
		multiset <ASDF> st(vec.begin(), vec.end());

		rm = y - x;
		for (auto it : vec)
		{
			int num = it.x;
			int idx = it.idx;

			if (st.empty()) break;

			auto nxt = st.upper_bound(it);
			if (nxt == st.end())
			{
				nxt = st.begin();
				if (num == nxt->x) continue;
			}

			int n2 = nxt->x;
			int i2 = nxt->idx;

			if (rm == 0) break;
			rm--;

			ans[idx] = n2;
			if (ans[i2] == -1) ans[i2] = notUsed;

			st.erase(nxt);
		}

		if (rm > 0)
		{
			cout << "NO\n";
			continue;
		}

		for (int i = 0; i < n; i++) if (ans[i] == -1) ans[i] = notUsed;

		cout << "YES\n";
		for (int i = 0; i < n; i++) cout << ans[i] << ' ';
		cout << '\n';
	}
}