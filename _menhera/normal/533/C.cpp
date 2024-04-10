#include<cstdio>
#include<algorithm>
int main()
{
	int xp,yp,xv,yv;
	scanf("%d%d%d%d",&xp,&yp,&xv,&yv);
	if(xp+yp<=std::max(xv,yv)) puts("Polycarp");
	else if(xp-1<xv && yp<yv) puts("Polycarp");
	else if(xp<xv && yp-1<yv) puts("Polycarp");
	else puts("Vasiliy");
	return 0;
}