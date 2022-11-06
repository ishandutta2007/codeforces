/*
    
	
	
	
	
	
	
	
	
	
	
	
					                  ever17
*/

/*
	
*/

/*
	
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
struct node
{
	int ans, ansl, ansr, cnt1, cnt0, len;
}tree[N << 2];
int a[N], n, q;
inline void Set(int x, int p) 
{
	if(a[x] == 0) 
	{
		tree[p].ans = tree[p].ansl = tree[p].ansr = tree[p].cnt1 = tree[p].cnt0 = 0;
		return ;
	}	
	tree[p].ans = tree[p].ansl = tree[p].ansr = 1;
	if(a[x] > 0) 
		tree[p].cnt1 = 1, tree[p].cnt0 = 0;
	else
		tree[p].cnt1 = 0, tree[p].cnt0 = 1;
	return ;
}
inline int lc(int p) {return p << 1;}
inline int rc(int p) {return p << 1 | 1;}
inline void push_up(int p)
{
	/* fuck code */
	tree[p].ans = max(tree[lc(p)].ans, tree[rc(p)].ans);
	tree[p].ans = max(tree[p].ans, max(tree[rc(p)].ansl + tree[lc(p)].cnt1, tree[lc(p)].ansr + tree[rc(p)].cnt0));
	if(tree[lc(p)].cnt1 == tree[lc(p)].len) tree[p].ansl = tree[lc(p)].cnt1 + tree[rc(p)].ansl;
	else if(tree[lc(p)].ansl == tree[lc(p)].len) tree[p].ansl = tree[lc(p)].ansl + tree[rc(p)].cnt0;
	else tree[p].ansl = tree[lc(p)].ansl;
	if(tree[rc(p)].cnt0 == tree[rc(p)].len) tree[p].ansr = tree[rc(p)].cnt0 + tree[lc(p)].ansr;
	else if(tree[rc(p)].ansr == tree[rc(p)].len) tree[p].ansr = tree[rc(p)].ansr + tree[lc(p)].cnt1;
	else tree[p].ansr = tree[rc(p)].ansr;
	if(tree[lc(p)].cnt0 == tree[lc(p)].len) tree[p].cnt0 = tree[lc(p)].cnt0 + tree[rc(p)].cnt0;
	else tree[p].cnt0 = tree[lc(p)].cnt0;
	if(tree[rc(p)].cnt1 == tree[rc(p)].len) tree[p].cnt1 = tree[rc(p)].cnt1 + tree[lc(p)].cnt1;
	else tree[p].cnt1 = tree[rc(p)].cnt1;
	return ;
}
inline void build(int l, int r, int p) 
{
	tree[p].len = r - l + 1;
	if(l == r) 
	{
		Set(l, p); return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, lc(p));
	build(mid + 1, r, rc(p));
	push_up(p);
}
inline void update(int l, int r, int p, int x) 
{
	if(l == r)
	{
		Set(l, p); 
		return ;
	}
	int mid = (l + r) >> 1;
	if(mid >= x) update(l, mid, lc(p), x);
	else update(mid + 1, r, rc(p), x);
	push_up(p);
	return ;
}
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i < n; i++) a[i] = a[i + 1] - a[i]; n--;
	q = read();
	if(!n) 
	{
		for (int i = 1; i <= q; i++) puts("1"); return 0;
	}
	build(1, n, 1);
	for (int i = 1; i <= q; i++) 
	{
		int l = read(), r = read(), d = read();
		if(l - 1 >= 1) 
		{
			a[l - 1] += d;
		//	cout << i << " " << l - 1 << " " << a[l - 1] << endl;
			update(1, n, 1, l - 1);
		}
		if(r <= n) 
		{
			a[r] -= d; 
			update(1, n, 1, r);
		}
		printf("%lld\n", tree[1].ans + 1);
	//	for (int j = 1; j <= n; j++) cout << a[j] << " "; cout << endl;
	}
	return 0;
}