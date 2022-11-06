#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int isUsed[201];
vector <vector<int> > k;

vector <int> idx[201];
int cnt[201];
int tcnt[201];

bool isValid(vector <int>& res)
{
	if (res.size() < n) return false;

	int idx[201];
	for (int i = 0; i < n; i++)
		idx[res[i]] = i;

	for (auto& vec : k)
	{
		set <int> st;
		for (auto num : vec) st.insert(idx[num]);

		int fr = *st.begin();
		int bk = *prev(st.end());

		if (bk - fr + 1 != st.size()) return false;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		k.clear();
		memset(cnt, 0, sizeof cnt);

		cin >> n;
		for (int i = 1; i <= n; i++) idx[i].clear();

		for (int i = 0; i < n - 1; i++)
		{
			vector <int> tmp;
			int s; cin >> s;

			for (int j = 0; j < s; j++)
			{
				int x; cin >> x;
				tmp.push_back(x);
				idx[x].push_back(i);
				cnt[x]++;
			}

			k.push_back(tmp);
		}

		vector <int> ans;

		for (int fr = 1; fr <= n; fr++)
		{
			memset(isUsed, 0, sizeof isUsed);
			memcpy(tcnt, cnt, sizeof cnt);
			tcnt[fr]++;
			vector <int> tmpVec = { fr };
			k.push_back(tmpVec);
			idx[fr].push_back(n - 1);

			vector <int> res;
			for (int i = 0; i < n; i++)
			{
				int cnum = 0;
				for (int j = 1; j <= n; j++)
				{
					if (tcnt[j] == 1)
					{
						cnum = j;
						break;
					}
				}

				if (cnum == 0) break;
				if (cnum == 0) break;

				int ckidx = 0;
				res.push_back(cnum);
				for (auto kidx : idx[cnum])
				{
					if (isUsed[kidx]) continue;
					ckidx = kidx;
				}

				isUsed[ckidx] = 1;
				for (auto it : k[ckidx])
					tcnt[it]--;
			}

			if (isValid(res)) ans = res;

			k.pop_back();
			idx[fr].pop_back();
		}

		reverse(ans.begin(), ans.end());
		for (auto it : ans) cout << it << ' ';
		cout << '\n';
	}
}