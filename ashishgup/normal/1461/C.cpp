#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int n, m;
int a[N], r[N];
double p[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			p[i] = 1;
		}
		for(int i = 1; i <= m; i++)
		{
			int idx;
			cin >> idx;
			double prob;
			cin >> prob;
			p[idx] *= (1 - prob);
		}
		int idx = -1;
		for(int i = n; i >= 1; i--)
		{
			if(a[i] != i)
			{
				idx = i;
				break;
			}
		}
		double ans = 0;
		if(idx == -1)
			ans = 1;
		else
		{
			ans = 1;
			for(int i = idx; i <= n; i++)
				ans *= p[i];
			ans = 1 - ans;
		}
		cout << fixed << setprecision(12) << ans << endl;
	}
	return 0;
}