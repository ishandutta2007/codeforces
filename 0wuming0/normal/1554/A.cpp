#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int l,a;
        long long ans=-1;
        scanf("%d",&l);
        for(int i=1;i<n;i++)
        {
            long long k;
            scanf("%d",&a);
            k=(long long)a*l;
            ans=max(ans,k);
            l=a;
        }
        printf("%lld\n",ans);
    }
    return 0;
}