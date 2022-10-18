#include<cstdio>

int a[1000];
bool in[1000];

int prime(int x,int y)
{
	int tmp;
	while(x && y)
	{
		if(x<y) tmp=y,y=x,x=tmp;
		x = x%y;
	}
	return y;
}

int main()
{
	int n,insert=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n-1;i++)
	{
		if(prime(a[i],a[i+1])!=1) 
		{
			insert++;
			in[i]=true;
		}	
	}
	printf("%d\n%d",insert,a[0]);
	for(int i=1;i<n;i++)
	{
		if(in[i-1]) printf(" 1");
		printf(" %d",a[i]);
	}
	return 0;
}