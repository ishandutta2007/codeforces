#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 100000 + 5
#define M 6000000 + 5
#define LOGN 60

int n, tot, xx, Trie[M][2], Cnt[M], _Cnt[LOGN];
LL cur, Ans[N], A[N], Pow[LOGN];

inline int Log(LL x)
{
	return upper_bound(Pow, Pow + LOGN, x) - Pow - 1;
}

int Modify(int w)
{
	int u = 0;
	for (int i = LOGN - 1; i >= w; i --)
	{
		u = Trie[u][i == w];
		if (!u) return 0;
	}
	int res = Cnt[u];
	for (int i = LOGN - 1, u = 0; i >= w; i --)
	{
		u = Trie[u][i == w];
		Cnt[u] -= res;
	}
	return res;
}

void Modify(int w, int cnt)
{
	if (!cnt) return ;
	int u = 0;
	for (int i = LOGN - 1; i >= w; i --)
	{
		u = Trie[u][i == w];
		Cnt[u] += cnt;
		if (!u) return ;
	}
}

LL Calc(LL x)
{
	int u = 0;
	LL res = 0;
	for (int i = LOGN - 1; ~i; i --)
	{
		int d = (x & Pow[i]) > 0;
		if (Trie[u][d] && Cnt[Trie[u][d]])
			u = Trie[u][d], res |= (d ? Pow[i] : 0);
		else if (Trie[u][d ^ 1] && Cnt[Trie[u][d ^ 1]])
			u = Trie[u][d ^ 1], res |= (!d ? Pow[i] : 0);
		else return -1;
	}
	return res;
}

void Del(LL x)
{
	int u = 0;
	for (int i = LOGN - 1; ~i; i --)
	{
		int d = (x & Pow[i]) > 0;
		u = Trie[u][d];
		Cnt[u] --;
	}
}

int main()
{
	Pow[0] = 1;
	for (int i = 1; i < LOGN; i ++)
		Pow[i] = Pow[i - 1] * 2;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%lld", A + i);
		int u = 0;
		for (int j = LOGN - 1; ~j; j --)
		{
			int d = (A[i] & Pow[j]) > 0;
			if (!Trie[u][d])
				Trie[u][d] = ++ tot;
			u = Trie[u][d];
			Cnt[u] ++;
		}
	}
	for (xx = 1; xx <= n; xx ++)
	{
		LL _cur = cur;
		for (int d = 0; d < LOGN; d ++)
			if ((_cur & Pow[d]) > 0)
				_Cnt[d] = Modify(d);
		LL t = Calc(cur);
		if (!~t) break ;
		Ans[xx] = t;
		cur ^= t;
		Del(t);
		for (int d = 0; d < LOGN; d ++)
			if ((_cur & Pow[d]) > 0)
				Modify(d, _Cnt[d]);
	}
	if (xx <= n) puts("No");
	else
	{
		puts("Yes");
		for (int i = 1; i <= n; i ++)
			printf("%lld%c", Ans[i], i == n ? '\n' : ' ');
	}
	return 0;
}