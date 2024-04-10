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
	while (ch > '9' || ch < '0')
	{
	    if (ch == '-') nega = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0') sum = sum * 10 + ch - '0', ch = getchar();
	return sum * nega;
}
const int N = 1e5 + 9;
int n;
map<string, int> mp, cnt;
string s[N], t;
char p[N][19];
signed main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
		int len = strlen(p[i]);
		for (int j = 0; j < len; j++) s[i] += p[i][j];
		for (int l = 0; l < len; l++)
			for (int r = l; r < len; r++)
			{
				t = "";
				for (int j = l; j <= r; j++) t += p[i][j];
				if(mp[t] != i) mp[t] = i, cnt[t]++;
			}
	}
	int m; cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> t;
		if(!mp[t]) cout << "0" << " " << '-' << endl;
		else cout << cnt[t] << " " << s[mp[t]] << endl;
	}
	return 0;
}