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
const int N = 3e5 + 9;
int n;
int a[N], now1, now2, ans;
inline int lowbit(int x)
{
	return x & (-x);
}
inline int get(int x)
{
	int now = x, cnt = 0;
	while(x)
	{
		x -= lowbit(x); cnt++;
	}
	return cnt;
}
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++) a[i] = get(a[i]);
	int pp = 0;
	now2 = 1;
	for (int i = 1; i <= n; i++)
	{
		pp += a[i];
		if(pp & 1) ans += now1, now1++;
		else ans += now2, now2++;
	}
	for (int i = 1; i <= n; i++)
	{
		int l, r, sum = 0;
		l = i, sum = a[i];
		while(sum < a[i] * 2 && l >= 1)
		{
			r = i;
			int nowsum = sum;
			while(nowsum < a[i] * 2 && r <= n)
			{
				if((nowsum % 2 == 0) && nowsum < a[i] * 2) 
				{
				//	cout << l << " " << r << " " << "fuck" << endl;
					ans--;
				}
				r++, nowsum += a[r];
			}
			l--, sum += a[l];
		}
	}
	cout << ans << endl;
	return 0;
}
//qwq