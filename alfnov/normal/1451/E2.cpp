#include<bits/stdc++.h>
using namespace std;
int x[1000005],y[1000005];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		printf("XOR %d %d\n",i,i+1);
		fflush(stdout);
		int aa;
		cin>>aa;
		x[i+1]=x[i]^aa;
	}
	for(int i=1;i<=n;i++)y[i]=x[i];
	sort(y+1,y+n+1);
	int ls=0,t1=0,t2=0;
	for(int i=1;i<n;i++)if(y[i]==y[i+1])ls=i;
	if(!ls)
	{
		int tt1=0,tt2=0;
		for(int i=1;i<=n;i++)
		{
			if(x[i]==1)tt1=i;
			else if(x[i]+1==n)tt2=i;
		}
		printf("OR %d %d\n",1,tt1);
		fflush(stdout);
		int a1;
		cin>>a1;
		printf("AND %d %d\n",tt1,tt2);
		fflush(stdout);
		int a2;
		cin>>a2;
		int xx1=x[tt1]^((a1-a1%2)+a2);
		printf("!");
		for(int i=1;i<=n;i++)printf(" %d",xx1^x[i]);
		printf("\n");
		fflush(stdout);
		return 0;
	}
	ls=y[ls];
	for(int i=1;i<=n;i++)if(x[i]==ls)
	{
		if(t1)t2=i;
		else t1=i;
	}
	printf("AND %d %d\n",t1,t2);
	fflush(stdout);
	int yu,xxx=0;
	cin>>yu;
	xxx=yu^x[t1];
	printf("!");
	for(int i=1;i<=n;i++)printf(" %d",xxx^x[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}