#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n;
long long w[1010000], tw[1010000];
long long S, res = 1e18;
struct AA {
	int x;
	long long c;
}T[1010000];
int cnt;
long long Calc(long long K) {
	int i;
	long long s = 0, pv;
	for (i = 1; i <= cnt; i++) {
		s += T[i].c;
		if (s > K / 2) {
			pv = T[i].x;
			break;
		}
	}
	long long r = 0;
	for (i = 1; i <= cnt; i++) {
		r += abs(pv - T[i].x)*T[i].c;
	}
	return r;
}
void Do(long long K) {
	int i, j;
	for (i = 1; i <= n; i++)w[i] = tw[i];
	long long cur = 0;
	long long s = 0;
	cnt = 0;
	for (i = 1; i <= n; i++) {
		if (!cur) {
			w[i] %= K;
		}
		if (cur + w[i] >= K) {
			long long t = K - cur;
			T[++cnt] = { i, t };
			s += Calc(K);
			cnt = 0;
			cur = 0;
			w[i] -= t;
			i--;
			continue;
		}
		T[++cnt] = { i, w[i] };
		cur += w[i];
		w[i] = 0;
	}
	res = min(res, s);
}
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		tw[i] = w[i];
		S += w[i];
	}
	long long tp = S;
	for (i = 2; 1ll * i*i <= tp; i++) {
		if (tp%i == 0) {
			Do(i);
			while (tp%i == 0)tp /= i;
		}
	}
	if (tp!=1) {
		Do(tp);
	}
	if (res > 8e17)res = -1;
	printf("%lld\n", res);
}