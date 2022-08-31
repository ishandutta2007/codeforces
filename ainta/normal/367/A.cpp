#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, S[100010][3], w[3];
char p[100010];
int main()
{
	int i, a, b, aa, bb, cc, j;
	scanf("%s", p + 1);
	scanf("%d", &m);
	for (i = 1; p[i]; i++){
		S[i][0] = S[i - 1][0];
		S[i][1] = S[i - 1][1];
		S[i][2] = S[i - 1][2];
		S[i][p[i] - 'x']++;
	}
	for (i = 1; i <= m; i++){
		scanf("%d%d", &a, &b);
		w[0] = S[b][0] - S[a - 1][0];
		w[1] = S[b][1] - S[a - 1][1];
		w[2] = S[b][2] - S[a - 1][2];
		sort(w, w + 3);
		if (b - a + 1 <= 2){
			printf("YES\n");
		}
		else if (w[2] - w[0] > 1){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
}