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
const int N = 1e5 + 9, M = 379, INF = 1e18;
int n, a[N];
int f[N], pos[N];
int L[N], R[N], tag[N], B;
struct node
{
	int val, pos;
};
inline void Max(node &x, node y) 
{
	if(x.val < y.val) x = y;
	return ;
}
struct Block
{
	int l, r, q[M];
	int k, b;
	inline int g(int x) {return f[x] + k * a[x] + b;}
	inline double slope(int x, int y) 
	{
		if(a[x] == a[y]) 
		{
			if(f[x] > f[y]) return -INF;
			else return INF;
		}
		else return 1.0 * (f[x] - f[y]) / (a[x] - a[y]);
	}
	inline void build(int x)
	{
		for (int i = L[x]; i <= R[x]; i++) f[i] += k * a[i] + b;
		k = b = 0;
		l = 1, r = 0;
		for (int i = L[x]; i <= R[x]; i++)
		{
		//	cout << pos[i] << endl;
			while(r > l && slope(q[r - 1], q[r]) < slope(q[r], pos[i])) r--;
			q[++r] = pos[i];
		}	
	}
	inline node get()
	{
		while(r > l && g(q[l]) <= g(q[l + 1])) l++;
	//	cout << 
		return node{g(q[l]), q[l]};
	} 
}t[M];
signed main()
{
	n = read(); B = sqrt(n);
	//B = 1;
	for (int i = 1; i <= n; i++) a[i] = f[i] = read(), pos[i] = i, tag[i] = (i - 1) / B + 1;
	for (int l = 1, r; l <= n; l = r + 1) 
		r = l + B - 1, L[tag[l]] = l, R[tag[l]] = min(n, r);
	for (int i = 1; i <= tag[n]; i++) 
	{
		sort(pos + L[i], pos + R[i] + 1, [&](int x, int y) {return a[x] < a[y];});
		t[i].build(i); 
	} 
	int ans = 0;
	while(1) 
	{
		node res = node{0, 0};
	//	for (int i = 1; i <= tag[n]; i++) cout << t[i].get().pos << " " << t[i].get().val << endl;
		//return 0;
		for (int i = 1; i <= tag[n]; i++) Max(res, t[i].get()); 
		int u = res.pos;
		//cout << res.pos << " " << res.val << endl;
		if(res.val <= 0) break;  
		ans += res.val;
		f[u] = -INF;
		for (int i = 1; i < tag[u]; i++) t[i].b += a[u];
		for (int i = tag[u] + 1; i <= tag[n]; i++) t[i].k += 1;
		for (int i = L[tag[u]]; i < u; i++) f[i] += a[u];
		for (int i = u + 1; i <= R[tag[u]]; i++) f[i] += a[i];
		t[tag[u]].build(tag[u]);
	}
	cout << ans << endl;
	return 0;
}