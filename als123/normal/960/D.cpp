#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const LL lim=1000000000000000000LL;
LL c[65];//
LL get (LL now,LL xx,LL x,LL y) //        xy 
{
	if (xx==x) return now;
	LL lalal=(1LL<<(x-xx-1));
//	printf("%I64d %I64d %I64d %I64d %I64d\n",now,xx,x,y,lalal);
	if (y<=lalal) return get(now*2,xx+1,x,y);
	else return get(now*2+1,xx+1,x,y-lalal);
}
LL get (LL x,LL xx)
{
	LL t=(1LL<<xx-1);//
	//printf("OZY:%I64d %I64d\n",t,x);
	x=x-c[xx];
	x=(x%t+t)%t;
	if (x==0) x=t;
	return x;
}
LL find (LL x)
{
	LL xx;// 
	for (xx=1;;xx++)
	{
		LL t=(1LL<<xx-1LL);//	
		if (x<=t) break;
		x-=t;
	}
	return xx;
}
int main()
{
//	printf("%I64d\n",get(1,1,2,2));
	memset(c,0,sizeof(c));
	LL q;
	scanf("%I64d",&q);
	for (LL u=1;u<=q;u++)
	{
		LL op;
		scanf("%I64d",&op);
		if (op==3)
		{
			LL x;
			scanf("%I64d",&x);
			LL xx;// 
			for (xx=1;;xx++)
			{
				LL t=(1LL<<xx-1LL);//	
				if (x<=t) break;
				x-=t;
			}
			LL t=(1LL<<xx-1);//
			x=x+c[xx];
			x=(x%t+t)%t;
			if (x==0) x=t;
			while (xx!=0)
			{
				//printf("OZY:%I64d %I64d %I64d\n",xx,x,c[xx]);
				printf("%I64d ",get(1,1,xx,get(x,xx)));
				xx--;x=(x+1)>>1LL;
			}
			printf("\n");
		}
		if (op==1)
		{
			LL x,xx;
			scanf("%I64d%I64d",&x,&xx);
			x=find(x);
			c[x]+=xx;
		}
		if (op==2)
		{
			LL x,xx;
			scanf("%I64d%I64d",&x,&xx);
			x=find(x);
		//	printf("OZY:%I64d\n",x);
			for (LL u=x;;u++)
			{
				LL t=(1LL<<u-1);
				if (t>lim) break;
				xx=(xx%t+t)%t;
				if (xx==0) xx=t;
				c[u]=c[u]+xx;
			//	printf("TYB:%I64d %I64d\n",u,xx);
				xx=xx*2;
				
				c[u]=(c[u]%t+t)%t;
				if (c[u]==0) c[u]=t;
			}
		}
	}
	return 0;
}