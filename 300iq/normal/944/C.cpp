#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;

vector <int> g[N];

int main()
{
#ifdef ONPC
	freopen("a.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector <int> p(n);
	vector <int> ret(n, 1);
	for (int i = 1; i < n; i++)
	{
		cin >> p[i];
		p[i]--;
		g[p[i]].push_back(i);
	}
	vector <int> q;
	q.push_back(0);
	int ans = 0;
	while (!q.empty())
	{
		int s = 0;
		for (int v : q)
		{
			s++;
		}
		ans += s % 2;
		vector <int> nq;
		for (int v : q)
		{
			for (int to : g[v])
			{
				nq.push_back(to);
			}
		}
		q = nq;
	}
	cout << ans << '\n';
}