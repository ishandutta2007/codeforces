#include<cstdio>
#include<algorithm>
using namespace std;
char p[100100], q[101000], U[101000], R[201000];
int n, c, Loc[101000];
int main() {
	scanf("%s", p);
	int i, c = 0;
	for (i = 0; p[i]; i++) {
		if (p[i] == 'a')continue;
		Loc[c] = i;
		q[c++] = p[i];
	}
	if (c == 0) {
		printf("%s\n", p);
		return 0;
	}
	n = i;
	for (i = 0; i < Loc[c / 2]; i++) {
		U[i] = p[i];
	}
	int L = Loc[c / 2];
	for (i = 0; i < Loc[c / 2]; i++) {
		if (p[i] != 'a')U[L++] = p[i];
	}
	if (L == n) {
		for (i = 0; i < n; i++) {
			if (p[i] != U[i])break;
		}
		if (i == n) {
			for (i = 0; i < Loc[c / 2]; i++)printf("%c", U[i]);
			return 0;
		}
	}
	puts(":(");
}