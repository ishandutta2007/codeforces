#include<cstdio>
#include<algorithm>
#include<vector>
#include<random>
#include<ctime>
#include<iostream>
#include<cassert>
#include<set>
using namespace std;
int n, chk[1010000], P[201000], PC, res;
long long Z[50], w[201000];
void Do(long long a) {
	int i;
	long long s = 0;
	for (i = 1; i <= n; i++) {
		if (w[i] < a)s += a - w[i];
		else {
			long long t = w[i] % a;
			s += min(t, a - t);
		}
		if (s >= res)return;
	}
	res = s;
}
void Solve() {
	int i, k;
	for (i = 2; i <= 1000000; i++) {
		if (chk[i])continue;
		P[++PC] = i;
		for (int j = i + i; j <= 1000000; j += i)chk[j] = 1;
	}
	mt19937 rd((unsigned)time(NULL));
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%lld", &w[i]);
		//w[i] = i * 6 + 9e11 + 1;
	}
	shuffle(w + 1, w + n + 1, rd);
	set<long long>Set;
	for (i = 1; i <= 20 && i<=n; i++) {
		long long j, k;
		long long b = max(1ll, w[i] - 20), e = w[i] + 20;
		for (j = b; j <= e ; j++)Z[j-w[i]+20] = j;
		for (k = 1; k <= PC; k++) {
			long long t = e / P[k] * P[k];
			if (t >= b) {
				Set.insert(P[k]);
				while (t >= b) {
					while (Z[t - w[i] + 20] % P[k] == 0)Z[t - w[i] + 20] /= P[k];
					t -= P[k];
				}
			}
		}
		for (j = b; j <= e; j++) {
			if (Z[j - w[i] + 20]!=1) {
				Set.insert(Z[j - w[i]+20]);
			}
		}
	}
	res = n;
	for (auto &t : Set) {
		Do(t);
	}
	printf("%d\n", res);
}
int main() {
	int TC = 1;
	while (TC--) {
		Solve();
	}
}