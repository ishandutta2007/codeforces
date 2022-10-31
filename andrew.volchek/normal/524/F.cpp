#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <cassert>
#include <stack>
#include <fstream>
#include <unordered_map>
#include <ctime>

using namespace std;

#define snd second
#define fst first
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define left _left
#define y1 _y1
#define right _right

const ld pi = 3.14159265359;

template < typename T > T abs(T x)
{
    return x > 0 ? x : -x;
}

template < typename T > T sqr(T x)
{
	return x * x;
}

const int maxn = 2000005;

const ll mod = 1000000007;
const ll base = 43;

ll pw[maxn * 4];

ll bpow(ll x, ll n)
{
	ll res = 1;
	while (n)
	{
		if (n & 1)
			res = (res * x) % mod;
		x = (x * x) % mod;
		n >>= 1;
	}
	
	return pw[n] = res;
}

char s[maxn];
ll h[maxn];

ll inv = bpow(base, mod - 2);

ll ho[maxn];
ll hc[maxn];


ll invP[maxn * 2], baseP[maxn * 2];

ll getH(int l, int r, int i, int j, int len)
{
	if (len <= l)
		return ho[len];
	else
	{
		ll res = h[min(j, i + (len - l) - 1)] - (i ? h[i - 1] : 0) + mod;
		
		res %= mod;
		res *= invP[i];
		res %= mod;
		
		res *= baseP[l];
		res %= mod;
		res = (res + ho[l]) % mod;
		
		res = res + hc[max(0, len - l - (j - i + 1))] * baseP[l + j - i + 1];
	
		res %= mod;
		
		return res;
	}
}

char getC(int l, int r, int i, int j, int len)
{
	if (len <= l)
	{
		return '(';
	}
	else
	{
		if (len > l + j - i + 1)
			return ')';
		else
			return s[i + (len - l) - 1];
	}
}


bool comp(int l1, int l2, int r1, int r2, int i1, int i2, int len)
{
	int lo = 0, hi = len + 1 + l1 + r1;
	while (hi - lo > 1)
	{
		int mid = (lo + hi) >> 1;
		
		if (getH(l1, r1, i1, i1 + len - 1, mid) == getH(l2, r2, i2, i2 + len - 1, mid))
		{
			lo = mid;
		}
		else
			hi = mid;
	}
	
	return getC(l1, r1, i1, i1 + len - 1, lo + 1) < getC(l2, r2, i2, i2 + len - 1, lo + 1);
}

int bal[maxn];

int t[maxn * 4];

void build(int v, int l, int r)
{
	if (l == r)
	{
		t[v] = bal[l];
		return;
	}
	
	int c = (l + r) >> 1;
	
	build(2 * v, l, c);
	build(2 * v + 1, c + 1, r);
	
	t[v] = min(t[2 * v], t[2 * v + 1]);
}

int get(int v, int l, int r, int i, int j)
{
	if (i <= l && r <= j)
		return t[v];
		
	int res = 1e9;
	int c = (l + r) >> 1;
	
	if (i <= c)
		res = min(res, get(2 * v, l, c, i, j));
	if (c < j)
		res = min(res, get(2 * v + 1, c + 1, r, i, j));
		
	return res;
}

int n;

bool le(int l1, int p1, int r1, int l2, int p2, int r2)
{
	if (l1 + r1 > l2 + r2)
		return true;
	else if (l1 + r1 == l2 + r2)
	{
		if (comp(l1, l2, r1, r2, p1, p2, n))
		{
			return false;
		}
		
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	//srand(time(NULL));
	//gen();
	//freopen("a.in", "r", stdin);

	scanf("%s", s);
	/*for (int i = 0; i < 1e6; i++)
		if (1||rand() & 1)
			s[i] = '(';
		else
			s[i] = ')';*/
			
	baseP[0] = invP[0] = 1;
	for (int i = 1; i < maxn * 2; i++)
		baseP[i] = (baseP[i - 1] * base) % mod, invP[i] = (invP[i - 1] * inv) % mod;
	
	n = strlen(s);
	for (int i = 0; i < n; i++)
	{
		s[i + n] = s[i];
	}
	
	ll hh = 1;
	ll c = 0;
	for (int i = 0; i < n + n; i++)
	{
		ho[i + 1] = (ho[i] + hh * '(') % mod;
		hc[i + 1] = (hc[i] + hh * ')') % mod;
		h[i] = (c + hh * s[i]) % mod;
		c += h[i] - c + mod;
		c %= mod;
		hh = (hh * base) % mod;
	}
	
	int b = 0;
	for (int i = 0; i < n * 2; i++)
	{
		if (s[i] == '(')	
			b++;
		else
			b--;
		bal[i] = b;
	}
	
	build(1, 0, maxn - 1);
	
	int ansL = 1e9, ansPos = -1, ansR = 0;
	
	for (int i = 0; i < n; i++)
	{
		int x = (i ? bal[i - 1] : 0);
		int res = get(1, 0, maxn - 1, i, i + n - 1) - x;
		
		int cl = -min(0, res);
		
		int cr = bal[i + n - 1] - x + cl;
		//cout << cr << endl;
		
		if (le(ansL, ansPos, ansR, cl, i, cr))
		{
			//cout << ansL << " " << ansPos << " " << ansR << " " << cl << " " << i << " " << cr << endl;
			ansL = cl, ansPos = i, ansR = cr;
		}
	}
	
	
	for (int i = 0; i < ansL; i++)
		printf("(");
		
	for (int i = 0; i < n; i++)
		printf("%c", s[ansPos + i]);
		
	for (int i = 0; i < ansR; i++)
		printf(")");
	
	return 0;
}