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
const int N = 1e6 + 9, mod = 1e9 + 7;
const double eps = 0.00000001;
int n;
double p, res, p0, p1, p2, p3, s;
signed main()
{
	n = read();
	scanf("%lf", &p);
	for (int i = 0; i <= n; i++)
	{
		res = 0;
		s = n * (n - 1) * (n - 2) / 6;
		p0 = (n - i) * (n - i - 1) * (n - i - 2) / 6.0 * 1.0 / s;
		p1 = i * (n - i) * (n - i - 1) / 2.0 / s;
		p2 = i * (i - 1) * (n - i) / 2.0 / s;
		p3 = i * (i - 1) * (i - 2) / 6.0 / s;
		res = p3 + p2 + p1 / 2.0;
		if(res - p >= -eps) 
		{
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}