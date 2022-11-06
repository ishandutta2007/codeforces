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
const int N = 1e5 + 9;
int T, n, m, ans; 
vector<int> x[N], y[N];
inline void solve()
{
	n = read(); m = read();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) 
		{
			int t = read(); 
			x[t].push_back(i); y[t].push_back(j);
		}
	}
	for (int i = 0; i <= 1e5; i++) 
		if(x[i].size() != 0) 
		{
			int sumx = 0, sumy = 0;
			sort(x[i].begin(), x[i].end());
			sort(y[i].begin(), y[i].end()); sumx += x[i][0], sumy += y[i][0];
			for (int j = 1; j < x[i].size(); j++) 
			{
				ans = (ans + j * x[i][j] - sumx);
				ans = (ans + j * y[i][j] - sumy);
				sumx += x[i][j]; sumy += y[i][j];
			}
		}
	cout << ans << endl;
}
signed main()
{
	T = 1;
	while(T--) solve();
	return 0;
}