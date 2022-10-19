#include<bits/stdc++.h>
using namespace std;
int s[100005],d[100005],vist[100005],tot=0,n,fk=100;
void print()
{
	s[1]=1;
	for(int i=2;i<=100000;i++)
	{
		if(!s[i])d[++tot]=i;
		for(int j=1;j<=tot&&i*d[j]<=100000;j++)
		{
			s[i*d[j]]=1;
			if(i%d[j]==0)break;
		}
	}
	d[tot+1]=1000000;
}
void solve(int wz,int x)
{
	for(int j=wz;j<=tot&&1ll*x*d[j]<=n;j++)
	{
		printf("A %d\n",x*d[j]);
		fflush(stdout);
		int l;
		cin>>l;
		if(!l)continue;
		solve(j,x*d[j]);
		return;
	}
	printf("C %d\n",x);
	fflush(stdout);
}
int main()
{
	print();
	cin>>n;
	int gs=0;
	for(int i=1;i<=tot&&d[i]<=n;i++)
	{
		printf("B %d\n",d[i]);
		int qwq;
		cin>>qwq;
		for(int j=1;d[i]*j<=n;j++)vist[d[i]*j]=1;
		fflush(stdout);
		if(i%fk==0||d[i+1]>n)
		{
			gs++;
			printf("A 1\n");
			fflush(stdout);
			int l;
			cin>>l;
			int ff=0;
			for(int j=1;j<=n;j++)if(!vist[j])ff++;
			if(l!=ff)
			{
				for(int j=fk*(gs-1)+1;j<=i;j++)
				{
					printf("B %d\n",d[j]);
					fflush(stdout);
					int x;
					cin>>x;
					if(x)
					{
						solve(j,d[j]);
						return 0;
					}
				}
			}
		}
	}
	printf("C 1\n");
	fflush(stdout);
	return 0;
}