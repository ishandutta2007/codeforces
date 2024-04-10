#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int n,tot,ans[105];

int read()
{
    int x=0,f=1;char ch=getchar();
    while (ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

int get(int x)
{
	int ans=0;
	while (x) ans+=x%10,x/=10;
	return ans;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=min(n,81);i++)
	{
		if (get(n-i)==i) ans[++tot]=n-i;
	}
	printf("%d\n",tot);
	for (int i=tot;i>=1;i--) printf("%d ",ans[i]);
	return 0;
}