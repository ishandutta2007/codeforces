#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int abc[400010], ab[400010], bc[400010], a[400010], b[400010], c[400010];
#define lc(u) (u << 1)
#define rc(u) (u << 1 | 1)
inline void pushup(int u)
{
	a[u] = a[lc(u)] + a[rc(u)];
	b[u] = b[lc(u)] + b[rc(u)];
	c[u] = c[lc(u)] + c[rc(u)];
	ab[u] = min(a[lc(u)] + ab[rc(u)], ab[lc(u)] + b[rc(u)]);
	bc[u] = min(b[lc(u)] + bc[rc(u)], bc[lc(u)] + c[rc(u)]);
	abc[u] = min(min(a[lc(u)] + abc[rc(u)], ab[lc(u)] + bc[rc(u)]), abc[lc(u)] + c[rc(u)]);
}
inline void Build(int u, int l, int r)
{
	if(l == r)
	{
		char ch = s[l - 1];
		a[u] = b[u] = c[u] = ab[u] = bc[u] = abc[u] = 0;
		if(ch == 'a')
			a[u] = 1;
		else if(ch == 'b')
			b[u] = 1;
		else
			c[u] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	Build(lc(u), l, mid);
	Build(rc(u), mid + 1, r);;
	pushup(u);
}
inline void Modify(int u, int l, int r, int pos, char ch)
{
	if(r < pos || pos < l)
		return;
	if(l == pos && r == pos)
	{
		a[u] = b[u] = c[u] = 0;
		if(ch == 'a')
			a[u] = 1;
		else if(ch == 'b')
			b[u] = 1;
		else
			c[u] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	Modify(lc(u), l, mid, pos, ch);
	Modify(rc(u), mid + 1, r, pos, ch);
	pushup(u);
}
int main()
{
	int q;
	scanf("%d %d", &n, &q);
	cin >> s;
	Build(1, 1, n);
	while(q--)
	{
		int x;
		char ch;
		scanf("%d %c", &x, &ch);
		Modify(1, 1, n, x, ch);
		printf("%d\n", abc[1]);
	}
	return 0;
}