#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int sm=0;
	for(int i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		sm^=a;
	}
	if(sm&&n%2==0)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	if(n&1)
	{
		printf("%d\n",n-1);
		for(int i=1;i<n;i+=2)printf("%d %d %d\n",i,i+1,n);
		for(int i=1;i<n;i+=2)printf("%d %d %d\n",i,i+1,n);
	}else
	{
		printf("%d\n",n-2);
		for(int i=1;i<=n-2;i+=2)printf("%d %d %d\n",i,i+1,n);
		for(int i=1;i<=n-2;i+=2)printf("%d %d %d\n",i,i+1,n);
	}
	return 0;
}