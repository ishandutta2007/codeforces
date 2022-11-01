#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=200005;

int n;
bool pd[N];
char str[N];

int gcd(int x,int y)
{
	if (!y) return x;
	else return gcd(y,x%y);
}

bool check(int x)
{
	for (int i=0;i<x;i++)
	{
		int s=0;
		for (int j=i;j<n;j+=x) if (str[j]=='1') s^=1;
		if (s) return 0;
	}
	return 1;
}

int main()
{
	scanf("%d",&n);
	scanf("%s",str);
	for (int i=1;i<=n;i++)
		if (n%i==0) pd[i]=check(i);
	int s=0,ans=0;
	for (int i=0;i<n;i++) if (str[i]=='0') s++;
	if (s==n) ans++;
	for (int i=1;i<n;i++)
		if (pd[gcd(n,i)]) ans++;
	printf("%d\n",ans);
	return 0;
}