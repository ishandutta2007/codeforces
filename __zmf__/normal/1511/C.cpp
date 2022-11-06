//zhouakngyang txdy!
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,q,a[300009],pos[59],x;
signed main()
{
	n=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=n;i>=1;i--)pos[a[i]]=i;
	for(int i=1;i<=q;i++)
	{
		x=read();printf("%d ",pos[x]);
		for(int j=1;j<=50;j++)
			if(pos[j]!=0&&pos[j]<pos[x])pos[j]++;
		pos[x]=1;
	}
	return 0;
}