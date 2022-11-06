#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const int INF = numeric_limits<int>::max();
int n, m;
int d[10001];
int dist[10001][1001];
int g, r;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(dist, -1, sizeof dist);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> d[i];
	cin >> g >> r;

	sort(d, d + m);

	deque <pii> dq;
	dist[0][0] = 0;
	dq.push_back({ 0,0 });

	while (!dq.empty())
	{
		int idx = dq.front().first;
		int tm = dq.front().second;
		dq.pop_front();

		//cout << "IDX, TM: " << idx << ' ' << tm << "\n";
		if (tm < 0)
		{
			int stop_here = 0;
		}

		int r_tm = g - tm;
		
		int nidx = idx + 1;
		int sub = d[nidx] - d[idx];
		int ntm = (tm + sub) % g;

		if (idx < m - 1)
		{
			if (sub <= r_tm && dist[nidx][ntm] == -1)
			{
				if (ntm == 0)
				{
					dist[nidx][ntm] = dist[idx][tm] + 1;
					dq.push_back({ nidx, ntm });
				}
				else
				{
					dist[nidx][ntm] = dist[idx][tm];
					dq.push_front({ nidx, ntm });
				}
			}
		}		

		if (idx > 0)
		{
			nidx = idx - 1;
			sub = d[idx] - d[nidx];
			ntm = (tm + sub) % g;

			if (sub <= r_tm && dist[nidx][ntm] == -1)
			{
				if (ntm == 0)
				{
					dist[nidx][ntm] = dist[idx][tm] + 1;
					dq.push_back({ nidx, ntm });
				}
				else
				{
					dist[nidx][ntm] = dist[idx][tm];
					dq.push_front({ nidx, ntm });
				}
			}
		}
	}

	int ans = INF;
	for (int i = 0; i < g; i++)
	{
		if (dist[m - 1][i] != -1)
		{
			int res = dist[m - 1][i] * (r + g) + i;
			if (i == 0) res -= r;
			ans = min(ans, res);
		}
	}

	if (ans == INF) ans = -1;
	cout << ans;
}