#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=100005;

int n,b1[N],b2[N];
LL sta1[N],sta2[N];
char str[N];

int main()
{
	scanf("%d",&n);
	LL ans=0;
	int top1=0,top2=0,tim=0;
	while (n--)
	{
		tim++;
		scanf("%s",str);
		if (str[0]=='f')
		{
			int x;scanf("%d",&x);
			if (x==1) sta2[++top2]=x,b2[top2]=tim;
			else sta1[++top1]=x,b1[top1]=tim;
		}
		else if (str[0]=='e')
		{
			if (b1[top1]>b2[top2]) top1--;
			else top2--;
		}
		else
		{
			LL s=1;
			for (int i=1;i<=top1;i++)
			{
				s*=sta1[i];
				if (s>=((LL)1<<32)) {puts("OVERFLOW!!!");return 0;}
			}
			ans+=s;
		}
	}
	if (ans>=((LL)1<<32)) {puts("OVERFLOW!!!");return 0;}
	else printf("%lld\n",ans);
	return 0;
}