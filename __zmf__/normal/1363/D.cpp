/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/
//kk
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
const int N = 1009;
int T, n, max_pos, ans[N], k;
int bl[N][N];
char s[N]; 
inline int get(int l, int r, int bel)
{
	int cnt = 0;
	for (int i = l; i <= r; i++)
		if(!bl[bel][i]) cnt++;
	cout << "? " << cnt;
	for (int i = l; i <= r; i++)
		if(!bl[bel][i]) cout << " " << i;
	cout << endl;
	int awa = read();
//	cout << awa << endl;
	return awa;
}
signed main()
{
	T = read();
	for (int ttt = 1; ttt <= T; ttt++)
	{
		memset(bl, 0, sizeof(bl));
		n = read(), k = read();
		for (int i = 1; i <= k; i++)
		{
			int qwq = read(), x;
			for (int j = 1; j <= qwq; j++) x = read(), bl[i][x] = 1;
		}
		int val = get(1, n, 0), l = 1, r = n, mid;
		while(l < r)
		{
			mid = (l + r) >> 1;
			if(get(l, mid, 0) == val) r = mid;
			else l = mid + 1;
		}
		//cout << l << " " << r << endl;
		for (int i = 1; i <= k; i++)
			if(bl[i][r]) ans[i] = get(1, n, i);
			else ans[i] = val;
		cout << "!";
		for (int i = 1; i <= k; i++) cout << " " << ans[i];
		cout << endl;
		cin >> s; 
	}
	return 0;
}