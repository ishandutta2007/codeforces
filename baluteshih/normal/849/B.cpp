#include <stdio.h>
#include <string.h>

int main()
{
	long long n,i,j,arr[1050],x,d,dd,tmp;
	bool has[1050];
	scanf("%lld",&n);
	for(i=0;i<n;i++)
		scanf("%lld",&arr[i]);
	for(i=1;i<n;i++)
	{
		memset(has,0,sizeof(has));
		has[0]=1,has[i]=1,d=arr[i]-arr[0],x=i,tmp=n-2;
		for(j=i+1;j<n;j++)
			if((arr[j]-arr[x])*i==d*(j-x)) has[j]=1,tmp--,x=j;
		if(!tmp)
		{
			i=n+1;
			break;
		}
		if(tmp==1) break;
		for(j=0;j<n;j++)
			if(!has[j]) break;
		x=j;
		for(;j<n;j++)
		{
			if(!has[j])
			{
				if((arr[j]-arr[x])*i!=d*(j-x)) break;
				x=j;
			}
		}
		if(j==n) break;
	}
	//printf("%d\n",i);
	if(i==n+1) printf("No\n");
	else if(i<n) printf("Yes\n");
	else
	{
		d=arr[2]-arr[1],x=2;
		for(j=3;j<n;j++)
			if((arr[j]-arr[j-1])!=d) break;
		if(j==n) printf("Yes\n");
		else printf("No\n");
	}
}