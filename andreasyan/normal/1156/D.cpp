#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define m_p make_pair
const int N = 200005;

int n;
vector<pair<int, int> > a[N];

long long dp[N][2];

void dfs(int x, int p)
{
	for (int i = 0; i < a[x].size(); ++i)
	{
		int h = a[x][i].first;
		int z = a[x][i].second;
		if (h == p)
			continue;
		dfs(h, x);
		if (z == 0)
		{
			dp[x][0] += dp[h][0];
			dp[x][0]++;
		}
		else
		{
			dp[x][1] += dp[h][1];
			dp[x][1]++;
		}
	}
}

long long ans, yans1, yans0;
void dfs1(int x, int p, long long p0, long long p1)
{
	ans += (dp[x][0] + p0 + 1) * (dp[x][1] + p1 + 1);
	ans--;
	yans0 += (dp[x][0] + p0);
	yans1 += (dp[x][1] + p1);
	for (int i = 0; i < a[x].size(); ++i)
	{
		int h = a[x][i].first;
		int z = a[x][i].second;
		if (h == p)
			continue;
		if (z == 0)
		{
			dfs1(h, x, p0 + dp[x][0] - dp[h][0], 0);
		}
		else
		{
			dfs1(h, x, 0, p1 + dp[x][1] - dp[h][1] );
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		int x, y, z;
		cin >> x >> y >> z;
		a[x].push_back(m_p(y, z));
		a[y].push_back(m_p(x, z));
	}
	dfs(1, -1);
	dfs1(1, -1, 0, 0);
	yans1 /= 2;
	yans0 /= 2;
	//ans += yans1;
	//ans += yans0;
	cout << ans << endl;
	return 0;
}