#include<bits/stdc++.h>

typedef long long LL;

const int N=105;

int tot;
LL xs,ys,x0,y0,ax,bx,ay,by,t;
struct data{LL x,y;}p[N];

LL get_dis(LL x1,LL y1,LL x2,LL y2)
{
	return abs(x1-x2)+abs(y1-y2);
}

void dp()
{
	int ans=0;
	for (int i=1;i<=tot;i++)
		for (int j=1;j<=i;j++)
			for (int k=i;k<=tot;k++)
			{
				if (get_dis(xs,ys,p[i].x,p[i].y)+get_dis(p[i].x,p[i].y,p[j].x,p[j].y)+get_dis(p[j].x,p[j].y,p[k].x,p[k].y)<=t)
					ans=std::max(ans,k-j+1);
				if (get_dis(xs,ys,p[i].x,p[i].y)+get_dis(p[i].x,p[i].y,p[k].x,p[k].y)+get_dis(p[j].x,p[j].y,p[k].x,p[k].y)<=t)
					ans=std::max(ans,k-j+1);
			}
	printf("%d\n",ans);
}

int main()
{
	scanf("%lld%lld%lld%lld%lld%lld",&x0,&y0,&ax,&ay,&bx,&by);
	scanf("%lld%lld%lld",&xs,&ys,&t);
	while (x0-xs<=t&&y0-ys<=t)
	{
		if (get_dis(x0,y0,xs,ys)<=t) p[++tot]=(data){x0,y0};
		x0=x0*ax+bx;y0=y0*ay+by;
	}
	dp();
	return 0;
}