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
int n, m, k;
signed main()
{
	n = read(), m = read(), k = read();
	if((n * m * 2) % k != 0)
	{
		puts("NO");
		return 0;
	}
	int d1 = __gcd(n, k); n /= d1, k /= d1;
	int d2 = __gcd(m, k); m /= d2, k /= d2;
	if(k == 1)
	{
		if(d1 >= 2) n *= 2;
		else m *= 2;
	}
	puts("YES");
	cout << "0 0" << endl;
	printf("%lld 0\n0 %lld\n", n, m);
	return 0;
}
//qwq