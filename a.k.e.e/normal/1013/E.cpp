#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;
const int MAXN=5005;
const ll INF=0x3f3f3f3f3f3f3f3fll;

int n,a[MAXN];
ll d[MAXN][MAXN>>1|1][3];

inline int cost(int x,int y)
	{return x>y?0:y-x+1;}

int main()
{
    #ifdef OnCode
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    memset(d,0x3f,sizeof(d));
    d[1][0][0]=d[1][1][1]=0;
    for(int i=2;i<=n;i++)
    {
    	d[i][0][0]=0;
    	for(int j=1;j*2<=i+1;j++)
    	{
    		d[i][j][0]=min(d[i-1][j][0],d[i-1][j][2]);
    		d[i][j][1]=min(d[i-1][j-1][0]+cost(a[i],a[i-1]),
				d[i-1][j-1][2]+cost(a[i],min(a[i-1],a[i-2]-1)));
			d[i][j][2]=d[i-1][j][1]+cost(a[i-1],a[i]);
    	}
    }
    for(int j=1;j*2<=n+1;j++)
    {
    	ll ans=INF;
    	for(int k=0;k<3;k++)
    		ans=min(ans,d[n][j][k]);
    	cout<<ans<<" ";
    }
    return 0;
}