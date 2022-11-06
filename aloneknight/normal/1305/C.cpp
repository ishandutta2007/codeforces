#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,ans,a[1005];
int main()
{
	scanf("%d%d",&n,&m);ans=1;
	if(n>m){puts("0");return 0;}
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)ans=1ll*ans*abs(a[i]-a[j])%m;
	printf("%d\n",ans);return 0;
}