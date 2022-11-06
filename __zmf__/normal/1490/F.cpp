#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int taxi,n,a[200009],p[200009],cnt,now,tot[200009],ans;
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();now=1,cnt=0;ans=n;
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++)
		{
			if(a[i]!=a[i-1])p[++cnt]=now,now=1;
			else now++;
		}
		p[++cnt]=now;
		sort(p+1,p+cnt+1);
		p[0]=0;
		tot[1]=cnt;
		for(int i=1;i<=cnt;i++)
			for(int j=p[i-1]+1;j<=p[i];j++)
				tot[j]=cnt-(i-1);
	//	for(int i=1;i<=p[cnt];i++)cout<<tot[i]<<" ";
	//	cout<<endl;
		for(int i=1;i<=p[cnt];i++)ans=min(ans,n-i*tot[i]);
		printf("%d\n",ans);
		for(int i=1;i<=cnt;i++)p[i]=0;
	}
	return 0;
}