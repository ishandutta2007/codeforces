#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int n,m,a[MAXN],b[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int tmp=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){scanf("%d",&a[i]);tmp=max(tmp,a[i]);} 
    for(int i=1;i<=m;i++)
	{
		scanf("%d",&b[i]);
		if(b[i]<tmp)return 0*printf("-1\n");
	}
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	if(a[n]==b[1])
	{
		ll sum=0;
		for(int i=1;i<=n-1;i++)sum+=1ll*a[i]*m;
		for(int i=1;i<=m;i++)sum+=b[i];
		printf("%lld\n",sum);
	}
	else
	{
		ll sum=1ll*a[n-1]*(m-1)+a[n];
		for(int i=1;i<=n-2;i++)sum+=1ll*a[i]*m;
		for(int i=1;i<=m;i++)sum+=b[i];
		printf("%lld\n",sum);
	}
    return 0;
}