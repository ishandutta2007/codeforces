#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        long long p;
        scanf("%d%I64d%d",&n,&p,&k);
        vector<long long> a(n+1,0);
        for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);
        sort(a.begin(),a.end());
        vector<long long> v(n+1,0);
        for(int i=k;i<=n;i++) v[i]=v[i-k]+a[i];
        int res=0;
        long long sum=0;
        for(int o=0;o<=n;o++)
        {
            sum+=a[o];
            if(sum>p) break;
            int l=0,r=((n-o)/k)+1;
            while(l<r-1)
            {
                int m=(l+r)/2;
                if(sum+v[o+m*k]-v[o]<=p) l=m;
                else r=m;
            }
            res=max(res,o+l*k);
        }
        printf("%d\n",res);
    }
    return 0;
}