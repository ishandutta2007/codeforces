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
const int N = 1e5 + 9, mod = 1e9 + 7;
const double eps = 0.000000000001;
int a[N];
int k, n, m, ans = 1;
struct oper
{
	int opt, pos, b;
}p[N];
struct point
{
	int x, y, id, opt;
	double p;
}q[N], pp[N];
int v1[N], pos1[N];
vector<pair<int, int> > v[N];
inline int Pow(int x, int y)
{
	int res = 1, base = x;
	while(y)
	{
		if(y & 1) res = res * base % mod;
		base = base * base % mod;
		y >>= 1;
	}
	return res;
}
inline bool cmp(point xxx, point yyy)
{
	return xxx.p - yyy.p > eps;
}
inline bool cmp2(point xxx, point yyy)
{
	if(xxx.opt != yyy.opt) return xxx.opt < yyy.opt;
	else return xxx.id < yyy.id;
}
signed main()
{
	k = read(), n = read(), m = read();
	for (int i = 1; i <= k; i++) a[i] = read(), ans = ans * a[i] % mod;
	for (int i = 1; i <= n; i++) q[i].y = 1, q[i].id = i; 
	for (int i = 1; i <= n; i++) 
	{
		p[i].opt = read(), p[i].pos = read(), p[i].b = read(); 
		q[i].opt = p[i].opt;
		if(p[i].opt == 1) 
		{
			if(v1[p[i].pos] < p[i].b) v1[p[i].pos] = p[i].b, pos1[p[i].pos] = i;
		}
		else if(p[i].opt == 2) v[p[i].pos].push_back({p[i].b, i});
		else q[i].id = i, q[i].x = p[i].b - 1, q[i].y = 1; 
	}
	for (int i = 1; i <= k; i++)
	{
		if(v1[i] > a[i]) v[i].push_back({v1[i] - a[i], pos1[i]}); 
		if(v[i].size() == 0) continue;
		sort(v[i].begin(), v[i].end());
		reverse(v[i].begin(), v[i].end());
		for (int j = 0; j < v[i].size(); j++)
		{
			pair<int, int> t = v[i][j];
			q[t.second].id = t.second, q[t.second].x = t.first, q[t.second].y = a[i], a[i] += t.first; 
		}
	}
	for (int i = 1; i <= n; i++) q[i].p = q[i].x * 1.0 / q[i].y * 1.0, q[i].id = i; 
	sort(q + 1, q + n + 1, cmp);
	int res = n;
	for (int i = 1; i <= n; i++)
		if(q[i].p <= eps)
		{
			res = i - 1; break;
		}
	res = min(res, m);
	cout << res << endl;
	for (int i = 1; i <= res; i++)
		pp[i] = q[i];
	sort(pp + 1, pp + res + 1, cmp2);
	for (int i = 1; i <= res; i++) printf("%lld ", pp[i].id);
	return 0;
}
// (n * n - m) / (n * n) * 1 / (n * n)