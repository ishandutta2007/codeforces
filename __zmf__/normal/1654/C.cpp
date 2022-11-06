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
int n, x, sum, res;
map<int, int> mp;
inline void work()
{
	n = read(); sum = 0; mp.clear();
	for (int i = 1; i <= n; i++) 
	{
		x = read(); mp[x]++; sum += x;
	}
	res = 0;
	int cnt0 = 1, cnt1 = 0;
	if(n == 1) 
	{
		puts("YES"); return ;
	}
	while(sum)
	{
		if(sum & 1) cnt1 = cnt1 * 2 + cnt0;
		else cnt0 = cnt0 * 2 + cnt1;
		sum /= 2;
		int t = min(cnt1, mp[sum + 1]); mp[sum + 1] -= t;
		cnt1 -= t;
		t = min(cnt0, mp[sum]);
		cnt0 -= t, mp[sum] -= t;
	}
//	cout << cnt0 << " " << cnt1 << endl;
	if(!cnt0 && !cnt1) 
	{
		puts("YES"); return ;
	}
	puts("NO"); return ;
}
int T;
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		work();
	}
	return 0;
}