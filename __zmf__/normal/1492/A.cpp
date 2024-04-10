#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
long long n,taxi,a,b,c,ans;
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();
		a=read(),b=read(),c=read();		
		ans=(a-n%a)%a;
		ans=min(ans,(b-n%b)%b);
		ans=min(ans,(c-n%c)%c);
		cout<<ans<<endl;
	}
	return 0;
}