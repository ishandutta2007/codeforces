#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 5e5 + 5;
const int B = sqrt(N) + 5;

int n = 5e5;
int a[N];
int sum[B][B];

void add(int x)
{
	for(int i = 1; i < B; i++)
		sum[x % i][i] += a[x];
}

void remove(int x)
{	
	for(int i = 1; i < B; i++)
		sum[x % i][i] -= a[x];
}

int32_t main()
{
	IOS;
	int q;
	cin >> q;
	while(q--)
	{
		int t, x, y;
		cin >> t >> x >> y;
		if(t == 1)
		{
			remove(x);
			a[x] += y;
			add(x);
		}
		else
		{
			if(x < B)
				cout << sum[y][x] << endl;
			else
			{
				int ans = 0;
				for(int i = y; i <= n; i += x)
					ans += a[i];
				cout << ans << endl;
			}
		}
	}
	return 0;
}