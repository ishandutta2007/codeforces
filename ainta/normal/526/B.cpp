#include<stdio.h>
#include<algorithm>
using namespace std;
int n, D[4000], w[4000], m, P[4000];
int main(){
	int i, j, c1, c2, t;
	scanf("%d", &n);
	m = 1 << (n + 1);
	for (i = 2; i < m; i++)scanf("%d", &w[i]);
	for (i = n - 1; i >= 0; i--){
		for (j = (1 << i); j < (1 << (i+1)); j++){
			c1 = j * 2, c2 = j * 2 + 1;
			t = max(P[c1] + w[c1], P[c2] + w[c2]);
			P[j] = t;
			D[j] = D[c1] + D[c2] + (t - P[c1] - w[c1]) + (t - P[c2] - w[c2]);
		}
	}
	printf("%d\n", D[1]);
}