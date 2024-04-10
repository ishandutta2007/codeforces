#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=1000005;

int tim,a[N],n,b[105];

int abs(int x)
{
	return x>=0?x:-x;
}

int get_mx()
{
	int l=0,r=(int)1e9;
	while (l<=r)
	{
		int mid=(l+r)/2;
		printf("> %d\n",mid);
		fflush(stdout);
		tim--;
		int x;scanf("%d",&x);
		if (!x) r=mid-1;
		else l=mid+1;
	}
	return r+1;
}

int gcd(int x,int y)
{
	if (!y) return x;
	else return gcd(y,x%y); 
}

int main()
{
	srand(20010104);
	scanf("%d",&n);
	tim=60;
	int mx=get_mx();
	int d=0,m=std::min(tim,n);
	for (int i=1;i<=std::min(tim,n);i++)
	{
		printf("? %d\n",rand()*rand()%n+1);
		fflush(stdout);
		scanf("%d",&b[i]);
	}
	b[++m]=mx;
	for (int i=1;i<m;i++)
		for (int j=i+1;j<=m;j++)
			d=gcd(d,abs(b[i]-b[j]));
	printf("! %d %d\n",mx-(n-1)*d,d);
	fflush(stdout);
	return 0;
}