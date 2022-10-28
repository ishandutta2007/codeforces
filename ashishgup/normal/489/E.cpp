#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 1005;

int n, l;
int x[N], b[N];
bool vis[N];
double cache[N];
double g[N][N], store[N][N];

double dp(int idx)
{
	if(idx == n)
		return 0;
	if(vis[idx])
		return cache[idx];
	vis[idx] = 1;
	double &ans = cache[idx];
	ans = 1e9;
	for(int i = idx + 1; i <= n; i++)
		ans = min(ans, g[idx][i] + dp(i));
	return ans;
}

void path(int idx)
{
	if(idx == n)
		return;
	double &ans = cache[idx];
	for(int i = idx + 1; i <= n; i++)
	{
		if(abs(g[idx][i] + dp(i) - ans) < 1e-9)
		{	
			cout << i << " ";
			return path(i);
		}
	}
}

bool check(double k, bool print)
{
	for(int i = 0; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			g[i][j] = store[i][j] - k * b[j];
	memset(vis, 0, sizeof(vis));
	double mx = dp(0);
	if(print)
		path(0);
	return mx <= 0;
}

void binsearch(double lo, double hi)
{
	for(int i = 1; i <= 64; i++)
	{
		double mid = (lo + hi) / 2;
		if(check(mid, 0))
			hi = mid;
		else
			lo = mid;
	}
	check(lo, 1);
}

int32_t main()
{
	IOS;	
	cin >> n >> l;
	for(int i = 1; i <= n; i++)
		cin >> x[i] >> b[i];
	for(int i = 0; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			store[i][j] = sqrtl(abs(x[j] - x[i] - l));
	binsearch(0, 1e9);

	return 0;
}