#include <stdio.h>

int month[13]={0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int m, d;

int main()
{
	scanf("%d %d",&m,&d);
	int day=d-1;
	day+=month[m];
	int cnt=day/7;
	if(day%7!=0) cnt++;
	printf("%d\n",cnt);

	return 0;
}