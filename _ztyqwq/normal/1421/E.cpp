#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int INF = 50000000000000000ll;
int a[300001];
int f[300001][5][5]; // 0: ok 1: limit
inline void Max(int &a, int b)
{
	if(a < b)
		a = b;
}
signed main()
{
	// freopen("E.txt", "r", stdin);
	// freopen("E-true.txt", "w", stdout);
	int n;
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	if(n == 1)
	{
		printf("%lld\n", a[1]);
		return 0;
	}
	f[0][0][0] = f[0][1][0] = f[0][1][1] = f[0][2][0] = f[0][2][1] = -INF;
	f[0][0][1] = 0;
	for(int i = 1; i <= n; i++)
	{
		f[i][0][0] = f[i][0][1]  = f[i][1][0] = f[i][1][1] = f[i][2][0] = f[i][2][1] = -INF;
		for(int j = 0; j < 3; j++)
		{
			if(i & 1) // CHOOSE +
			{
				Max(f[i][(j + 1) % 3][1], f[i - 1][j][1] + a[i]);
				Max(f[i][(j + 1) % 3][0], f[i - 1][j][0] + a[i]);
			}
			else
			{
				Max(f[i][(j + 1) % 3][0], f[i - 1][j][1] + a[i]);
				Max(f[i][(j + 1) % 3][0], f[i - 1][j][0] + a[i]);
			}
			
			if(!(i & 1)) // CHOOSE -
			{
				Max(f[i][j][1], f[i - 1][j][1] - a[i]);
				Max(f[i][j][0], f[i - 1][j][0] - a[i]);
			}
			else
			{
				Max(f[i][j][0], f[i - 1][j][1] - a[i]);
				Max(f[i][j][0], f[i - 1][j][0] - a[i]);
			}
		}
		// cout << f[i][0][0] << ' ' << f[i][0][1] << ' ' << f[i][1][0] << ' ' << f[i][1][1] << ' ' << f[i][2][0] << ' ' << f[i][2][1] << endl;
	} 
	int a3 = 2 - n % 3;
	printf("%lld\n", f[n][a3][0]);
	return 0;
}