#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll atk[100005];
ll h[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,n;
        scanf("%lld",&a);
        scanf("%lld",&b);
        scanf("%lld",&n);
        ll best=0;
        for(int i=0;i<n;i++)scanf("%lld",atk+i);
        for(int i=0;i<n;i++)scanf("%lld",h+i);
        for(int i=0;i<n;i++)best=max(best,atk[i]);
        for(int i=0;i<n;i++)
        {
            ll c=h[i]/a;
            if(h[i]%a)c++;
            b-=atk[i]*c;
            if(b<=-best)
            {
                printf("NO\n");
                goto ne;
            }
        }
        printf("YES\n");
        ne:;
    }
    return 0;
}