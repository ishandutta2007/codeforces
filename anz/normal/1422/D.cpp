#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

const ll INF = 1e18;

ll n, m;
ll sx, sy, fx, fy;
vector <ll> vx, vy;
int getIdx(vector <ll>& vec, ll val)
{
	return lower_bound(vec.begin(), vec.end(), val) - vec.begin();
}

pll mv[100001];

vector <int> mx[100001], my[100001];
ll dx[100001], dy[100001];

bool compX(int a, int b)
{
	return mv[a].first < mv[b].first;
}

bool compY(int a, int b)
{
	return mv[a].second < mv[b].second;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	fill(dx, dx + 100001, INF);
	fill(dy, dy + 100001, INF);

	cin >> n >> m;
	cin >> sx >> sy >> fx >> fy;

	for (int i = 0; i < m; i++)
	{
		ll x, y; cin >> x >> y;
		mv[i] = { x,y };
		vx.push_back(x);
		vy.push_back(y);
	}

	sort(vx.begin(), vx.end());
	vx.erase(unique(vx.begin(), vx.end()), vx.end());
	sort(vy.begin(), vy.end());
	vy.erase(unique(vy.begin(), vy.end()), vy.end());

	for (int i = 0; i < m; i++)
	{
		mv[i].first = getIdx(vx, mv[i].first);
		mv[i].second = getIdx(vy, mv[i].second);

		mx[mv[i].first].push_back(i);
		my[mv[i].second].push_back(i);
	}

	//for (int i = 0; i < vx.size(); i++)
	//{
	//	sort(mx[i].begin(), mx[i].end(), compY);
	//}

	//for (int i = 0; i < vy.size(); i++)
	//{
	//	sort(my[i].begin(), my[i].end(), compX);
	//}

	priority_queue<pair<ll, pii>, vector<pair<ll, pii>>, greater<pair<ll, pii>> > pq;

	auto it = lower_bound(vx.begin(), vx.end(), sx);
	if (it != vx.end())
	{
		int idx = it - vx.begin();
		dx[idx] = *it - sx;
		pq.push({ dx[idx], {idx, 0} });
	}

	if (it != vx.begin())
	{
		it = prev(it);
		int idx = it - vx.begin();
		dx[idx] = sx - *it;
		pq.push({ dx[idx], {idx, 0} });
	}

	it = lower_bound(vy.begin(), vy.end(), sy);
	if (it != vy.end())
	{
		int idx = it - vy.begin();
		dy[idx] = *it - sy;
		pq.push({ dy[idx], {idx, 1} });
	}

	if (it != vy.begin())
	{
		it = prev(it);
		int idx = it - vy.begin();
		dy[idx] = sy - *it;
		pq.push({ dy[idx], {idx, 1} });
	}

	while (!pq.empty())
	{
		auto it = pq.top(); pq.pop();
		ll cd = it.first;
		int idx = it.second.first, type = it.second.second;

		if (type == 0)
		{
			for (int ni : mx[idx])
			{
				int ny = mv[ni].second;
				if (dy[ny] > cd)
				{
					dy[ny] = cd;
					pq.push({ dy[ny], {ny, 1} });
				}
			}

			if (idx != vx.size() - 1)
			{
				if (dx[idx + 1] > cd + vx[idx + 1] - vx[idx])
				{
					dx[idx + 1] = cd + vx[idx + 1] - vx[idx];
					pq.push({ dx[idx + 1], {idx + 1, 0} });
				}
			}

			if (idx != 0)
			{
				if (dx[idx - 1] > cd + vx[idx] - vx[idx - 1])
				{
					dx[idx - 1] = cd + vx[idx] - vx[idx - 1];
					pq.push({ dx[idx - 1], {idx - 1, 0} });
				}

			}
		}
		else
		{
			for (int ni : my[idx])
			{
				int nx = mv[ni].first;
				if (dx[nx] > cd)
				{
					dx[nx] = cd;
					pq.push({ dx[nx], {nx, 0} });
				}
			}

			if (idx != vy.size() - 1)
			{
				if (dy[idx + 1] > cd + vy[idx + 1] - vy[idx])
				{
					dy[idx + 1] = cd + vy[idx + 1] - vy[idx];
					pq.push({ dy[idx + 1], {idx + 1, 1} });
				}
			}

			if (idx != 0)
			{
				if (dy[idx - 1] > cd + vy[idx] - vy[idx - 1])
				{
					dy[idx - 1] = cd + vy[idx] - vy[idx - 1];
					pq.push({ dy[idx - 1], {idx - 1, 1} });
				}
			}
		}
	}

	ll ans = llabs(sx - fx) + llabs(sy - fy);

	for (int i = 0; i < m; i++)
	{
		ll d = min(dx[mv[i].first], dy[mv[i].second]);
		d += llabs(fx - vx[mv[i].first]) + llabs(fy - vy[mv[i].second]);

		ans = min(ans, d);
	}

	cout << ans;
}