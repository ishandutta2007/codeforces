#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=1000005;

int n,c[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void ins(int x)
{
	while (x<=n) c[x]^=1,x+=x&(-x);
}

int find(int x)
{
	int ans=0;
	while (x) ans^=c[x],x-=x&(-x);
	return ans;
}

int main()
{
	n=read();
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		int x=read();
		ans^=find(n)^find(x);
		ins(x);
	}
	if ((n&1)==ans) puts("Petr");
	else puts("Um_nik");
	return 0;
}