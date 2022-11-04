#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

int S1[3010][3010], X1[100010], Y1[100010], X2[100010], Y2[100010];

ll S2[3010][3010];

int B[3010][3010];

ll ran()
{
	ll ans = 0;
	for(int i = 1; i <= 4; i++) ans = ans * 32768 + rand();
	return ans;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d%d%d", &X1[i], &Y1[i], &X2[i], &Y2[i]);
		X1[i]++, Y1[i]++;
		if(X2[i] - X1[i] == Y2[i] - Y1[i]) return printf("YES 1\n%d\n", i), 0;
		for(int j = X1[i]; j <= X2[i]; j++)
			for(int k = Y1[i]; k <= Y2[i]; k++) S1[j][k] = 1;
		S2[X1[i]][Y1[i]] = S2[X2[i]][Y2[i]] = ran();
		S2[X1[i]][Y2[i]] = S2[X2[i]][Y1[i]] = ran();
		B[X2[i]][Y2[i]] = 1;
		B[X1[i]][Y1[i]] = 2;
	}
	for(int i = 1; i <= 3000; i++)
		for(int j = 1; j <= 3000; j++)
			S1[i][j] += S1[i - 1][j] + S1[i][j - 1] - S1[i - 1][j - 1],
			S2[i][j] ^= S2[i - 1][j] ^ S2[i][j - 1] ^ S2[i - 1][j - 1];
	for(int i = 1; i <= 3000; i++)
		for(int j = 1; j <= 3000; j++)
			if(B[i][j] == 1) {
				for(int k = min(i, j); k >= 1; k--) if(B[i - k + 1][j - k + 1] == 2) {
					if(S1[i][j] - S1[i - k][j] - S1[i][j - k] + S1[i - k][j - k] != k * k) continue;
					if(!(S2[i][j] ^ S2[i - k][j] ^ S2[i][j - k] ^ S2[i - k][j - k])) {
						int sm = 0;
						for(int s = 1; s <= n; s++)
							if(X1[s] <= i && X1[s] > i - k && Y1[s] <= j && Y1[s] > j - k) sm++;
						printf("YES %d\n", sm);
						for(int s = 1; s <= n; s++)
							if(X1[s] <= i && X1[s] > i - k && Y1[s] <= j && Y1[s] > j - k) printf("%d ", s);
						return 0;
					}
				}
			}
	return puts("NO"), 0;
}