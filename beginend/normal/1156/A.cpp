#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=105;

int n,a[N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int ans=0;
	for (int i=2;i<=n;i++)
	{
		int x=a[i-1],y=a[i];
		if (x>y) std::swap(x,y);
		if (x==2) {puts("Infinite");return 0;}
		if (y==2) ans+=3;
		else ans+=4;
	}
	for (int i=2;i<n;i++)
		if (a[i]==1&&a[i-1]==3&&a[i+1]==2) ans--;
	puts("Finite");
	printf("%d\n",ans);
	return 0;
}