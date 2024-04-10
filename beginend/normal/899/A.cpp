#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=200005;

int n,a[N],t[3];

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
	for (int i=1;i<=n;i++)
	{
		int x=read();
		t[x]++;
	}
	int ans=min(t[1],t[2]);
	t[1]-=ans;t[2]-=ans;
	ans+=t[1]/3;
	printf("%d",ans);
	return 0;
}