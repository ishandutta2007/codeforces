#include<bits/stdc++.h>
using namespace std;
#define int long long
inline long long read()
{
	long long sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
long long k,x,y,ans;
int taxi;
inline long long que(long long p,long long q)
{
	if(p==0)return 0;
	long long l,r,now=q/p,pos=p;long long res=0;
	for(int i=1;i*i<=q&&i<=p;i++)res+=q/i,pos=i;
//	cout<<res<<endl;
	if(p*p<=q)return res;
	for(int i=1;i*i<=q;i++)
	{
		l=q/(i+1)+1;r=q/i;
		if(r>p)r=p;
		if(l==pos)l++;
		if(r>=l)res+=(r-l+1)*i;
	}
	return res;
}
signed main()
{
	taxi=read();
//	cout<<que(6,10)<<endl;
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		x=read(),y=read();
		k=(long long)sqrt(x+1);
		if(y<=k)
		{
			ans=(y-1)*y/2;
			cout<<ans<<endl;
			continue;
		}
		ans=(k-1)*k/2;
		if(y>=x)y=x-1;
		if(k>=x)k=x-1;
		ans=ans+que(y+1,x);
	//	cout<<ans<<endl;
		ans=ans-que(k+1,x);
		cout<<ans<<endl;
	}
	return 0;
}