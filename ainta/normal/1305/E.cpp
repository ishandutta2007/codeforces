#include<cstdio>
#include<algorithm>
#include<vector>
#include<random>
#include<ctime>
#include<iostream>
#include<cassert>
using namespace std;
int n, K, Res[5010];
void Solve() {
	int i, j;
	scanf("%d%d", &n, &K);
	long long res = 0;
	for (i = 1; i <= n; i++) {
		res += (i - 1) / 2;
		if (res >= K) {
			Res[i] = i + (res - K) * 2;
			int del = Res[i] + 1;
			Res[i + 1] = 5e8 + del;
			for (j = i + 2; j <= n; j++) {
				Res[j] = Res[j - 1] + del;
			}
			for (j = 1; j <= n; j++)printf("%d ", Res[j]);
			puts("");
			return;
		}
		Res[i] = i;
	}
	puts("-1");

}
int main() {
	int TC = 1;
	while (TC--) {
		Solve();
	}
}