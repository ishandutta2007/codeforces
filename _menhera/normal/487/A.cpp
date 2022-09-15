#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int hp,atk,def;
	int hpm,atkm,defm;
	int h,a,d;
	scanf("%d%d%d",&hp,&atk,&def);
	scanf("%d%d%d",&hpm,&atkm,&defm);
	scanf("%d%d%d",&h,&a,&d);
	for(int cost=0;;cost++)
	for(int j=0;j<=min(210,cost/a);j++)
	for(int k=0;k<=min(210,(cost-j*a)/d);k++)
	{
		if((cost-k*d-j*a)%h!=0) continue;
		int i=(cost-k*d-j*a)/h;
		int hpy=hp+i;
		int atky=atk+j;
		int defy=def+k;
		if(atky-defm<=0) continue;
		int hp_m=hpm;
		int hp_y=hpy;
		if(atkm-defy<=0 || (hp_m-1)/(atky-defm) < (hp_y-1)/(atkm-defy) ){
			printf("%d",cost);return 0;}
	}
	return 0;
}