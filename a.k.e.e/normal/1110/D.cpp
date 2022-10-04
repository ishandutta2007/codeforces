#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=1000005,INF=1<<30;

int n,m,a[MAXN];
int f[15][15][15],d[15][15],tmp[15][15];

int main()
{
    int x;
    scanf("%d%d",&n,&m);
    ++m;
    for(int i=1;i<=n;i++)
    {
    	scanf("%d",&x);
    	++a[x+1];
    }
    for(int i=2;i<=m;i++)
    {
    	//int ans=-INF;
    	for(int x0=0;x0<=6 && x0<=a[i];++x0)
    		for(int x1=0;x1<=6 && x1<=a[i-1];++x1)
    		{
    			d[x0][x1]=-INF;
    			for(int x2=0;x2<=6 && x2<=a[i-2];++x2)
    			{
    				f[x0][x1][x2]=-INF;
    				for(int t=0;t<=2&&t+x0<=a[i]&&t+x1<=a[i-1]&&t+x2<=a[i-2];t++)
    					f[x0][x1][x2]=max(f[x0][x1][x2],
							tmp[x1+t][x2+t]+t+(a[i]-x0-t)/3);
    				d[x0][x1]=max(d[x0][x1],f[x0][x1][x2]);
    			}
    			//ans=max(ans,d[x0][x1]);
    		}
    	memcpy(tmp,d,sizeof(tmp));
    	//cout<<a[i]<<" "<<ans<<endl;
    }
    int ans=0;
	for(int x0=0;x0<=6 && x0<=a[m];++x0)
		for(int x1=0;x1<=6 && x1<=a[m-1];++x1)
			ans=max(ans,d[x0][x1]);
	printf("%d\n",ans);
    return 0;
}