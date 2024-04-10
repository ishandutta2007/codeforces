#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int n, chk[3010], L, oto[3010], BB[3010], EE[3010];
string A[3010], B[3010];
char p[3010], q[3010];
int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%s", p);
		A[i] = p;
	}
	for (i = 1; i <= n; i++) {
		scanf("%s", p);
		B[i] = p;
	}
	for (i = 1; i <= n; i++) {
		int b = -1, e = -1;
		for (j = 0; j < A[i].size(); j++) {
			if (A[i][j] != B[i][j]) {
				if (b == -1)b = j;
				e = j;
			}
		}
		if (b == -1)continue;
		chk[i] = 1;
		BB[i] = b, EE[i] = e;
		if (!L) {
			for (j = b; j <= e; j++) {
				p[L] = A[i][j];
				q[L] = B[i][j];
				L++;
			}
			p[L] = q[L] = 0;
		}
		else {
			if (e - b + 1 != L) {
				puts("NO");
				return 0;
			}
			for (j = b; j <= e; j++) {
				if (p[j - b] != A[i][j] || q[j - b] != B[i][j]) {
					puts("NO");
					return 0;
				}
			}
		}
	}
	while (1) {
		char qq = 0, ck = 0;
		for (i = 1; i <= n; i++) {
			if (!chk[i])continue;
			if (BB[i] == 0) {
				ck = 1;
				break;
			}
			if (!qq)qq = A[i][BB[i] - 1];
			if (qq != A[i][BB[i] - 1])ck = 1;
		}
		if (ck)break;
		for (i = 1; i <= n; i++)BB[i]--;
	}
	while (1) {
		char qq = 0, ck = 0;
		for (i = 1; i <= n; i++) {
			if (!chk[i])continue;
			if (EE[i] == A[i].size() - 1) {
				ck = 1;
				break;
			}
			if (!qq)qq = A[i][EE[i] + 1];
			if (qq != A[i][EE[i] + 1])ck = 1;
		}
		if (ck)break;
		for (i = 1; i <= n; i++)EE[i]++;
	}
	for (i = 1; i <= n; i++){
		if (chk[i]) {
			L = 0;
			for (j = BB[i]; j <= EE[i]; j++) {
				p[L] = A[i][j];
				q[L] = B[i][j];
				L++;
			}
			break;
		}
	}
	p[L] = q[L] = 0;
	oto[0] = -1;
	for (i = 0; i < L; i++) {
		int t = oto[i];
		while (t != -1 && p[i] != p[t])t = oto[t];
		oto[i + 1] = t + 1;
	}
	for (i = 1; i <= n; i++) {
		int pv = 0;
		for (j = 0; j < A[i].size(); j++) {
			while (pv != -1 && p[pv] != A[i][j])pv = oto[pv];
			pv++;
			if (pv == L) {
				if (!chk[i]) {
					puts("NO"); return 0;
				}
				if (EE[i] != j) {
					puts("NO"); return 0;
				}
				break;
			}
		}
	}
	puts("YES");
	printf("%s\n%s\n", p, q);
}