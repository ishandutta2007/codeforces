#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAXN=500005;

int n,a[MAXN];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("code.in","r",stdin);
    //freopen("code.out","w",stdout);
    #endif
    int Q,op;
    scanf("%d",&Q);
    ll sum=0;int cur=0;
    double ans=0;
    while(Q--)
    {
    	scanf("%d",&op);
    	if(op==1)
		{
			scanf("%d",&a[++n]);
    		if(n==1)continue;
    		if(!cur)cur=1,sum=a[1];
    		while(cur<n-1 && (sum+a[n])*(cur+2)>(cur+1)*(sum+a[n]+a[cur+1]))
				sum+=a[++cur];
			ans=max(ans,a[n]-1.0*(sum+a[n])/(cur+1));
		}
    	else
			printf("%.9lf\n",ans);
    }
    return 0;
}