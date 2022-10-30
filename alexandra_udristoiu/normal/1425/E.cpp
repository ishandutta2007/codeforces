#include <bits/stdc++.h>

using namespace std;

const int inf=1e9;

long long dr[100010];
long long a[100010],d[100010];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&d[i]);
    long long ans=0;
    if(k>=2) {
        long long s=0;
        for(int i=1;i<=n;i++) s+=a[i];
        long long mn=inf;
        for(int i=1;i<n;i++) mn=min(mn,d[i]);
        ans=max(ans,s-mn);
        ans=max(ans,a[n]-d[n]);
        printf("%lld",ans);
        return 0;
    }
    else if(k==0) {
        long long s=0;
        for(int i=n;i>=1;i--) {
            s+=a[i];
            ans=max(ans, s-d[i]);
        }
        printf("%lld",ans);
        return 0;
    }
    else {
        long long s=0;
        for(int i=n;i>=2;i--) {
            s+=a[i];
            ans=max(ans, s-d[i]);
            dr[i-1]=ans;
        }
        s+=a[1];
        s-=d[1];
        for(int i=2;i<=n;i++) ans=max(ans,s-a[i]);
        for(int i=2;i<=n;i++) ans=max(ans,s-d[i]);
        s=a[1];
        long long mn=d[1];
        for(int i=2;i<n;i++) {
            s+=a[i];
            mn=min(mn,d[i]);
            ans=max(ans,s-mn);
            ans=max(ans,s+dr[i]-mn);
        }
        printf("%lld",ans);
        return 0;
    }
    return 0;
}