#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N = 1e3 + 5;

struct data
{
	double x, y, t, p;

	bool operator <(data &other)
	{
		return t < other.t;
	}
};

int n;
data a[N];
double cache[N];
bool vis[N];

double dist(double x1, double y1, double x2, double y2)
{
	return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double dp(int idx)
{
	double &ans = cache[idx];
	if(vis[idx])
		return ans;
	vis[idx] = 1;
	ans = a[idx].p;
	for(int i = idx + 1; i <= n; i++)
	{
		double haveTime = a[i].t - a[idx].t;
		double travelTime = dist(a[i].x, a[i].y, a[idx].x, a[idx].y);
		if(travelTime <= haveTime)
			ans = max(ans, a[idx].p + dp(i));
	}
	return ans;
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].y >> a[i].t >> a[i].p;
	sort(a + 1, a + n + 1);
	double ans = 0;
	for(int i = 1; i <= n; i++)
		ans = max(ans, dp(i));
	cout << fixed << setprecision(12) << ans;
	return 0;
}