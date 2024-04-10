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
const int mod=1e9+7;
int n,k,res,k1,k2,ans;
char a[1009],b[1009];
inline int Pow(int x,int y)
{
	int res=1,base=x;
	while(y)
	{
		if(y&1)res=res*base%mod;
		base=base*base%mod;
		y>>=1;
	}
	return res;
}
signed main()
{
	scanf("%s",a+1);scanf("%s",b+1);
	n=strlen(a+1);k=read();
//	cout<<6*Pow(6,mod-2)%mod<<endl;
	if(k%2==1)k2=(Pow(n-1,k)+1)%mod*Pow(n,mod-2)%mod,k1=k2-1;
	else k2=(Pow(n-1,k)-1+mod)%mod*Pow(n,mod-2)%mod,k1=k2+1;
	//cout<<k1%mod<<" "<<k2%mod<<endl;
	for(int i=1;i<=n;i++)
	{
		int flag=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]!=b[(i+j-2+n)%n+1])flag=1;
		}
		if(flag==0&&i==1)ans=(ans+k1)%mod;
		else if(flag==0)ans=(ans+k2)%mod;
	}
	cout<<ans<<endl;
	return 0;
}