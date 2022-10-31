#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int mod = 998244353;
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
int p2[1000010];
inline void Init2(int n)
{
	p2[0] = 1;
	for(int i = 1; i <= n; i++)
		p2[i] = p2[i - 1] * 2 % mod;
}
inline int inv(int x)
{
	return fastpow(x, mod - 2);
}
map< pair<int, int>, int > mp;
int r[1000010][2], c[1000010][2], rc[2];
inline int calcr(int x)
{
	return 2 - (bool(r[x][0]) + bool(r[x][1]));
}
inline int calcc(int x)
{
	return 2 - (bool(c[x][0]) + bool(c[x][1]));
}
inline int calcrc()
{
	return 2 - (bool(rc[0]) + bool(rc[1]));
}
int totr[3], totc[3];
signed main()
{
	int n, m, k;
	scanf("%lld %lld %lld", &n, &m, &k);
	Init2(max(n, m));
	totr[0] = totr[1] = 0, totr[2] = n;
	totc[0] = totc[1] = 0, totc[2] = m;
	while(k--)
	{
		int x, y, t;
		scanf("%lld %lld %lld", &x, &y, &t);
		int prer = calcr(x), prec = calcc(y);
		if(mp.find({x, y}) != mp.end() && mp[{x, y}] != -1)
		{
			int tmp = mp[{x, y}];
			r[x][(y ^ tmp) & 1]--;
			c[y][(x ^ tmp) & 1]--;
			rc[(x ^ y ^ tmp) & 1]--;
		}
		mp[{x, y}] = t;
		if(t != -1)
		{
			r[x][(y ^ t) & 1]++;
			c[y][(x ^ t) & 1]++;
			rc[(x ^ y ^ t) & 1]++;
		}
		int nowr = calcr(x), nowc = calcc(y);
		totr[prer]--, totc[prec]--;
		totr[nowr]++, totc[nowc]++;
		int ansr = totr[0] ? 0 : p2[totr[2]], ansc = totc[0] ? 0 : p2[totc[2]];
		printf("%lld\n", (ansr + ansc - calcrc() + mod) % mod);
	}
	return 0;
}