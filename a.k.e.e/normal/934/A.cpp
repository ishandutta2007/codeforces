#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;
const int MAXN=55;
const ll INF=1ll<<60;

ll a[MAXN],b[MAXN];
int n,m;

int main()
{
	#ifdef OnCode
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    
    ll ans=INF,tmp;
    for(int i=1;i<=n;i++)
    {
    	tmp=-INF;
    	for(int j=1;j<=n;j++)
    	{
    		if(i==j)continue;
    		for(int k=1;k<=m;k++)
    			tmp=max(tmp,a[j]*b[k]);
    	}
    	ans=min(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}