#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
const int N=1e5+9;
int q,n,a[N],tot[10],opt,x;
int main()
{
//	taxi=read();
	n=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read(),tot[a[i]]++;
	for(int i=1;i<=q;i++)
	{
		opt=read(),x=read();
		if(opt==1)tot[a[x]]--,a[x]=1-a[x],tot[a[x]]++;
		else 
		{
			if(tot[1]>=x)puts("1");
			else puts("0");
		}
	}
	return 0;
}