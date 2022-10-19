#include<cstdio>
int Test_num,n,m,k,xx,yy,sx,sy,la;
int sum[102]={};
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),read(m),read(sx),read(sy),k=n*m,xx=sx,la=yy=sy;
	for(int i=1;i<=k;++i)
	{
		++sum[xx],printf("%d %d\n",xx,yy);
		if(sum[xx]==m)
		{
			if(xx==sx)xx=0;
			if((++xx)==sx)++xx;
			la=yy;
		}
		else
		{
			if(yy==la)yy=0;
			if((++yy)==la)++yy;
		}
	}
	return 0;
}