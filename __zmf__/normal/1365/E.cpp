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
int n,ans;
int a[509];
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	n+=2;
	for(int i=n-1;i<=n;i++)a[i]=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				ans=max(ans,(a[i]|a[j]|a[k]));
	cout<<ans<<endl;		
	return 0;
}