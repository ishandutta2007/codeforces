#include <stdio.h>

int main()
{
	int n,x,all=0,tmp;
	scanf("%d%d%d",&n,&x,&all);
	while(--n)
		scanf("%d",&tmp),all+=tmp+1;
	if(all!=x) puts("NO");
	else puts("YES");
}