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
	while (ch <= '9'&&ch >= '0') sum = sum * 10 + ch - '0', ch = getchar ();
	return sum * nega;
}
const int N = 2e5 + 9;
int n, cnt1, cnt2;
int a[N], used[N], incr[N], decr[N];
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		a[i] = read();
		used[a[i]]++;
		if(used[a[i]] == 3)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	incr[0] = decr[0] = -1;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if(incr[cnt1] < a[i]) incr[++cnt1] = a[i];
		else decr[++cnt2] = a[i]; 
	}
	cout << cnt1 << endl;
	for (int i = 1; i <= cnt1; i++) printf("%d ", incr[i]);
	puts("");
	cout << cnt2 << endl;
	for (int i = cnt2; i >= 1; i--) printf("%d ", decr[i]);
	return 0;
}