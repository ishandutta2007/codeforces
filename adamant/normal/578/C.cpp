#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define double long double

const int maxn = 3e6;

double a[maxn], pr[maxn];
int n;

double calc(double k)
{
	double mx = -1e15, mn = 1e15;
	double pmx = 0, pmn = 0;
	for(int i = 1; i <= n; i++)
	{
		double t = i * k + pr[i];
		pmx = max(pmx, t);
		pmn = min(pmn, t);
		mx = max(mx, t - pmn);
		mn = min(mn, t - pmx);
	}
	return max(fabs(mx), fabs(mn));
}

signed main()
{
	//freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
		cin >> a[i];
	pr[0] = 0;
	for(int i = 1; i <= n; i++)
		pr[i] = pr[i - 1] + a[i - 1];
	double l = -1e5, r = 1e5;
	double eps = 1e-13;
	while(r - l > eps)
	{
		double m1 = l + (r - l) / 2.1, m2 = r - (r - l) / 2.5;
		if(calc(m1) < calc(m2))
			r = m2;
		else
			l = m1;
	}
	cout << fixed << setprecision(12) << calc(l) << "\n";
    return 0;
}