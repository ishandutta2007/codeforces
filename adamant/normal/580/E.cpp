#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 7, base = 47, mod1 = 1e9 + 7, mod2 = 1e9 + 9;

#define hash alflal

struct hash
{
	int h1 = 0;
	int h2 = 0;
	hash(int x):h1(x), h2(x){}
	hash():h1(0), h2(0){}
} sm[4 * maxn];

hash operator + (hash a, hash b)
{
	hash c;
	c.h1 = (a.h1 + b.h1) % mod1;
	c.h2 = (a.h2 + b.h2) % mod2;
	return c;
}
hash operator - (hash a, hash b)
{
	hash c;
	c.h1 = (a.h1 - b.h1 + mod1) % mod1;
	c.h2 = (a.h2 - b.h2 + mod2) % mod2;
	return c;
}


hash operator * (hash a, hash b)
{
	hash c;
	c.h1 = 1LL * a.h1 * b.h1 % mod1;
	c.h2 = 1LL * a.h2 * b.h2 % mod2;
	return c;
}

hash pw[4 * maxn];
hash inv;
int to_push[4 * maxn];

void push(int v, int l, int r)
{
	if(to_push[v] == 0)
		return;
	sm[v] = to_push[v] * (pw[l] - pw[r]) * inv;
	if(r - l > 1)
	{
		to_push[2 * v] = to_push[v];
		to_push[2 * v + 1] = to_push[v];
	}
	to_push[v] = 0;
}

void make(int a, int b, int c, int v = 1, int l = 0, int r = maxn)
{
	push(v, l, r);
	if(a <= l && r <= b)
	{
		to_push[v] = c;
		push(v, l, r);
		return;
	}
	if(r <= a || b <= l)
		return;
	int m = (l + r) / 2;
	make(a, b, c, 2 * v, l, m);
	make(a, b, c, 2 * v + 1, m, r);
	sm[v] = sm[2 * v] + sm[2 * v + 1];
}

hash get(int a, int b, int v = 1, int l = 0, int r = maxn)
{
	push(v, l, r);
	if(a <= l && r <= b)
		return sm[v];
	if(r <= a || b <= l)
		return 0;
	int m = (l + r) / 2;
	return get(a, b, 2 * v, l, m) + get(a, b, 2 * v + 1, m, r);
}

int bpow(int x, int n, int mod)
{
	if(n == 0)
		return 1;
	int t = bpow(x, n / 2, mod);
	t = 1LL * t * t % mod;
	if(n % 2 == 0)
		return t;
	else
		return 1LL * t * x % mod;
}

int main()
{
	//freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    pw[0] = 1;
    for(int i = 1; i < 4 * maxn; i++)
		pw[i] = base * pw[i - 1];
	inv.h1 = bpow(1 - base + mod1, mod1 - 2, mod1);
	inv.h2 = bpow(1 - base + mod2, mod2 - 2, mod2);
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    for(int i = 0; i < n; i++)
		make(i, i + 1, s[i] - '0' + 1);
    int q = m + k;
    while(q--)
    {
		int t, l, r, c;
		cin >> t >> l >> r >> c;
		l--;
		if(t == 1)
		{
			make(l, r, c + 1);
		}
		if(t == 2)
		{
			int d = c;
			hash a = pw[n - l] * get(l, r - d);
			hash b = pw[n - l - d] * get(l + d, r);
			if(a.h1 == b.h1 && a.h2 == b.h2)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
    return 0;
}