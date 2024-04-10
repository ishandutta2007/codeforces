#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 3005;

int n, m, p, q;
int g0, x, y, z;
int g[N * N];
int a[N][N], b[N][N];

int32_t main()
{
	IOS;
	cin >> n >> m >> p >> q;
	cin >> g0 >> x >> y >> z;
	g[0] = g0;
	for(int i = 1; i <= n * m; i++)
		g[i] = (1LL * g[i - 1] * x + y) % z;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[i][j] = g[(i - 1) * m + j - 1];
	for(int i = 1; i <= n; i++)
	{
		deque<int> s;
		for(int j = 1; j <= q; j++)
		{
			while(s.size() && a[i][s.back()] > a[i][j])
				s.pop_back();
			s.push_back(j);
		}
		b[i][1] = a[i][s.front()];
		for(int j = q + 1; j <= m; j++)
		{
			while(s.size() && a[i][s.back()] > a[i][j])
				s.pop_back();
			s.push_back(j);
			while(s.front() <= j - q)
				s.pop_front();
			b[i][j - q + 1] = a[i][s.front()];
		}	
	}
	long long ans = 0;
	//n * (m - q + 1)
	for(int j = 1; j <= m - q + 1; j++)
	{
		deque<int> s;
		for(int i = 1; i <= p; i++)
		{
			while(s.size() && b[s.back()][j] > b[i][j])
				s.pop_back();
			s.push_back(i);
		}
		ans += b[s.front()][j];
		for(int i = p + 1; i <= n; i++)
		{
			while(s.size() && b[s.back()][j] > b[i][j])
				s.pop_back();
			s.push_back(i);
			while(s.front() <= i - p)
				s.pop_front();
			ans += b[s.front()][j];
		}
	}
	cout << ans;
	return 0;
}