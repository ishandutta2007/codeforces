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
const int N = 2009;
const double eps = 1e-9;
int n, a, b, cnta, cntb;
double p[N], u[N], w[N], ansa, ansb, tot;
inline void work(double ca, double cb)
{
	cnta = cntb = tot = 0;
	for (int i = 1; i <= n; i++) 
	{
		double now = 0; int visa = 0, visb = 0;
		if(w[i] - ca - cb > now) visa = visb = 1, now = w[i] - ca - cb;
		if(u[i] - cb > now) visb = 1, visa = 0, now = u[i] - cb;
		if(p[i] - ca > now) visa = 1, visb = 0, now = p[i] - ca;
		cnta += visa, cntb += visb, tot += now;
	}
	return ;
}
signed main()
{
	n = read(), a = read(), b = read();
	for (int i = 1; i <= n; i++) scanf("%lf", &p[i]);
	for (int i = 1; i <= n; i++) scanf("%lf", &u[i]);
	for (int i = 1; i <= n; i++) w[i] = 1 - (1 - u[i]) * (1 - p[i]);
	double la = 0, ra = 1;
	while(ra - la > eps)
	{
		double mida = (la + ra) * 1.0 / 2.0;
		double lb = 0, rb = 1;
		while(rb - lb > eps)
		{
			double midb = (lb + rb) * 1.0 / 2.0;
			work(mida, midb); ansb = midb;
			if(cntb < b) rb = midb;
			else if(cntb > b) lb = midb;
			else break;
		}
		ansa = mida;
		if(cnta < a) ra = mida;
		else if(cnta > a) la = mida;
		else break; 
	}
	printf("%.8lf\n", tot + a * ansa + b * ansb);
	return 0;
}