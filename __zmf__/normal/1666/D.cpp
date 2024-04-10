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
const int N = 39;
int n;
int lena, lenb, now;
char a[N], b[N];
bool vis[N];
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) 
	{
		memset(vis, 0, sizeof(vis));
		scanf("%s", a + 1);
		scanf("%s", b + 1);
		lena = strlen(a + 1);
		lenb = strlen(b + 1);
		now = lenb;
		for (int j = lena; j >= 1; j--)
		{
			if(a[j] == b[now] && vis[a[j] - 'A' + 1] == 0) 
			{
				now--;
		//		cout << now << endl;
			}
			else vis[a[j] - 'A' + 1] = 1;
		}
		if(now == 0) puts("YES");
		else puts("NO");
	}
	return 0;
}