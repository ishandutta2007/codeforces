#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bitset>
#include <list>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll gcd(ll a, ll b) { for (; b; a %= b, swap(a, b)); return a; }

int n, m;
vector <vector <int> > mp, dis, tmp;

int dx[8] = { -1,-1,-1,0,1,1,1,0 };
int dy[8] = { -1,0,1,1,1,0,-1,-1 };
int mcnt = 0;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	mp.resize(n), dis.resize(n), tmp.resize(n);
	for (int i = 0; i < n; i++)
		mp[i].resize(m), dis[i].resize(m), tmp[i].resize(m);

	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		for (int j = 0; j < m; j++)
		{
			if (s[j] == 'X') mp[i][j] = 1, mcnt++;
		}
	}

	queue <pii> q;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
	{
		if (mp[i][j] == 0) continue;
		if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
		{
			dis[i][j] = 1;
			q.push({ i,j });
			continue;
		}

		bool flag = false;
		for (int k = 0; k < 8; k++)
		{
			if (mp[i + dx[k]][j + dy[k]] == 0)
			{
				flag = true;
				break;
			}
		}

		if (flag)
		{
			dis[i][j] = 1;
			q.push({ i,j });
		}
	}

	while (!q.empty())
	{
		bool flag = false;
		int cx = q.front().first, cy = q.front().second;
		int d = dis[cx][cy];
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = cx + dx[i], ny = cy + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (mp[nx][ny] == 0) continue;
			if (dis[nx][ny] != 0) continue;

			dis[nx][ny] = d + 1;
			q.push({ nx,ny });
		}
	}

	int l = 0, r = n * m + 1;
	while (l+1 < r)
	{
		queue <pii> q;
		int mid = (l + r) / 2;
		for (int i = 0; i < n; i++)
		{
			tmp[i].clear();
			tmp[i].resize(m);
		}

		bool flag = true;
		int cnt = 0;
		int scnt = 0;
		int tcnt = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		{
			if (dis[i][j] > mid)
			{
				q.push({ i,j }), cnt++, scnt++;
				tmp[i][j] = 1;
			}

		}

		for (int i = 0; i < mid; i++)
		{
			if (scnt == 0)
			{
				flag = false;
				break;
			}
			for (int j = 0; j < scnt; j++)
			{
				int cx = q.front().first, cy = q.front().second; q.pop();
				for (int k = 0; k < 8; k++)
				{
					int nx = cx + dx[k], ny = cy + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					{
						flag = false;
						break;
					}
					if (tmp[nx][ny]) continue;

					if (mp[nx][ny] == 0)
					{
						flag = false;
						break;
					}

					tmp[nx][ny] = 1;
					q.push({ nx,ny });
					tcnt++;
				}

				if (!flag) break;
			}

			scnt = tcnt;
			cnt += scnt;
			tcnt = 0;
			if (!flag) break;
		}

		if (cnt < mcnt) flag = false;

		if (flag)
		{
			l = mid;
		}
		else
		{
			r = mid;
		}
	}

	cout << l << '\n';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dis[i][j] > l) cout << 'X';
			else cout << '.';
		}
		cout << '\n';
	}
}