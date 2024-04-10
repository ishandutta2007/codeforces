#include<stdio.h>
#include<algorithm>
using namespace std;
int n, w[101], i, j, S, Sum, k, C, a, t;
int main()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &k);
		for (j = 1; j <= k; j++){
			scanf("%d", &a);
			Sum += a;
			t = j * 2 - k;
			if (t == 1)w[C++] = -a;
			else if (t <= 0)S += a;
		}
	}
	sort(w, w + C);
	for (i = 0; i < C; i += 2)S -= w[i];
	printf("%d %d\n", S, Sum - S);
}