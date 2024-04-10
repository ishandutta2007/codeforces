#include<stdio.h>
char p[101000];
int main()
{
	int i, c = 0, t, s = 0;
	scanf("%s", p);
	for (i = 0; p[i]; i++){
		if (p[i] == '(')c++;
		if (p[i] == '#' || p[i] == ')'){
			c--;
		}
		if (p[i] == '#')t = i;
		if (c < 0)break;
	}
	if (p[i]){
		printf("-1\n");
	}
	else{
		for (i = 0; p[i]; i++){
			if (p[i] == '#'){
				if (i == t){
					s -= (1 + c);
				}
				else s--;
			}
			else if (p[i] == ')')s--;
			else s++;
			if (s < 0)break;
		}
		if (p[i]){
			printf("-1\n");
		}
		else{
			for (i = 0; p[i]; i++){
				if (p[i] == '#'){
					if (i == t){
						printf("%d\n", 1 + c);
					}
					else printf("1\n");
				}
			}
		}
	}
}