#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, sum = 0;
double a[N];
int b[N], c[N], ans[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i] = floorl(a[i]);
		sum += b[i];
		c[i] = ceill(a[i]);
	}
	int reqd = 0 - sum;
	for(int i = 1; i <= n; i++)
	{
		ans[i] = b[i];
		if(reqd > 0 && c[i] > b[i])
		{
			reqd--;
			ans[i] = c[i];
		}
	}
	for(int i = 1; i <= n; i++)
		cout << ans[i] << endl;
	return 0;
}