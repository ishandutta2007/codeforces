#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int n, w[101], i, C[101], S, r;
int main(){
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
		C[w[i]]++;
	}
	for (i = 0; i <= 100; i++){
		S += C[i];
		if (r < (S - 1) / (i + 1) + 1) r = (S - 1) / (i + 1) + 1;
	}
	printf("%d\n", r);
}