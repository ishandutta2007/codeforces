#include <cstdio>
#include <cctype>
#include <cstring>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 0;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define P 1000000007
int n, p, pw, f[2][2][2][2];
void Add(int &x, long long y){
	(x += y % P) >= P ? x -= P : 0;
}
int main(){
	n = read(), p = read();
	pw = 500000004;
	f[0][0][0][0] = 1;
	for (register int i = 0; i < n; ++i){
		int x = read(), k = i & 1, t = k ^ 1;
		memset(f[t], 0, sizeof(f[t]));
		for (register int w = 0; w <= 1; ++w)
			for (register int b = 0; b <= 1; ++b)
				for (register int wb = 0; wb <= 1; ++wb)
					if (f[k][w][b][wb]){
						if (x != 1){
							if (!b) Add(f[t][1][b][wb ^ 1], 1ll * f[k][w][b][wb] * pw << 1);
							else Add(f[t][1][b][wb ^ 1], 1ll * f[k][w][b][wb] * pw), Add(f[t][w][b][wb], 1ll * f[k][w][b][wb] * pw);
						}
						if (x != 0){
							if (!w) Add(f[t][w][1][wb ^ 1], 1ll * f[k][w][b][wb] * pw << 1);
							else Add(f[t][w][1][wb ^ 1], 1ll * f[k][w][b][wb] * pw), Add(f[t][w][b][wb], 1ll * f[k][w][b][wb] * pw);
						}
					}
		(pw <<= 1) %= P;
	}
	int ans = 0;
	for (register int i = 0; i <= 1; ++i)
		for (register int j = 0; j <= 1; ++j)
			Add(ans, f[n & 1][i][j][p]);
	printf("%d", ans);
}