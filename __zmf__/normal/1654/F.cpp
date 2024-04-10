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
const int N = 1e6 + 9;
int n, len;
char s[N]; 
int rk[N];
struct point
{
	int a, b, id;
}p[N];
inline bool cmp(point x, point y)
{
	if(x.a == y.a) return x.b < y.b;
	else return x.a < y.a; 
}
signed main()
{
	n = read(); len = (1 << n);
	scanf("%s", s); 
	for (int i = 0; i < len; i++) p[i].a = s[i] - 'a' + 1;
	for (int i = 0; i < len; i++) p[i].id = i;
	sort(p, p + len, cmp);
	int cnt = 1; rk[p[0].id] = 1;
	for (int i = 1; i < len; i++) 
	{
		if(p[i].a != p[i - 1].a || p[i].b != p[i - 1].b) cnt++;
		rk[p[i].id] = cnt;
	}
	for (int t = 1; t < len; t <<= 1) 
	{
		for (int i = 0; i < len; i++) p[i].id = i, p[i].a = rk[i], p[i].b = rk[(i ^ t)];
		sort(p, p + len, cmp);
		cnt = 1; rk[p[0].id] = 1;
		for (int i = 1; i < len; i++) 
		{
			if(p[i].a != p[i - 1].a || p[i].b != p[i - 1].b) cnt++;
			rk[p[i].id] = cnt;
		}	
	}
	int pos = 0;
	for (int i = 0; i < len; i++) 
		if(rk[i] == 1) pos = i;
	for (int i = 0; i < len; i++) 
		putchar(s[(i ^ pos)]);
	return 0;
}