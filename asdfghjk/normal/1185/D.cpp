#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=200005;
struct node
{
	int id,num;
}a[N];
struct mode
{
	int c,d;
}b[N];
int n,i,j,c[N],l;
bool cmp(node a,node b)
{
	return a.num<b.num;
}
bool cmq(mode a,mode b)
{
	if(a.d!=b.d)
		return a.d<b.d;
	return a.c<b.c;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i].num);
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	for(i=2;i<=n;++i)
		c[i-1]=a[i].num-a[i-1].num;
	sort(c+1,c+n);
	for(i=1;i<n;i=j)
	{
		for(j=i;j<n&&c[i]==c[j];++j);
		b[++l]=(mode){c[i],j-i};
	}
	sort(b+1,b+1+l,cmq);
	if(n==3)
	{
		printf("1");
		return 0;
	}
	if(l==1)
	{
		printf("%d",a[1].id);
		return 0;
	}
	if(l>3)
	{
		printf("-1");
		return 0;
	}
	if(l==2)
	{
		if(b[1].d>2)
			printf("-1");
		else if(b[1].d==1)
		{
			for(i=2;i<=n;++i)
				if(a[i].num-a[i-1].num==b[1].c)
					break;
			if(i==2)
				printf("%d",a[1].id);
			else if(i==n)
				printf("%d",a[n].id);
			else if(b[1].c==0)
				printf("%d",a[i].id);
			else
				printf("-1");
		}
		else if(b[1].c*2==b[2].c)
		{
			for(i=2;i<=n;++i)
				if(a[i].num-a[i-1].num==b[1].c)
					break;
			if(a[i+1].num-a[i].num==b[1].c)
				printf("%d",a[i].id);
			else
				printf("-1");
		}
		else
			printf("-1");
	}
	else if(b[1].d!=1||b[2].d!=1)
		printf("-1");
	else if(b[3].c==b[1].c+b[2].c)
	{
		for(i=2;i<=n;++i)
			if(a[i].num-a[i-1].num==b[1].c||a[i].num-a[i-1].num==b[2].c)
				break;
		if(a[i+1].num-a[i].num==b[1].c||a[i+1].num-a[i].num==b[2].c)
			printf("%d",a[i].id);
		else
			printf("-1");
	}
	else
		printf("-1");
	return 0;
}