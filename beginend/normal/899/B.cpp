#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=45;

int n,a[N],d[12]={31,28,31,30,31,30,31,31,30,31,30,31},t[N];

int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read(),t[a[i]]++;
	if (t[29]>1) {puts("NO");return 0;}
	for (int i=0;i<12;i++)
	{
		int flag=0;
		for (int now=i,j=1;j<=n;j++,now=(now+1)%12)
			if (now==1)
			{
				if (a[j]!=28&&a[j]!=29) {flag=1;break;}
			}
			else
			{
				if (a[j]!=d[now]) {flag=1;break;}
			}
		if (!flag) {puts("YES");return 0;}
	}
	puts("NO");
	return 0;
}