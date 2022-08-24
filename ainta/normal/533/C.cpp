#include<stdio.h>
int main(){
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if (a <= c && b <= d){
		printf("Polycarp\n");
	}
	else{
		if (a + b <= c || a + b <= d)printf("Polycarp\n");
		else printf("Vasiliy\n");
	}
}