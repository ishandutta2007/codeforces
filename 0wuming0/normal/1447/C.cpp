#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll ans[200005],nn;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        ll m0=m;
        m=(m+1)/2;
        ll sum=0,numi=0;
        nn=0;
        for(int i=1;i<=n;i++)
        {
            ll q;
            scanf("%lld",&q);
            if(q>m0)continue;
            if(q>=m)numi=i;
            else if(sum<m)
            {
                sum+=q;
                ans[nn++]=i;
            }
        }
        if(numi)printf("1\n%lld\n",numi);
        else if(sum>=m)
        {
            printf("%lld\n",nn);
            for(int i=0;i<nn;i++)printf("%lld%c",ans[i]," \n"[i==nn-1]);
        }
        else printf("-1\n");
    }
    return 0;
}