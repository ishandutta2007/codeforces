#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int N = 200001;

int n;
int l[N], r[N];

int st[N];
int sum[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;

		vector <pair<int, pii> > v;

		for (int i = 0; i < n; i++)
		{
			cin >> l[i] >> r[i];
			v.push_back({ l[i],{0, i} });
			v.push_back({ r[i],{1, i} });
		}

		sort(v.begin(), v.end());

		int cnt = 0;
		int cur = 0;
		for (auto it : v)
		{
			int num = it.first;
			int type = it.second.first;
			int idx = it.second.second;

			if (type == 0)
			{
				cnt++;
				cur++;

				st[idx] = cnt;
				sum[idx] = cur;
			}
			else
			{
				cur--;
				sum[idx] += cnt - st[idx];
			}
		}

		int res = *max_element(sum, sum + n);

		//cout << "ANS:";
		cout << n - res << '\n';
	}
}