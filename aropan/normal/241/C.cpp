#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const int MAXN = 103;

int hl, hr, n;
int a[MAXN], b[MAXN];
int v[MAXN];
char t[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	scanf("%d %d %d", &hl, &hr, &n);
	for (int i = 0; i < n; i++)
		scanf("%d %c %d %d\n", &v[i], &t[i], &a[i], &b[i]);

	int ans = 0;
	for (int i = -n - 1; i <= n + 1; i++)
	{
		if (i == 0) continue;
		int
			x1 = 0, y1 = hl,
			x2 = 100000, y2 = 100 * i + (((abs(i)) & 1)? 100 - hr : hr);
//		cout << i << " " << y2 << endl;
		long long
			A = y2 - y1,
			B = x1 - x2,
			C = -(A * x1 + B * y1);
/*			
		cout << A << " " << B << " " << C  << endl;
//*/
		int res = 0;
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			int c = 0;
			for (int k = -n - 1; k <= n + 1; k++)
			{
				long long Y = 100 * k;
				if ((abs(k) & 1) ^ (t[j] == 'T')) continue;
				long long L = a[j] * A, X = -B * Y - C, R = b[j] * A;
				if (L > R) swap(L, R);
				if (L <= X && X <= R)
				{
					c++;
					res += v[j];
				}
			}
			cnt += c;
			if (c > 1)
			{
				cnt = 0;
				break;
			}
		}
		if (cnt == abs(i))
		{
//			cout << i << " " << res << endl;
			ans = max(ans, res);
		}
	}
	cout << ans << endl;

	return 0;
}