#include<bits/stdc++.h>
#define eps 1e-10
#define inf 0x3f3f3f3f
using namespace std;
double x,y,z,w;
int mx=0;
double a[3],b[9];
inline void print(int x)
{
	if(!x)printf("x^y^z");
	else if(x==1)printf("x^z^y");
	else if(x==2)printf("(x^y)^z");
	else if(x==3)printf("y^x^z");
	else if(x==4)printf("y^z^x");
	else if(x==5)printf("(y^x)^z");
	else if(x==6)printf("z^x^y");
	else if(x==7)printf("z^y^x");
	else printf("(z^x)^y");
}
int main()
{
	scanf("%lf%lf%lf",&x,&y,&z),a[0]=log(x),a[1]=log(y),a[2]=log(z),w=max(a[0],max(a[1],a[2]));
	if(w<0)
	{
		b[0]=z*log(y)+log(-log(x));
		b[1]=y*log(z)+log(-log(x));
		b[2]=log(y)+log(z)+log(-log(x));
		b[3]=z*log(x)+log(-log(y));
		b[4]=x*log(z)+log(-log(y));
		b[5]=log(x)+log(z)+log(-log(y));
		b[6]=y*log(x)+log(-log(z));
		b[7]=x*log(y)+log(-log(z));
		b[8]=log(x)+log(y)+log(-log(z));
		for(int i=1;i<=8;++i)if(b[i]<b[mx])mx=i;
	}
	else if(abs(w)<eps)for(int i=0;i<3;++i){if(abs(a[i])<eps){mx=3*i;break;}}
	else
	{
		if(log(x)>0)
		{
			b[0]=z*log(y)+log(log(x));
			b[1]=y*log(z)+log(log(x));
			b[2]=log(y)+log(z)+log(log(x));
		}
		else b[0]=b[1]=b[2]=-inf;
		if(log(y)>0)
		{
			b[3]=z*log(x)+log(log(y));
			b[4]=x*log(z)+log(log(y));
			b[5]=log(x)+log(z)+log(log(y));
		}
		else b[3]=b[4]=b[5]=-inf;
		if(log(z)>0)
		{
			b[6]=y*log(x)+log(log(z));
			b[7]=x*log(y)+log(log(z));
			b[8]=log(x)+log(y)+log(log(z));
		}
		else b[6]=b[7]=b[8]=-inf;
		for(int i=1;i<=8;++i)if(b[i]>b[mx])mx=i;
	}
	print(mx);
	return 0;
}