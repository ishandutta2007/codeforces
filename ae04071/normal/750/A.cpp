#include <stdio.h>

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int time=240-k;
	int cnt=0, m=5;
	while(time-m*(cnt+1)>=0) {
		time-=m*(cnt+1);
		cnt++;
	}
	if(cnt>n) cnt=n;
	printf("%d\n",cnt);

	return 0;
}