#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int a[N],b[N],f[N];
int n,k;
int A,B;
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=2;i<=n;++i)
	{
		printf("and 1 %d\n",i);
		fflush(stdout);
		scanf("%d",&a[i]);
		printf("or 1 %d\n",i);
		fflush(stdout);
		scanf("%d",&b[i]);
	}
	printf("and 2 3\n");
	fflush(stdout);
	scanf("%d",&A);
	printf("or 2 3\n");
	fflush(stdout);
	scanf("%d",&B);
	for (int i=0;i<=30;++i)
	{
		int p=0;
		if ((1<<i)&a[2])++p;
		if ((1<<i)&b[2])++p;
		if ((1<<i)&a[3])++p;
		if ((1<<i)&b[3])++p;
		if ((1<<i)&A)--p;
		if ((1<<i)&B)--p;
		if (p)
			f[1]|=1<<i;
	}
	for (int i=2;i<=n;++i)
		f[i]=a[i]^b[i]^f[1];
	sort(f+1,f+1+n);
	printf("finish %d\n",f[k]);
	fflush(stdout);
	return 0;
}