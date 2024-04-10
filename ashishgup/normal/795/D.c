#include <stdio.h>
#define ll long long

int a[100001],b[100001];
int fa[100001]={0},fb[100001]={0};

int main()
{
	int n,l,r;
	scanf("%d %d %d",&n,&l,&r);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		fa[a[i]]++;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
		fb[b[i]]++;
	}
	int check=1;
	for(i=0;i<l-1;i++)
	{
		if(a[i]!=b[i])
			check=0;
	}
	for(i=r;i<n;i++)
	{
		if(a[i]!=b[i])
			check=0;
	}
	for(i=0;i<=100000;i++)
	{
		if(fa[i]!=fb[i])
			check=0;
	}
	if(check)
	{
		printf("TRUTH");
	}
	else
	{
		printf("LIE");
	}
	return 0;
}