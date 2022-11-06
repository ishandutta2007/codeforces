//zhouakngyang txdy!
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
int n,k,a[200009],w[200009],ans,taxi;
inline bool cmp(int xxx,int yyy)
{
	return xxx>yyy;
}
signed main()
{
	cin>>taxi;
	for(int ttt=1;ttt<=taxi;ttt++)
	{
		ans=0;
		n=read(),k=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=k;i++)w[i]=read();
		sort(a+1,a+n+1,cmp);
		sort(w+1,w+k+1,cmp);
		int l=n,r=1;
		for(int i=1;i<=k;i++)
			if(w[i]==1)ans=ans+a[r]*2,r=r+1;
		for(int i=1;i<=k;i++)
		{
			if(w[i]==1)continue;
			ans=ans+a[r]+a[l],r=r+1,l=l-w[i]+1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}