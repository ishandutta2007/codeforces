#include<cstdio>
#include<algorithm>
using namespace std;
char p[101000];
int n, Mn=1e9, Res[101000], w[101000], RL = 1e9;
void Do(int pv) {
	if (pv <= 0 || pv >= n || p[pv] == '0')return;
	int i;
	for (i = 0; i < 101000; i++)w[i] = 0;
	for (i = 0; i < pv; i++) {
		w[i] += p[pv - i - 1] - '0';
	}
	for (i = pv; i < n; i++) {
		w[n - 1 - i] += p[i] - '0';
	}
	for (i = 0; i <= n; i++) {
		w[i + 1] += w[i] / 10;
		w[i] %= 10;
	}
	for (i = 100500; i >= 0; i--)if (w[i])break;
	int L = i + 1;
	if (RL < L)return;
	if (RL == L) {
		for (i = L - 1; i >= 0; i--) {
			if (Res[i] != w[i]) {
				if (Res[i] < w[i])return;
				break;
			}
		}
	}
	for (i = 0; i < L; i++)Res[i] = w[i];
	RL = L;
}
int main() {
	int i;
	scanf("%d", &n);
	scanf("%s", p);
	for (i = 1; i < n; i++) {
		if (p[i] > '0') {
			Mn = min(Mn, abs(n / 2 - i));
		}
	}
	for (i = Mn; i <= Mn + 5; i++) {
		int t1 = n / 2 - i;
		Do(t1);
		int t2 = n / 2 + i;
		Do(t2);
	}
	for (i = RL - 1; i >= 0; i--)printf("%d", Res[i]);
}