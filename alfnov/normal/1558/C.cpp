#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int a[3005],b[3005],c[20005],tot;
void qwq(int x)
{
	c[++tot]=x;
	for(int i=1;(i<<1)<=x;i++)swap(a[i],a[x-i+1]);
	for(int i=1;i<=x;i++)b[a[i]]=i;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,flag=1;
		tot=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]),b[a[i]]=i;
			if((i+a[i]&1))flag=0;
		}
		if(!flag)printf("-1\n");
		else
		{
			for(int i=n-1;i>=2;i-=2)
			{
				qwq(b[i+1]);
				int x=b[i];
				qwq(x-1);
				qwq(x+1);
				qwq(3);
				qwq(i+1);
			}
			printf("%d\n",tot);
			for(int i=1;i<=tot;i++)printf("%d ",c[i]);
			putchar('\n');
		}
	}
	return 0;
}