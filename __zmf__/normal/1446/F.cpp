/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
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
const double eps = 1e-9, PI = 3.14159265358979323846;
const int N = 2e5; 
int n, k, c[N + 9];
double l, r;
struct point
{
	double x, y;
}p[N + 9], q[N + 9];
inline bool cmp(point x, point y) 
{
	if(fabs(x.x - y.x) >= eps) return x.x < y.x;
	else return x.y < y.y;
}
inline bool cmp2(int x, int y) 
{
	if(q[x].x != q[y].x) return q[x].x < q[y].x;
	return q[x].y < q[y].y;
}
double b[N + 9];
int id[N + 9];
inline int lowbit(int x) {return x & (-x);}
inline void update(int x) 
{
	while(x <= N) c[x]++, x += lowbit(x);
}
inline int query(int x) 
{
	int res = 0;
	while(x) res += c[x], x -= lowbit(x);
	return res;
}
inline int check(double R) 
{
	int cnt = 0;
	memset(c, 0, sizeof(c));
	for (int i = 1; i <= n; i++) 
	{
		if(p[i].x * p[i].x + p[i].y * p[i].y <= R * R + eps) continue;
		double dis = sqrt(p[i].x * p[i].x + p[i].y * p[i].y);
		double f1 = atan2(p[i].y, p[i].x), f2 = acos(R / dis);
		q[i].x = f1 - f2, q[i].y = f2 + f1;
		if(q[i].x < -PI) q[i].x += 2.0 * PI;
		if(q[i].y > PI) q[i].y -= 2.0 * PI;
		if(q[i].y < q[i].x) swap(q[i].x, q[i].y);
		b[++cnt] = q[i].x, b[++cnt] = q[i].y;
	}
	sort(b + 1, b + cnt + 1);
	int pep = 0, ans = n * (n - 1) / 2;
	for (int i = 1; i <= n; i++)
	{
		if(p[i].x * p[i].x + p[i].y * p[i].y <= R * R + eps) continue;
		q[i].x = lower_bound(b + 1, b + cnt + 1, q[i].x) - b;
		q[i].y = lower_bound(b + 1, b + cnt + 1, q[i].y) - b;
		id[++pep] = i;
	}
	sort(id + 1, id + pep + 1, cmp2);
	for (int i = 1; i <= pep; i++) 
	{
		int x = id[i];
		ans -= query(q[x].y); ans += query(q[x].x - 1); 
		update(q[x].y);
	}
	//cout << R << " " << ans << " " << pep  << endl;
	return ans;
}
signed main()
{
	n = read(), k = read();
	for (int i = 1; i <= n; i++) p[i].x = (double)read(), p[i].y = (double)read();
	l = 0, r = 20000;
	while(fabs(r - l) >= eps)
	{
		double mid = (r + l) / 2.0;
		if(check(mid) < k) l = mid;
		else r = mid;
	//	cout << l << " " << r << endl; 
	}
	printf("%.9Lf\n", l);
	return 0;
}