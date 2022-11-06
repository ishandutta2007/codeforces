/*
	
	
	
	
	
	

	
	
	
										Narcissu
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
	while (ch <= '9'&&ch >= '0')sum=sum*10+ch-'0',ch=getchar();
	return sum * nega;
}
const int N = 1e6 + 9, M = 1e7 + 9;
int n, a[N], val[M], ans, cnt;
bool vis[M];
inline int get(int x, int y)
{
	int res = 0;
	while(x % y == 0) x /= y, ++res;
	return res;
}
inline int check(int p, int x)
{
	int res = 0;
	while(p) res = res + p / x, p /= x; 
	return res;
}
inline int get_val(int num, int x)
{
	if(x == 0) return 1;
	int l = num, r = num * x, ans = 0, mid; 
	while(l <= r)
	{
		mid = (l + r) >> 1;
		if(check(mid, x) >= num) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	return ans;
}
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read(), val[a[i]]++;
	for (int i = M - 9; i >= 1; i--) val[i] = val[i + 1] + val[i];
	ans = 1;
	for (int i = 2; i <= M - 9; i++)
		if(!vis[i])
		{
			cnt = 0;
			for (int j = 1; j <= (M - 9) / i; j++) 
				if(i * j <= (M - 9)) 
				{
					vis[j * i] = 1, cnt = cnt + (1 + get(j, i)) * val[i * j]; 
				}
	//		if(i <= 20)cout << i << " " << cnt << endl; 
			ans = max(ans, get_val(cnt, i));
		}
	cout << ans << endl;
	return 0;
}