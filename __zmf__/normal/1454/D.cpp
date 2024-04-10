#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
int taxi;
long long n,cnt[100009],ans[49],res,la;
signed main()
{
	taxi=read();
	for(register int kkk=1;kkk<=taxi;kkk++)
	{
		res=1;
		scanf("%lld",&n);
		la=n;
		for(register int i=1;i<=40;i++)ans[i]=1;
		for(register int i=2;i*i<=n;i++)cnt[i]=0;
		for(register int i=2;i*i<=n;i++)
			while(n%i==0)
			{
				cnt[i]++;n/=i;
			}
		if(n!=1)ans[1]=n;
		for(register int i=2;i*i<=la;i++)res=max(res,cnt[i]);
		for(register int i=2;i*i<=la;i++)
			for(register int j=1;j<=cnt[i];j++)
				ans[j]*=i;
		printf("%lld\n",res);
		for(register int i=res;i>=1;i--)printf("%lld ",ans[i]);
		puts("");
	}
	return 0;
}