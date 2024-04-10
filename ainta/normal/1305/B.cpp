#include<cstdio>
#include<algorithm>
#include<vector>
#include<random>
#include<ctime>
#include<iostream>
#include<cassert>
using namespace std;
int TC, S1[1010], S2[1010], n;
char p[1010];
void Solve() {
	int i, j;
	scanf("%s",p + 1);
	for (i = 1; p[i]; i++);
	n = i - 1;
	for (i = 1; i <= n; i++) {
		S1[i] = S1[i - 1] + (p[i] == '(');
		S2[i] = S2[i - 1] + (p[i] == ')');
	}
	for (i = 0; i <= n; i++) {
		if (S1[i] == S2[n] - S2[i] && S1[i] == 0) {
			printf("0\n");
			return;
		}
	}
	for (i = 0; i <= n; i++) {
		if (S1[i] == S2[n] - S2[i]) {
			printf("1\n");
			vector<int>T;
			for (j = 1; j <= n; j++) {
				if (j <= i && p[j] == '(')T.push_back(j);
				if (j > i && p[j] == ')')T.push_back(j);
			}
			printf("%d\n", T.size());
			for (auto &t : T)printf("%d ", t);
			puts("");
			return;
		}
	}
}
int main() {
	TC = 1;
	while (TC--) {
		Solve();
	}
}