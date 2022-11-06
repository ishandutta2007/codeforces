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
const int M=1e5;
int n,a[100009],pr[100009],ans,vis[100009],mu[100009],tot,qwq[100009];
inline void init()
{
    mu[1]=1;
    for(int i=2;i<=M;i++)
    {
        if(!vis[i])
        {
            mu[i]=-1;
            pr[++tot]=i;
        }
        for(int j=1;j<=tot;j++)
        {
            if(i*pr[j]>M)break;
            vis[i*pr[j]]=1;
            if(i%pr[j]==0)
            {
                mu[i*pr[j]]=0;
                break;
            }
            mu[i*pr[j]]=-mu[i];
        }
    }
} 
const int mod=1e9+7;
inline long long Pow(int x,int y)
{
	int res=1,base=x;
	while(y)
	{
		if(y%2==1)res=res*base%mod;
		base=base*base%mod;
		y=y/2;
	}
	return res;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),qwq[a[i]]++;
	init();
	ans=Pow(2,n)-1;
	for(int p=2;p<=M;p++)
	{
		int now=0,kk=0;
		for(int k=1;k<=M/p;k++)now=now+qwq[k*p];
		ans=ans+((Pow(2,now)-1)%mod*mu[p]);
		ans=ans%mod;ans=ans+mod;ans=ans%mod;
	}
	cout<<ans<<endl;
	return 0;
}