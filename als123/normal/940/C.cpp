#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=100005;
int n,k;
int a[N];
int b[N];
int belong[N];
int main()
{
	scanf("%d%d",&n,&k);
	for (int u=1;u<=n;u++)
	{
		char ch=getchar();
		while (ch<'a'||ch>'z') ch=getchar();
		b[u]=a[u]=ch-'a';
	}
	sort(b+1,b+1+n);
	int nn=1;
	for (int u=2;u<=n;u++)
		if (b[u]!=b[nn])
			b[++nn]=b[u];
	for (int u=1;u<=nn;u++) belong[b[u]]=u;
	if (n<k)
	{
		for (int u=1;u<=n;u++) printf("%c",a[u]+'a');
		for (int i=n+1;i<=k;i++) printf("%c",b[1]+'a');
		return 0;
	}
	int kk=k;
	while (true)
	{
		if (belong[a[k]]!=nn)
		{
			a[k]=b[belong[a[k]]+1];
			break;
		}
		a[k]=b[1];
		k--;
	}
	for (int u=1;u<=kk;u++)  printf("%c",a[u]+'a');
	return 0;
}