#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=100005;

int n;
int c[MAXN],a[MAXN];
int p[MAXN];
bool cmp(int x,int y)
	{return c[x]==c[y]?x<y:c[x]<c[y];}

int main()
{
    int Q,d,t;
    scanf("%d%d",&n,&Q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)p[i]=i;
    sort(p+1,p+n+1,cmp);
    int cur=1;
    while(Q--)
    {
    	ll ans=0;
    	scanf("%d%d",&t,&d);
    	if(a[t]>=d)
			a[t]-=d,ans+=(ll)c[t]*d;
    	else
    	{
    		ans+=(ll)a[t]*c[t];
    		d-=a[t];
    		a[t]=0;
    		while(cur<=n)
    		{
    			int u=p[cur];
    			if(a[u]>=d)
				{
					a[u]-=d;
					ans+=(ll)c[u]*d;
					break;
				}
    			else
				{
					d-=a[u];
					ans+=(ll)c[u]*a[u];
					a[u]=0;
				}
    			++cur;
    		}
    		if(cur>n)ans=0;
    	}
    	cout<<ans<<endl;
    }
    return 0;
}