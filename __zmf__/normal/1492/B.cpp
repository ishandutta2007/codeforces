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
int taxi,n,a[N],posi,pos[N],ans[N],cnt,now;
bool pp[N];
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();
		cnt=0,now=n;
		for(int i=1;i<=n;i++)pp[i]=0,a[i]=read(),pos[a[i]]=i;
		for(int i=n;i>=1;i--)
			if(pp[i]==0)
			{
				posi=pos[i];
				for(int j=posi;j<=now;j++)pp[a[j]]=1,ans[++cnt]=a[j];
				now=posi-1;
			}
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}