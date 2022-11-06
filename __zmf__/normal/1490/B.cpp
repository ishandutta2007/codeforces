#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int taxi,flag,pos,n,a[30009],cnt[3];
int main()
{
	taxi=read();
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		n=read();
		flag=0;
		for(int i=0;i<3;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)a[i]=read(),cnt[a[i]%3]++;
		for(int i=0;i<3;i++)cnt[i]=cnt[i]-n/3;
		for(int i=0;i<3;i++)
			if(cnt[i]<0)flag++;
		if(flag==0)
		{
			printf("0\n");continue;
		}
		else if(flag==1)
		{
			for(int i=0;i<3;i++)
				if(cnt[i]<0)pos=i;
			printf("%d\n",-cnt[pos]+cnt[(pos+1)%3]);
		}
		else
		{
			for(int i=0;i<3;i++)
				if(cnt[i]>0)pos=i;
			printf("%d\n",cnt[pos]-cnt[(pos+2)%3]);
		}
	}
	return 0;
}