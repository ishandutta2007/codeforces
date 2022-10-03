#include <cstdio>

int A[200010], n, k, q, x, y, tmp;

int main(){
	scanf("%d %d %d", &n, &k, &q);
	for (int i=0; i<n; i++){
		scanf("%d %d", &x, &y);
		A[x]++;
		A[y+1]--;
	}
	for (int i=1; i<200010; i++) A[i]=A[i-1] + ((tmp+=A[i])>=k);
	while (q--){
		scanf("%d %d", &x, &y);
		printf("%d\n", A[y]-A[x-1]);
	}
	return 0;
}