#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
	long long sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int taxi,flag;
long long n;
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		flag=0;
		n=read();
		for(long long i=1;i*i*i<=n;i++)
		{
			long long k=n-i*i*i,p=(long long)pow(k,0.33333334);
			if(p*p*p==k&&p!=0)
			{
				flag=1,puts("YES");break;
			}
		}
		if(!flag)puts("NO");
	}
	return 0;
}