#include <stdio.h>

int main()
{
	long long ax,ay,bx,by,cx,cy;
	scanf("%lld%lld%lld%lld%lld%lld",&ax,&ay,&bx,&by,&cx,&cy);
	if(ax==bx && ay==by && bx==cx && by==cy) printf("Yes\n");
	else if((ax-bx)*(ax-bx)+(ay-by)*(ay-by)!=(bx-cx)*(bx-cx)+(by-cy)*(by-cy)) printf("No\n");
	else if((ax-bx)*(by-cy)==(bx-cx)*(ay-by)) printf("No\n");
	else printf("Yes\n");
}