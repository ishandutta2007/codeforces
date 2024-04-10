#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=10005;
const int inf=100000000;

int t,a[N],b[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int ask(int x,int y)
{
	printf("0 %d %d\n",x,y);
	fflush(stdout);
	return read();
}

int main()
{
	srand(20010104);
	t=rand()*rand()-rand()*rand();
	while (!ask(t,t)) t=rand()*rand()-rand()*rand();
	int x=-inf+ask(-inf,-inf),a1=0,b1=0,step=7000;;
	while (x<=inf)
	{
		if (!ask(x,t)) a[++a1]=x;
		if (!ask(t,x)) b[++b1]=x;
		while (x+step<=inf&&ask(x+step,x+step)>=step) x+=step;
		x++;
		while (x<=inf)
		{
			int d=ask(x,x);
			if (!d) break;
			x+=d;
		}
	}
	printf("%d %d %d\n",1,a1,b1);
	for (int i=1;i<=a1;i++) printf("%d ",a[i]);
	puts("");
	for (int i=1;i<=b1;i++) printf("%d ",b[i]);
	return 0;
}