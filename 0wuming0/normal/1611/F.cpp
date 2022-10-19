#include"bits/stdc++.h"
using namespace std;
int a[200005];
long long sum[200005];
int n,m,k;
long long maxs[3005];
int finds(int now,long long s)
{
    int bg=now;
    int aim=now/k*k;
    if(aim<now)aim+=k;
    while(now!=aim)
    {
        if(now>n)return now-bg;
        if(sum[now]>s)return now-bg;
        now++;
    }
    for(int i=now/k;i<=k+2;i++)
    {
        if(maxs[i]>s)
        {
            for(int j=k*i;;j++)
            {
                if(sum[j]>s)return j-bg;
            }
        }
    }
    return n+1-bg;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            a[i]=-a[i];
            sum[i]=sum[i-1]+a[i];
        }
        k=sqrt(n);
        for(int i=0;i<=k+2;i++)maxs[i]=-1e18;
        for(int i=1;i<=n;i++)maxs[i/k]=max(maxs[i/k],sum[i]);
        long long s=m;
        int ans=0,sl,sr;
        for(int i=0;i<=n;i++)
        {
            s+=a[i];
            int t=finds(i+1,s);
            if(t>ans)
            {
                ans=t;
                sl=i+1;
                sr=i+t;
            }
        }
        if(ans==0)printf("-1\n");
        else printf("%d %d\n",sl,sr);
    }
    return 0;
}