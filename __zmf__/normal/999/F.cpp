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
int n,k,m,a[5009],b[5009],c[5009],cnt[100009],ans,dp[5009];
signed main()
{
	n=read(),k=read();m=n*k;
	for(int i=1;i<=m;i++)a[i]=read(),cnt[a[i]]++;
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=k;i++)c[i]=read();
	sort(b+1,b+n+1);
	int l=1,r=1;
	while(l<=n)
	{
		while(b[r+1]==b[l])r++;
		int qwq=cnt[b[l]],len=(r-l+1);
		for(int i=0;i<=n*k;i++)dp[i]=0;
		for(int i=1;i<=len;i++)
		{
			for(int j=qwq;j>=0;j--)
				for(int p=min(j,k);p>=1;p--)
					dp[j]=max(dp[j],dp[j-p]+c[p]);
		}
		int res=0;
		for(int i=1;i<=qwq;i++)res=max(res,dp[i]);
	//	cout<<qwq<<" "<<l<<" "<<r<<" "<<len<<" "<<res<<endl;
		ans+=res;
		l=r+1;
	}
	cout<<ans<<endl;
	return 0;
}