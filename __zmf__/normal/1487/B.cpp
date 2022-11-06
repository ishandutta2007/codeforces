#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
long long n,taxi,k,qwq,hsy; 
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read(),k=read();
		if(n%2==0)
		{
			printf("%lld\n",(k-1)%n+1);
			continue;
		}
		else
		{
			qwq=n*(n/2);k=(k-1)%qwq+1;
			hsy=(k-1)/(n/2);
			//cout<<k<<" "<<hsy<<endl;
			printf("%lld\n",(k+hsy-1)%n+1);
			continue;
		}
	}
	return 0;
}