#include<cstdio>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
using namespace std;
map<long long, int>Map;
int n, cnt, vis[1010];
long long w[1010], Mod = 998244353;
long long gcd(long long a, long long b) {
	return b ? gcd(b, a%b) : a;
}
int main() {
	int n, i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		vis[i] = 1;
		long long a;
		scanf("%lld", &a);
		w[i] = a;
		for (j = 1; j <= 40000; j++) {
			if (1ll * j*j*j*j == a)break;
		}
		if (j != 40001) {
			Map[j] += 4;
		}
		else {
			long long t = sqrt(a);
			int chk = 0;
			for (j = t - 100; j <= t + 100; j++) {
				if (j > 0 && 1ll*j*j == a) {
					chk = 1;
					break;
				}
			}
			if (chk)Map[j] += 2;
			else {
				t = (long long)pow(a, 1.0 / 3);
				for (j = t - 100; j <= t + 100; j++) {
					if (j > 0 && 1ll * j*j*j == a) {
						chk = 1;
						break;
					}
				}
				if (chk) {
					Map[j] += 3;
				}
				else vis[i] = 0;
			}
		}
	}
	for (i = 1; i<= n; i++) {
		if (vis[i])continue;
		vis[i] = 1;
		int c = 1;
		long long tt = -1;
		for (j = 1; j <= n; j++) {
			if (i == j)continue;
			if (w[i] == w[j]) {
				c++;
				vis[j] = 1;
			}
			else {
				long long g = gcd(w[i], w[j]);
				if (g != 1) tt = g;
			}
		}
		if (tt == -1) {
			cnt++;
			Map[-cnt]+=c;
			cnt++;
			Map[-cnt]+=c;
		}
		else {
			Map[tt] += c;
			Map[w[i] / tt] += c;
		}
	}
	long long res = 1;
	for (auto &x : Map) {
		res *= x.second + 1;
		res %= Mod;
	}
	printf("%lld\n", res);
	fflush(stdout);
}