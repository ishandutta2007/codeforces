#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=7005;
int n,b[N],vis[N],s[N];ll a[N],ans;
int main()
{
	scanf("%d",&n);int tt=n;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)s[i]+=(a[i]&a[j])!=a[i];
	for(int i=1;i<=n;i++)vis[i]=1,ans+=b[i];
	while(true)
	{
		int x=0;for(int i=1;i<=n;i++)if(vis[i]&&s[i]==tt-1){x=i;break;}
		if(!x)break;ans-=b[x];tt--;vis[x]=0;
		for(int i=1;i<=n;i++)if((a[i]&a[x])!=a[i])s[i]--;
	}
	printf("%lld\n",ans);
	return 0;
}