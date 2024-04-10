#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=30005;

int n,mod,fib[MAXN],a[MAXN],p[MAXN];
int wcnt[33005];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int Q,l,r;
    scanf("%d%d",&n,&mod);
    fib[1]=fib[2]=1;
    for(int i=3;i<=n;i++)fib[i]=(fib[i-1]+fib[i-2])%mod;
    for(int i=1;i<=n;i++)
    	{scanf("%d",&a[i]);p[i]=a[i];}
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++)
    	a[i]=lower_bound(p+1,p+n+1,a[i])-p;
    for(int i=1;i<=n;i++)p[i]%=mod;
    ll ans;int cur;
    scanf("%d",&Q);
    for(int kase=1;kase<=Q;kase++)
    {
    	ans=cur=0;
    	scanf("%d%d",&l,&r);
    	for(register int i=l;i<=r;++i)wcnt[a[i]]=kase;
    	for(register int i=1;i<=n;++i)
    		if(wcnt[i]==kase)ans+=p[i]*fib[++cur];
    	printf("%d\n",(int)(ans%mod));
    }
    return 0;
}