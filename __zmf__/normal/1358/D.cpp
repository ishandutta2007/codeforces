/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum = 0, nega = 1;
	char ch = getchar();
	while (ch > '9'||ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 2e6 + 9;
int n, x, sum[N], ans[N], a[N], res;
signed main()
{
	n = read(), x = read();
	for (int i = 1; i <= n; i++) a[i] = read(), sum[i] = sum[i - 1] + a[i], ans[i] = ans[i - 1] + (a[i] * (a[i] + 1) / 2); 
	for (int i = n + 1; i <= 2 * n; i++) a[i] = a[i - n], sum[i] = sum[i - 1] + a[i], ans[i] = ans[i - 1] + (a[i] * (a[i] + 1) / 2);
	n *= 2;
	for (int i = 1; i <= n; i++)
	{
		if(sum[i] < x) continue;
		int pos = lower_bound(sum, sum + n + 1, sum[i] - x) - sum + 1;
		//cout << i << " " << pos << endl;
		int val = ans[i] - ans[pos - 1], rest = x - (sum[i] - sum[pos - 1]);
		//cout << val << endl;
		val += (a[pos - 1] + a[pos - 1] - rest + 1) * rest / 2;
		//cout << val << endl;
		res = max(res, val);
	}
	cout << res << endl;
	return 0;
}