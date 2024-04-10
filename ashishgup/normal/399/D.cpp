#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double
 
const int N = 2005;
 
int n, m;
set<int> rows, cols;
bool vis[N][N];
double cache[N][N];
 
double dp(int r, int c)
{
	if(r < 0 || c < 0)
		return 0;
	if(r == 0 && c == 0)
		return 0;
	double &ans = cache[r][c];
	if(vis[r][c])
		return ans;
	vis[r][c] = 1;
	ans = 0;
	double both = r * c;
	double rows = r * (n - c);
	double cols = (n - r) * c;
	double same = (n - r) * (n - c);
 
	double num = 0;
	num += both * dp(r - 1, c - 1);
	num += rows * dp(r - 1, c);
	num += cols * dp(r, c - 1);
	num /= (n * n);
	num += 1;
 
	double den = 1 - same / (n * n);
 
	ans = num / den;
	return ans;
}
 
int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int r, c;
		cin >> r >> c;
		rows.insert(r);
		cols.insert(c);
	}
	double ans = dp(n - rows.size(), n - cols.size());
	cout << fixed << setprecision(12) << ans;
	return 0;
}