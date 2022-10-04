#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=1005;

int n,m,a[MAXN][MAXN];
int t[MAXN];
int d[MAXN][MAXN],u[MAXN][MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    	for(int j=1;j<=m;j++)
    		scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
    {
    	memcpy(t,a[i],sizeof(t));
    	sort(t+1,t+m+1);
    	int k=unique(t+1,t+m+1)-t-1;
    	for(int j=1;j<=m;j++)
    	{
    		d[i][j]=lower_bound(t+1,t+k+1,a[i][j])-t-1;
    		u[i][j]=k-(lower_bound(t+1,t+k+1,a[i][j])-t);
    	}
    }
    for(int j=1;j<=m;j++)
    {
    	for(int i=1;i<=n;i++)t[i]=a[i][j];
    	sort(t+1,t+n+1);
    	int k=unique(t+1,t+n+1)-t-1;
    	for(int i=1;i<=n;i++)
    	{
    		d[i][j]=max(d[i][j],(int)(lower_bound(t+1,t+k+1,a[i][j])-t-1));
    		u[i][j]=max(u[i][j],(int)(k-(lower_bound(t+1,t+k+1,a[i][j])-t)));
    	}
    }
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    		printf("%d ",d[i][j]+u[i][j]+1);
    	printf("\n");
    }
    return 0;
}