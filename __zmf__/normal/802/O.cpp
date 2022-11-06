/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/

/*
	
*/

/*
	
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
const int N = 500009;
int n, k, a[N], b[N], cnt, tot;
priority_queue<pair<int, int>> q;
inline void check(int x)
{
	cnt = tot = 0;
	while(!q.empty()) q.pop();
	for (int i = 1; i <= n; i++) a[i] -= x;
	for (int i = 1; i <= n; i++)
	{
		q.push({-a[i], 1});
		if(q.top().first - b[i] > 0) 
		{
			tot += (-q.top().first + b[i]); cnt += q.top().second; q.pop();
			q.push({b[i], 0}); 
		}
	}
	for (int i = 1; i <= n; i++) a[i] += x; 
	//cout << x << " " << cnt << " " << tot << endl;
	return ;
}
signed main()
{
	n = read(), k = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++) b[i] = read();
	int l = 0, r = 2e9, ans = 0;
	while(l <= r) 
	{
		int mid = (l + r) >> 1;
		check(mid);
		if(cnt == k) {ans = k * mid + tot; break;}
		else if(cnt > k) r = mid - 1;
		else l = mid + 1; 
	}
	cout << ans << endl;
	return 0;
}