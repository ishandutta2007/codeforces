#include <bits/stdc++.h>

using namespace std;

int n, m, K[100010], Cnt = 0;

const int P[5] = {10000, 1000, 100, 10, 1};

void Search(int S, int x, int S1, int S2, int lstnum, int B)
{
	if(x == 4) {
		S1 += S2 * lstnum * B;
		int tmp = abs(S1 - n);
		if(tmp < 10000 && K[tmp] != S) {
			K[tmp] = S, printf("%04d%04d\n", S, tmp);
			if(++Cnt == m) exit(0);
		}
		return;
	}
	int nown = (S % P[x]) / P[x + 1];
	Search(S, x + 1, S1 + S2 * lstnum * B, 1, nown, 1);
	Search(S, x + 1, S1 + S2 * lstnum * B, 1, nown, -1);
	Search(S, x + 1, S1, S2 * lstnum, nown, B);
	Search(S, x + 1, S1, S2, lstnum * 10 + nown, B);
}

int main()
{
	scanf("%d%d", &n, &m), memset(K, -1, sizeof K);
	for(int i = 0; i <= 9999; i++) Search(i, 1, 0, 1, i / 1000, 1);
}