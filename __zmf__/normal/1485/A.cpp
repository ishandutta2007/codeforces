#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int n,taxi;
long long a,b,now,cnt,ans; 
inline long long val(long long x,long long y)
{
	long long res=0;
	while(y!=0)y=y/x,res++;
	return res;
}
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		ans=0,now=0;
		a=read();b=read();
		if(b==1)b++,ans++;
		if(b<=10)
		{
			now=val(b,a);
			//cout<<now<<endl;
			for(int i=b+1;i<=10;i++)
			{
				now=min(now,val(i,a)+i-b);
			}
			ans=ans+now;
			cout<<ans<<endl;
		}
		else
		{
			while(a!=0)a=a/b,ans++;
			cout<<ans<<endl;
		}
	}
	return 0;
}