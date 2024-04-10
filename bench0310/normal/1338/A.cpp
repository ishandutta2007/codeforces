#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<ll> v(n,0);
        for(int i=0;i<n;i++) scanf("%I64d",&v[i]);
        bool b=1;
        for(int i=0;i<n-1;i++) if(v[i]>v[i+1]) b=0;
        if(b==1)
        {
            printf("0\n");
            continue;
        }
        for(int i=1;i<=60;i++)
        {
            bool ok=1;
            ll x=(1ll<<i)-1;
            ll now=v[n-1]+x;
            for(int j=n-2;j>=0;j--)
            {
                if(v[j]>now) ok=0;
                if(v[j]+x<=now) now=v[j]+x;
            }
            if(ok)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}