#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[101010];
int b[101010];
bool check(double x)
{
	double tmp=x;
	tmp-=(tmp+m)/a[1];
	if(tmp<0)
		return 0; 
	for(int i=2;i<=n;i++)
	{
		tmp-=(tmp+m)/b[i];
		if(tmp<0)
			return 0;
		tmp-=(tmp+m)/a[i];
		if(tmp<0)
			return 0;
	}
	tmp-=(tmp+m)/b[1];
	if(tmp<0)
		return 0;
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	double l=0,r=1e10;
	int T=100;
	while(T--)
	{
		double m=(l+r)/2;
		if(check(m))
			r=m;
		else
			l=m;
	}
	if(l>1e9)
		puts("-1");
	else
		printf("%.10f\n",l);
	return 0;
}