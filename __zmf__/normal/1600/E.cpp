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
const int N = 2e5 + 9, mod = 1e9 + 7;
int n, a[N], pos1, pos2;
inline bool dfs(int l, int r)
{
	int l1 = pos1 - l + 1, l2 = r - pos2 + 1;
	if(l1 == 0 && a[pos1] >= a[r]) return 0;
	if(l2 == 0 && a[pos2] >= a[l]) return 0;
	if(l1 == 0 && l2 == 0) return 0;
	if(a[l] < a[r]) 
	{
		if(l2 & 1) return 1;
		else return (dfs(l + 1, r) ^ 1);
	}
	else if(a[l] == a[r])
	{
		if(l2 & 1) return 1;
		if(l1 & 1) return 1;
		return 0;
	}
	else
	{
		if(l1 & 1) return 1;
		else return (dfs(l, r - 1) ^ 1);
	}
}
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 2; i <= n; i++) 
		if(a[i] <= a[i - 1]) 
		{
			pos1 = i - 1; break;
		}
	for (int i = n - 1; i >= 1; i--)
		if(a[i] <= a[i + 1])
		{
			pos2 = i + 1; break;
		}
	if(!pos1) pos1 = n; 
	if(!pos2) pos2 = n;
	if(dfs(1, n)) puts("Alice");
	else puts("Bob");
	return 0;
}