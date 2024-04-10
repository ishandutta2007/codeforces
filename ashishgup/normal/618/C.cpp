#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double
#define x first
#define y second
 
const int N = 1e5 + 5;
 
int n;
pair<pair<int, int>, int> a[N];
 
double get(double x1, double y1, double x2, double y2)
{
	return sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
 
const double eps = 1e-12;
 
int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i].x.x >> a[i].x.y; 
		a[i].y = i;
	}
	sort(a + 1, a + n + 1);
	double cosVal = 2, mx = 1e9;
	int idx = 3;
	double a12 = get(a[1].x.x, a[1].x.y, a[2].x.x, a[2].x.y);
	for(int i = 3; i <= n; i++)
	{
		double a1i = get(a[1].x.x, a[1].x.y, a[i].x.x, a[i].x.y);
		double a2i = get(a[i].x.x, a[i].x.y, a[2].x.x, a[2].x.y);
		double num = a1i * a1i + a2i * a2i - a12 * a12;
		double den = 2 * a1i * a2i;
		double val = num / den;
		if(val < cosVal)
		{
			cosVal = val;
			idx = i;
			mx = a1i;
		}
	}
	cout << a[1].y << " " << a[2].y << " " << a[idx].y << endl;
	return 0;
}