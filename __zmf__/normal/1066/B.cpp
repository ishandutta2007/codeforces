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
int taxi,n,a[3009],r,vis[3009],ans;
signed main()
{
	n=read();r=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			for(int j=i+r-1;j>=i-r+1&&j>=0;j--)
				if(a[j]==1)
				{
					for(int k=i;k<=j;k++)vis[k]=1;
					for(int k=j;k<=j+r-1;k++)
					{
						vis[k]=1;
					}
					ans++;break;
				}
			if(vis[i]==0)
			{
				puts("-1");return 0;
			}
		}
	cout<<ans<<endl;
	return 0;
}