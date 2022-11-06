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
const int N = 2e5 + 9, INF = 1e18;
int n, a[N], b[N], cnt1, cnt2, rem; 
int mx1, mx2, suma[N], sumb[N], sum, pep;
signed main()
{
	n = read();
	if(n == 1) 
	{
		printf("%lld\n", read()); return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		int x = read(); sum += abs(x);
		if(x < 0) a[++cnt1] = -x;
		else b[++cnt2] = x; 
		if(i & 1) pep += x;
		else pep -= x;
	}
	sort(a + 1, a + cnt1 + 1); sort(b + 1, b + cnt2 + 1);
	for (int i = 1; i <= cnt1; i++) suma[i] = suma[i - 1] + a[i];
	for (int i = 1; i <= cnt2; i++) sumb[i] = sumb[i - 1] + b[i];
	a[cnt1 + 1] = b[cnt2 + 1] = INF;
	if(n % 2 == 1) rem = (n - 1) / 2; else rem = (n + 2) / 2;
	rem %= 3; mx1 = mx2 = -INF; 
	for (int i = rem; i <= n; i += 3) 
	{
		int now1 = -INF, now2 = -INF;
		if(i < cnt1) now1 = sum - 2 * (suma[cnt1 - i]), now2 = max(now2, now1 + 2 * (a[cnt1 - i] - a[cnt1 - i + 1]));
		else if(i > cnt1) now1 = sum - 2 * (sumb[i - cnt1]), now2 = max(now2, now1 + 2 * (b[i - cnt1] - b[i - cnt1 + 1]));
		else now1 = sum, now2 = now1 - 2 * a[1] - 2 * b[1];
		if(mx1 < now1) mx2 = mx1, mx1 = now1, mx2 = max(mx2, now2);
		else if(mx2 < now1) mx2 = now1;
	}
	if(n % 2 == 1 && mx1 == pep) cout << mx2 << endl;
	else cout << mx1 << endl;
	return 0;
}