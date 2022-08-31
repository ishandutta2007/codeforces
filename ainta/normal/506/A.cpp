#include<stdio.h>
#include<algorithm>
using namespace std;
int n, D[30100][601], d, w[30100];
bool chk[30100][601];
void Make(int a, int i, int j){
	if (i > 30000)return;
	if (j > 600)return;
	chk[i][j] = true;
	if (D[i][j] < a + w[i]) D[i][j] = a + w[i];
}
int main()
{
	int i, j, a, t, Res = 0;
	scanf("%d%d", &n, &d);
	for (i = 1; i <= n; i++){
		scanf("%d", &a);
		w[a]++;
	}
	chk[d][300] = true;
	D[d][300] = w[d];
	for (i = d; i <= 30000; i++){
		for (j = max(300 - d + 1, 1); j <= 600; j++){
			if (!chk[i][j])continue;
			if (D[i][j] > Res)Res = D[i][j];
			t = j - 300 + d;
			Make(D[i][j], i + t + 1, j + 1);
			Make(D[i][j], i + t, j);
			if(t > 1)Make(D[i][j], i + t - 1, j - 1);
		}
	}
	printf("%d\n", Res);
}