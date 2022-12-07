#include<bits/stdc++.h>
using namespace std;
const int N=500;
int a[N];
int b[N];
int main()
{
	int n;
	scanf("%d",&n);
	if (n==2)
	{
		int A,B;
		scanf("%d%d",&A,&B);
		for (int u=0;u<=1;u++)
		for (int i=0;i<=1;i++)
		if ((u+i)%2!=(A+B)%2)
		{
		printf("%d %d\n%d %d\n",A,u,i,B);
		return 0;
		}
	}
	a[0]=0;
	for (int u=1;u<n;u++) a[u]=(a[u-1]+u)%n;
//	for (int u=1;u<n;u++)
//	{
//		for (int i=0;i<n;i++) printf("%d ",(a[i]-a[(i-u+n)%n]+n)%n);
//		printf("\n");
//	}
	for (int u=0;u<n;u++) scanf("%d",&b[u]);
	for (int u=0;u<n;u++)
	{
		int d=b[u]-a[(u+u)%n];
		for (int i=0;i<n;i++) printf("%d ",(a[(u+i)%n]+d+n)%n);
		printf("\n");
	}
	return 0;
}