#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 5005;

int n;
int a[N], f[N], curf[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		memset(curf, 0, sizeof(curf));
		int best = 0;
		for(int j = i; j <= n; j++)
		{
			curf[a[j]]++;
			if(curf[a[j]] > curf[best] || (curf[a[j]] == curf[best] && a[j] < best))
				best = a[j];
			f[best]++;
		}
	}
	for(int i = 1; i <= n; i++)
		cout << f[i] << " ";
	return 0;
}