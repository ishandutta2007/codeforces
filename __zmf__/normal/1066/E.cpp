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
int n,m,cnt[2000009],tot=1,ans,mod=998244353;
char a[2000009],b[2000009];
signed main()
{
	n=read(),m=read();
	cin>>a>>b;
	for(int i=0;i<m;i++)
	{
		if(b[i]=='1')cnt[i]=cnt[i-1]+1;
		else cnt[i]=cnt[i-1];
	}
	for(int i=n-1;i>=0;i--)
	{
		if(a[i]=='1')
			ans=(ans+cnt[m-1-(n-1-i)]*tot%mod)%mod;
		tot=tot*2%mod;
	}
	cout<<ans<<endl;
	return 0;
}