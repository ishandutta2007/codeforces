#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

#define N 2000200

int k[N],a[N],num[N],t[N];
int n,m,T,l;

void init()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=l;i++)
	{
		t[num[i]]=0;
		k[i]=0;
	}
	l=0;
	for (int i=1;i<=n;i++)
	{
		if (t[a[i]]==0)
		{
			l++;
			t[a[i]]=l;
			num[l]=a[i];
		}
		k[t[a[i]]]++;
	}
}

bool pd(int x)
{
	for (int i=1;i<=l;i++)
		if ((((k[i]-1)/x)+1)*(x-1)>k[i]) return false;
	return true;
}

int main()
{
	int mi;
	scanf("%d",&T);
	for (int ii=1;ii<=T;ii++)
	{
		init();
		mi=k[1];
		for (int i=2;i<=l;i++)
			mi=min(mi,k[i]);
		for (int x=mi+1;x>=1;x--)
			if (pd(x)) 
			{
				m=0;
				for (int i=1;i<=l;i++)
					m+=(k[i]+x-1)/x;
				printf("%d\n",m);
				break;
			}
	}
	return 0;
}