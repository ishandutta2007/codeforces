#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef long long LL;

const int N=1000005;
const int mo1=998244353;
const int mo2=1000000007;

int n,t1,t2,po1[N],po2[N],ny1[N],ny2[N],h1[N],h2[N],hash1[N],hash2[N],a[N],b[N];
char str[N];

int ksm(int x,int y,int mo)
{
	int ans=1;
	while (y)
	{
		if (y&1) ans=(LL)ans*x%mo;
		x=(LL)x*x%mo;y>>=1;
	}
	return ans;
}

bool check(int x,int y,int len)
{
	int p=(LL)(hash1[t1]+mo1-hash1[t1-len])*ny1[t1-len]%mo1;
	int q=(LL)(hash2[t1]+mo2-hash2[t1-len])*ny2[t1-len]%mo2;
	return x==p&&y==q;
}

int main()
{
	
	srand(20010104);
	int bas1=rand()+100,bas2=rand()+100;
	po1[0]=po2[0]=ny1[0]=ny2[0]=1;
	int n1=ksm(bas1,mo1-2,mo1),n2=ksm(bas2,mo2-2,mo2);
	for (int i=1;i<=1000000;i++) po1[i]=(LL)po1[i-1]*bas1%mo1,po2[i]=(LL)po2[i-1]*bas2%mo2;
	for (int i=1;i<=1000000;i++) ny1[i]=(LL)ny1[i-1]*n1%mo1,ny2[i]=(LL)ny2[i-1]*n2%mo2;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",str+1);
		t2=strlen(str+1);
		for (int j=1;j<=t2;j++) b[j]=str[j];
		for (int j=1;j<=t2;j++) h1[j]=(h1[j-1]+(LL)po1[j-1]*b[j]%mo1)%mo1,h2[j]=(h2[j-1]+(LL)po2[j-1]*b[j]%mo2)%mo2;
		int pos=1;
		for (int j=std::min(t1,t2);j>=1;j--) if (check(h1[j],h2[j],j)) {pos=j+1;break;}
		for (int j=pos;j<=t2;j++)
		{
			a[++t1]=b[j];
			hash1[t1]=(hash1[t1-1]+(LL)po1[t1-1]*a[t1]%mo1)%mo1;
			hash2[t1]=(hash2[t1-1]+(LL)po2[t1-1]*a[t1]%mo2)%mo2;
		}
	}
	for (int i=1;i<=t1;i++) putchar(a[i]);
	return 0;
}