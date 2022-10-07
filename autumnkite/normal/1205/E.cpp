#include <cstdio>
#include <vector>
#define P 1000000007
int n, m, k, ik, f[200005], ans;
std :: vector<int> d[200005];
int qpow(int a, int b){
	int s = 1;
	for (; b; b >>= 1, a = 1ll * a * a % P) if (b & 1) s = 1ll * s * a % P;
	return s;
}
void inc(int &a, int b){ (a += b) >= P ? a -= P : 0; }
void dec(int &a, int b){ (a -= b) < 0 ? a += P : 0; }
int main(){
	scanf("%d%d", &n, &k), ik = qpow(k, P - 2), m = (n - 1) << 1;
	for (register int i = 1; i <= m; ++i)
		for (register int j = i; j <= m; j += i)
			d[j].push_back(i);
	for (register int s = 1; s <= m; ++s){
		int l = std :: max(s - n + 1, 1), r = std :: min(s - 1, n - 1);
		for (register int i = d[s].size() - 1; ~i; --i){
			int g = d[s][i];
			f[g] = r / g - (l - 1) / g;
			for (int p : d[s / g]) if (p > 1) dec(f[g], f[g * p]);
			if (g <= n) inc(ans, 1ll * f[g] * qpow(ik, n - std :: max(s - n, g)) % P);
		}
	}
	printf("%d\n", ans);
}