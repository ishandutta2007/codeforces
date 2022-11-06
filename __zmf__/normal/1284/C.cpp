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
int n,m;
int ans,jc[250009];
signed main()
{
	n=read(),m=read();
	jc[0]=1;
	for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i%m;
	for(int i=1;i<=n;i++)ans=(ans+jc[i]*jc[n-i+1]%m*(n-i+1)%m)%m;
	cout<<ans<<endl;
	return 0;
}