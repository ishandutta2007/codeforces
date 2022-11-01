#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll a,b;
        int q;
        scanf("%I64d%I64d%d",&a,&b,&q);
        ll k=lcm(a,b);
        map<array<ll,2>,int> ord;
        vector<ll> sum(k,0);
        for(ll i=0;i<k;i++)
        {
            ord[{i%a,i%b}]=i;
            if(i>0) sum[i]=sum[i-1];
            sum[i]+=(((i%a)%b)!=((i%b)%a));
        }
        auto solve=[&](ll l,ll r)->ll
        {
            int one=ord[{l%a,l%b}];
            int two=ord[{r%a,r%b}];
            ll res=0;
            if(one<=two)
            {
                res=sum[two];
                if(one>0) res-=sum[one-1];
            }
            else res=sum[k-1]-sum[one-1]+sum[two];
            return res;
        };
        while(q--)
        {
            ll l,r;
            scanf("%I64d%I64d",&l,&r);
            ll x=(l-(l%k));
            if((l%k)>0) x+=k;
            ll y=(r-(r%k));
            ll res=0;
            if(x>y) res=solve(l,r);
            else
            {
                res+=(((y-x)/k)*sum[k-1]);
                if(l<x) res+=solve(l,x-1);
                res+=solve(y,r);
            }
            printf("%I64d ",res);
        }
        printf("\n");
    }
    return 0;
}