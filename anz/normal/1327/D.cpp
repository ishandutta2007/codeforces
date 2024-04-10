#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n;
int p[200001];
int c[200001];

int cache[200001];
vector <int> stk;

void DFS(int s)
{
	cache[s] = 1;
	stk.push_back(c[s]);
	if (cache[p[s]]) return;
	DFS(p[s]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> p[i];
		for (int i = 1; i <= n; i++) cin >> c[i];
		
		for (int i = 1; i <= n; i++) cache[i] = 0;

		int ans = 987654321;
		for (int i = 1; i <= n; i++)
		{
			if (cache[i]) continue;

			stk.clear();
			DFS(i);

			int mod = stk.size();
			vector <int> div;
			for (int k = 1; k * k <= mod; k++)
			{
				if (mod % k == 0)
				{
					div.push_back(k);
					if (k * k != stk.size()) div.push_back(mod / k);
				}
			}

			for (auto k : div)
			{
				for (int i = 0; i < k; i++)
				{
					bool flag = true;
					for (int j = 0; j < mod / k; j++)
					{
						if (stk[(j * k + i) % mod] != stk[((j + 1) * k + i) % mod])
						{
							flag = false;
							break;
						}
					}

					if (flag)
					{
						ans = min(ans, k);
						break;
					}
				}
			}
		}

		cout << ans << '\n';
	}
}