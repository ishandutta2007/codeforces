#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[100005];
ll b[100005];
ll suma[100005];
ll sumb[100005];
int main()
{
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",a+i);
            b[n+1-i]=a[i];
        }
        for(int i=2;i<=n;i++)
        {
            if(a[i]<=a[i-1])suma[i]=a[i-1]-a[i];
            if(b[i]<=b[i-1])sumb[i]=b[i-1]-b[i];
            suma[i]+=suma[i-1];sumb[i]+=sumb[i-1];
        }
        while(q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            if(l==r)printf("0\n");
            else if(l<r)
            {
                printf("%lld\n",suma[r]-suma[l]);
            }
            else
            {
                l=n+1-l;
                r=n+1-r;
                printf("%lld\n",sumb[r]-sumb[l]);
            }
        }
    }
    return 0;
}