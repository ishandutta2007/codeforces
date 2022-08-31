#include<stdio.h>
int n;
char p[110];
int main(){
	int i, j, k, ck = 0;
	scanf("%d", &n);
	scanf("%s", p);
	for (i = 0; i < n; i++){
		for (j = 1; i + j * 4 < n; j++){
			for (k = 0; k <= 4; k++){
				if (p[i + j*k] != '*')break;
			}
			if (k == 5)ck = 1;
		}
	}
	if (ck == 1)printf("yes\n");
	else printf("no\n");
}