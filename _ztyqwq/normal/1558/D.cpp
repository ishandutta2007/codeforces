#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int mod = 998244353;
struct Splay
{
	int fa, ch[2], sz;
	int val;
	int tag;
}s[800010];
int cnt = 0, root = 0;
void pushup(int p)
{
	s[p].sz = s[s[p].ch[0]].sz + s[s[p].ch[1]].sz + 1;
}
void pushdown(int p)
{
	if(s[p].tag)
	{
		s[p].val += s[p].tag;
		s[s[p].ch[0]].tag += s[p].tag;
		s[s[p].ch[1]].tag += s[p].tag;
		s[p].tag = 0;
		// swap(s[p].ch[0], s[p].ch[1]);
	}
}
bool get(int p)
{
	return s[s[p].fa].ch[1] == p;
}
void connect(int p, int fa, int d)
{
	s[fa].ch[d] = p;
	s[p].fa = fa;
}
void rotate(int p)
{
	bool d = get(p) ^ 1;
	int fa = s[p].fa, ffa = s[fa].fa, son = s[p].ch[d];
	connect(p, ffa, get(fa));
	connect(son, fa, d^1);
	connect(fa, p, d);
	pushup(fa);
	pushup(p);
}
void splay(int p, int tar)
{
	while(s[p].fa != tar)
	{
		int fa = s[p].fa, ffa = s[fa].fa;
		if(ffa != tar)
			rotate((get(p) ^ get(fa)) ? p : fa);
		rotate(p);
	}
	if(!tar)
		root = p;
}
int Insert(int &u, int fa, int x)
{
	if(u == 0)
	{
		u = ++cnt;
		s[u].fa = fa;
		s[u].ch[0] = s[u].ch[1] = 0;
		s[u].sz = 1;
		s[u].val = x;
		s[u].tag = 0;
		return u;
	}
	pushdown(u);
	if(x < s[u].val)
		return Insert(s[u].ch[0], u, x);
	else if(x > s[u].val)
		return Insert(s[u].ch[1], u, x);
	else
		return u; // nothing happened
}
inline void Print(int u)
{
	if(!u)
		return;
	printf("NODE #%lld: fa = %lld, ch = %lld, %lld, sz = %lld, val = %lld, tag = %lld\n", u, s[u].fa, s[u].ch[0], s[u].ch[1], s[u].sz, s[u].val, s[u].tag);
	Print(s[u].ch[0]);
	Print(s[u].ch[1]);
}


inline int fastpow(int a, int n)
{
	int ans = 1;
	while(n)
	{
		if(n & 1)
			ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans;
}
inline int inv(int x)
{
	return fastpow(x, mod - 2);
}
int fac[500001], ifac[500001];
inline void InitFac(int n)
{
	fac[0] = 1;
	for(int i = 1; i <= n; i++)
		fac[i] = fac[i - 1] * i % mod;
	ifac[n] = inv(fac[n]);
	for(int i = n; i >= 1; i--)
		ifac[i - 1] = ifac[i] * i % mod;
}
inline int C(int n, int m)
{
	return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
signed main()
{
	int t;
	scanf("%lld", &t);
	InitFac(400000);
	while(t--)
	{
		int n, m;
		scanf("%lld %lld", &n, &m);
		cnt = 0, root = 0;
		while(m--)
		{
			int x, y;
			scanf("%lld %lld", &x, &y);
			int yy = Insert(root, 0, y);
			splay(yy, 0);
			s[yy].val++;
			s[s[yy].ch[1]].tag++;
			// Print(root);
		}
		// cout << "CNT = " << cnt << endl;
		printf("%lld\n", C(2 * n - 1 - cnt, n));
	}
	return 0;
}