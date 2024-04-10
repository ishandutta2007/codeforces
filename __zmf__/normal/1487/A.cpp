#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,taxi,a[109],Min,ans; 
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();ans=n;Min=100;
		for(int i=1;i<=n;i++)a[i]=read(),Min=min(Min,a[i]);
		for(int i=1;i<=n;i++)if(Min==a[i])ans--;
		cout<<ans<<endl;
	}
	return 0;
}