#include<cstdio>
#include<algorithm>
using namespace std;
int w[401000], n, Num[1001000], C[401000];
void Solve() {
	int i, cnt = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		C[i] = 0;
	}
	sort(w + 1, w + n + 1);
	for (i = 1; i <= n; i++) {
		if (i == 1 || w[i] != w[i - 1])Num[w[i]] = ++cnt;
	}
	for (i = 1; i <= n; i++)w[i] = Num[w[i]];
	for (i = 1; i <= n; i++) {
		C[w[i]]++;
	}
	int s = C[cnt], G = C[cnt], ss = 0, S;
	int RG = 0, RS = 0, RB = 0;
	for (i = cnt - 1; i >= 1; i--) {
		ss += C[i];
		s += C[i];
		if (ss > G)break;
	}
	S = ss;
	ss = 0;
	for (i = i - 1; i >= 1; i--) {
		ss += C[i];
		s += C[i];
		if (ss > G && s*2 <= n) {
			RG = G, RS = S, RB = ss;
		}
	}
	printf("%d %d %d\n", RG, RS, RB);
}
int main() {
	int TC;
	scanf("%d", &TC);
	while (TC--) {
		Solve();
	}
}