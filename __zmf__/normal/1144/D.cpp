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
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar ();
	return sum * nega;
}
const int N = 2e6 + 9;
int cnt[N], n, a[N], val;
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read(), ++cnt[a[i]];
	for (int i = 1; i <= 200000; i++)
		if(cnt[val] <= cnt[i]) val = i;
	cout << n - cnt[val] << endl;
	for (int i = 2; i <= n; i++)
		if(a[i - 1] == val)
		{
			if(a[i] > a[i - 1]) printf("2 %lld %lld\n", i, i - 1);
			else if(a[i] < a[i - 1]) printf("1 %lld %lld\n", i, i - 1);
			a[i] = a[i - 1];
		}
	for (int i = n - 1; i >= 1; i--)
		if(a[i + 1] == val)
		{
			if(a[i] > a[i + 1]) printf("2 %lld %lld\n", i, i + 1);
			else if(a[i] < a[i + 1]) printf("1 %lld %lld\n", i, i + 1);
			a[i] = a[i + 1];
		}
	return 0;
}