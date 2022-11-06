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
const int N = 1e5 + 9;
int T, n, sum;
struct point
{
	int x, val;
}a[N];
inline bool check(int x)
{
	for (int i = 2; i * i <= x; i++)
		if(x % i == 0) return 0;
	return 1;
}
signed main() 
{	
	T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		n = read(); sum = 0;
		for (int i = 1; i <= n; i++) a[i].x = i, a[i].val = read(), sum += a[i].val;
		if(!check(sum))
		{
			cout << n << endl;
			for (int i = 1; i <= n; i++) printf("%lld ", i);
			puts("");
			continue;
		}
		for (int i = 1; i <= n; i++)
			if(!(check(sum - a[i].val)))
			{
				cout << n - 1 << endl;
				for (int j = 1; j <= n; j++)
					if(j != i) printf("%lld ", j);
				puts("");
				break;
			}
	}
	return 0;
}