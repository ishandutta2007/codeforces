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
int n, ansx, ansy;
struct point
{
	int s, t;
}a[N];
inline bool solve(int s, int t, int type)
{
	if(type == 1) return 1;
	else if(type == 2) return (s % 2 != t % 2);
	else return (s % 2 == t % 2);
}
inline int work(int s, int t, int type)
{
	if(s * 2 > t) return solve(s, t, type);
	int r = t, l = t / 2 + 1;
	while(1) 
	{
		if(type == 1) type = 2;
		else if(type == 2) 
		{
			if(r % 2 == 0) type = 1;
			else if((r - l) % 2 == 0) type = 3;
			else type = 2;
		}
		else
		{
			if(r % 2 == 1) type = 1;
			else if((r - l) % 2 == 0) type = 2;
			else type = 3;
		}
		r = l - 1, l = r / 2 + 1;
		if(l <= s && s <= r) return solve(s, r, type); 
	}
}
inline void add(int s, int t, int flag)
{
	int tmpx = 0, tmpy = 0;
	int px = work(s, t, 2), py = work(s, t, 1);
//	cout << px << " " << py << "qwq" << endl;
	if(flag)
	{
		ansx = px, ansy = py; return ;
	}
	if(px) tmpx |= (ansx ^ 1), tmpy |= (ansy ^ 1);
	if(py) tmpx |= ansx, tmpy |= ansy;
	ansx = tmpx, ansy = tmpy;
}
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i].s = read(), a[i].t = read();
	for (int i = n; i >= 1; i--) add(a[i].s, a[i].t, (i == n));
	cout << ansx << " " << ansy << endl;
	return 0;
}