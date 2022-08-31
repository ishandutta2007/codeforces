#include<stdio.h>
int S[5010], n, m, i, M[5010], j;
int w[5010][4], C;
int main()
{
	int p, a, b, c, t;
	scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++)M[i] = 999999999;
	while(m--) {
		scanf("%d%d%d%d", &p, &a, &b, &c);
		w[C][0]=p, w[C][1] = a, w[C][2] = b, w[C++][3] = c;
		if (p == 1){
			for (i = a; i <= b; i++)S[i] += c;
			continue;
		}
		for (i = a; i <= b; i++){
			if (M[i] > c - S[i])M[i] = c - S[i];
		}
	}
	for (i = 1; i <= n; i++)S[i] = 0;
	for (i = 0; i < C; i++){
		if (w[i][0] == 1){
			for (j = w[i][1]; j <= w[i][2]; j++)S[j] += w[i][3];
			continue;
		}
		m = -999999999;
		for (j = w[i][1]; j <= w[i][2]; j++){
			if (m < M[j] + S[j])m = M[j] + S[j];
		}
		if (m != w[i][3])break;
	}
	if (i == C){
		printf("YES\n");
		for (i = 1; i <= n; i++)printf("%d ", M[i]);
	}
	else{
		printf("NO\n");
	}
}