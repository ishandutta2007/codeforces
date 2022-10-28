#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = (1 << 22) + 5;

int n;
int a[N], f[N], g[N];

int32_t main()
{
	IOS;
	memset(g, -1, sizeof(g));
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		f[a[i]]++;
		g[a[i]] = a[i];
	}
	for(int i = 0; i < 22; i++)	
	{
		for(int mask = 0; mask < (1 << 22); mask++)
		{
			if(mask >> i & 1)
			{
				f[mask] += f[mask ^ (1 << i)];
				g[mask] = max(g[mask], g[mask ^ (1 << i)]);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++)
		cout << g[((1 << 22) - 1) ^ a[i]] << " ";
	cout << endl;
	return 0;
}