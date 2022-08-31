#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
using namespace std;
int x;
int main()
{
	scanf("%d", &x);
	int i, t;
	if (x == 3){
		printf("5\n");
		return 0;
	}
	for (i = 1;; i+=2){
		t = (i*i + 1) / 2;
		if (t >= x)break;
	}
	printf("%d\n", i);
}