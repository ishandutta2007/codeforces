#include <bits/stdc++.h>

using namespace std;

#define MAX 201000

char A[MAX], B[MAX];
long long Bpop[MAX], i, j, a, b;

int main () {
	scanf("%s %s", A, B);
	a = strlen(A), b = strlen(B);
	memset(Bpop, 0, sizeof Bpop);
	for (i = 0; i <= b - a; i++) if (B[i] == '1') ++Bpop[0];
	for (i = 1; i < a; i++) {
		Bpop[i] = Bpop[i - 1];
		if (B[i - 1] == '1') Bpop[i]--;
		if (B[i + b - a] == '1') Bpop[i]++;
	}
	long long ret = 0;
	for (j = 0; j < a; j++) {
		if (A[j] == '0') ret += Bpop[j];
		else if (A[j] == '1') ret += (b - a + 1 - Bpop[j]);
	}
	printf("%I64d\n", ret);
	return 0;
}