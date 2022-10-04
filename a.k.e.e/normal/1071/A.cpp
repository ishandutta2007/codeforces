#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;
const int MAXN=100005;

bool vis[MAXN];

int main()
{
    #ifdef OnCode
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    ll n,m,ans=0;
    int cnt=0;
    scanf("%lld%lld",&n,&m);
    for(;ans*(ans+1)<=(n+m)*2;++ans);
    --ans;
    for(ll i=ans;i;--i)
    	if(n>=i)n-=i,vis[i]=1,++cnt;
    printf("%d\n",cnt);
    for(int i=1;i<=ans;i++)
    	if(vis[i])printf("%d ",i);
    printf("\n%d\n",ans-cnt);
    for(int i=1;i<=ans;i++)
    	if(!vis[i])printf("%d ",i);
    return 0;
}