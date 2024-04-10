#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
int w[100010], p[100010];
int main()
{
	int i, c = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &w[i]);
		p[i] = w[i];
	}
	sort(w + 1, w + n + 1);
	for (i = 1; i <= n; i++){
		if (w[i] != p[i])c++;
	}
	if (c <= 2){
		printf("YES\n");
	}
	else printf("NO\n");
}