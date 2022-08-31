#include<cstdio>
#include<algorithm>
#define BS 105000
using namespace std;
int C[21][201000];
int n, res = 19, w[21], R[21];
void DFS(int dep, int cnt, int b, int e) {
	int i, ck = 0, ck2 = 0;
	if (dep >= 20)return;
	for (i = b; i <= e; i++) {
		if (C[dep][i + BS]){
			if(i)ck = 1;
			if (abs(i) & 1)ck2 = 1;
		}
	}
	w[dep] = 0;
	if (!ck) {
		if (res > cnt) {
			res = cnt;
			for (i = 0; i < 20; i++)R[i] = w[i];
		}
		return;
	}
	if (!ck2) {
		for (i = b; i <= e; i++) {
			if (C[dep][i + BS]) {
				C[dep + 1][i / 2 + BS] = 1;
			}
		}
		DFS(dep + 1, cnt, b / 2, e / 2);
		for (i = b; i <= e; i++) {
			if (C[dep][i + BS]) {
				C[dep + 1][i / 2 + BS] = 0;
			}
		}
	}
	else {
		w[dep] = -1;
		for (i = b; i <= e; i++) {
			if (C[dep][i + BS]) {
				if (abs(i) & 1)C[dep + 1][(i+1) / 2 + BS] = 1;
				else C[dep + 1][i / 2 + BS] = 1;
			}
		}
		DFS(dep + 1, cnt + 1, (b-1) / 2, (e+1) / 2);
		for (i = b; i <= e; i++) {
			if (C[dep][i + BS]) {
				if (abs(i) & 1)C[dep + 1][(i + 1) / 2 + BS] = 0;
				else C[dep + 1][i / 2 + BS] = 0;
			}
		}
		w[dep] = 1;
		for (i = b; i <= e; i++) {
			if (C[dep][i + BS]) {
				if (abs(i) & 1)C[dep + 1][(i - 1) / 2 + BS] = 1;
				else C[dep + 1][i / 2 + BS] = 1;
			}
		}
		DFS(dep + 1, cnt + 1, (b-1) / 2, (e+1) / 2);
		for (i = b; i <= e; i++) {
			if (C[dep][i + BS]) {
				if (abs(i) & 1)C[dep + 1][(i - 1) / 2 + BS] = 0;
				else C[dep + 1][i / 2 + BS] = 0;
			}
		}
	}
	w[dep] = 0;
}
int main() {
	int i, a;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a);
		C[0][a+BS] = 1;
	}
	DFS(0, 0, -100000, 100000);
	printf("%d\n", res);
	for (i = 0; i < 20; i++) {
		if (R[i])printf("%d ", (1 << i)*R[i]);
	}
}