#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long double ld;

int n;
ld a[105];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ld w=1-a[n],s=a[n];
	for (int i=n-1;i>=1;i--)
	{
		ld t=s*(1-a[i])+a[i]*w;
		if (t<s) break;
		s=t;w*=1-a[i];
	}
	printf("%.12lf",(double)s);
	return 0;
}