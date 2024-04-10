#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=300005;

int n;
struct data{int x,y,id;}a[N],b[N];

bool cmpx(data a,data b)
{
	return a.x>b.x;
}

bool cmpy(data a,data b)
{
	return a.y<b.y;
}

int main()
{
	scanf("%d",&n);
	int t1=0,t2=0;
	for (int i=1;i<=n;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		if (x<y) a[++t1]=(data){x,y,i};
		else b[++t2]=(data){x,y,i};
	}
	std::sort(a+1,a+t1+1,cmpx);
	std::sort(b+1,b+t2+1,cmpy);
	printf("%d\n",std::max(t1,t2));
	if (t1>t2) for (int i=1;i<=t1;i++) printf("%d ",a[i].id);
	else for (int i=1;i<=t2;i++) printf("%d ",b[i].id);
	puts("");
	return 0;
}