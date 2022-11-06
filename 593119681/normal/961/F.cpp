#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000000 + 5

int n, lim, Max[N], Ans[N], Pow[2][N], Hash[2][N];
char s[N];

class HASH
{
public :
	HASH () {}
	HASH (char *p, int _sz, int _K, int _Mod, int *_pow, int *_hash)
	 : sz(_sz), K(_K), Mod(_Mod), pow(_pow), hash(_hash)
	{
		pow[0] = 1, hash[0] = 0;
		for (int i = 1; i <= sz; i ++)
		{
			pow[i] = 1LL * pow[i - 1] * K % Mod;
			hash[i] = (1LL * hash[i - 1] * K + p[i] - 'a' + 5) % Mod;
		}
	}
	
	int GetValue(int l, int r)
	{
		int t_r = hash[r], t_l = 1LL * hash[l - 1] * pow[r - l + 1] % Mod;
		return (t_r - t_l + Mod) % Mod;
	}

private :
	int sz, K, Mod;
	int *pow, *hash;
}Hash1, Hash2;

int Calc(int c_1, int c_2)
{
	int l = 0, r = min(min(c_1, n - c_1 + 1), min(c_2, n - c_2 + 1));
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		int l_1 = c_1 - mid + 1, r_1 = c_1 + mid - 1;
		int l_2 = c_2 - mid + 1, r_2 = c_2 + mid - 1;
		// printf("*%d, %d, %d, %d*\n", Hash1.GetValue(l_1, r_1), Hash1.GetValue(l_2, r_2), Hash2.GetValue(l_1, r_1), Hash2.GetValue(l_2, r_2));
		if (Hash1.GetValue(l_1, r_1) == Hash1.GetValue(l_2, r_2) && Hash2.GetValue(l_1, r_1) == Hash2.GetValue(l_2, r_2))
			l = mid;
		else r = mid - 1;
	}
	// printf("# %d, %d => %d\n", c_1, c_2, l);
	return l;
}

int main()
{
	scanf("%d", &n);
	lim = n + 1 >> 1;
	scanf("%s", s + 1);
	Hash1 = HASH(s, n, 37, 1000000007, Pow[0], Hash[0]);
	Hash2 = HASH(s, n, 41, 998244353, Pow[1], Hash[1]);
	for (int i = 1; i < lim + (n + 1 & 1); i ++)
		Max[i - Calc(i, n - i + 1) + 1] = i;
	for (int i = 1; i <= lim; i ++)
	{
		Max[i] = max(Max[i - 1], Max[i]);
		Ans[i] = Max[i] >= i ? (Max[i] - i) * 2 + 1 : -1;
	}
	for (int i = 1; i <= lim; i ++)
		printf("%d%c", Ans[i], i == lim ? '\n' : ' ');
	return 0;
}