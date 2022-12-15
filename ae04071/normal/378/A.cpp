#include <cstdio>

int ABS(int a) {
	return a<0?-a:a;
}

int main() {
	int a,b;
	scanf("%d%d",&a,&b);
	int c1=0,c2=0,c3=0;
	for(int i=1;i<=6;i++) {
		if(ABS(a-i)<ABS(b-i)) c1++;
		else if(ABS(a-i)>ABS(b-i))c3++;
		else c2++;
	}
	printf("%d %d %d\n",c1,c2,c3);
	return 0;
}