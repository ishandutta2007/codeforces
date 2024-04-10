#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;
const int MAXN=1000005;
const ll INF=1ll<<51;

int n,m,k,s[MAXN],c,lass[MAXN];

int main()
{
    #ifdef OnCode
    //freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int x,c;
    ll ans=INF,sum;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
    	scanf("%d",&x);
    	s[x]=1;
    }
    if(s[0])
    {
    	printf("-1\n");
    	return 0;
    }
    lass[0]=0;
    for(int i=1;i<n;i++)
    	if(s[i])lass[i]=lass[i-1];
    	else lass[i]=i;
    for(int i=1;i<=k;i++)
    {
    	sum=0;
    	scanf("%d",&c);
    	for(int j=0;j<n;)
    	{
    		sum++;
    		if(j+i>=n)break;
    		if(j>=lass[j+i])
    		{
    			sum=INF;
    			break;
    		}
    		j=lass[j+i];
    	}
    	if(sum<INF)ans=min(ans,sum*c);
    }
    if(ans>=INF)cout<<"-1"<<endl;
    else cout<<ans<<endl;
    return 0;
}