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
        ll res=0;
        ll now;
        scanf("%I64d",&now);
        for(int i=1;i<n;i++)
        {
            ll x;
            scanf("%I64d",&x);
            if((x<0)==(now<0)) now=max(now,x);
            else
            {
                res+=now;
                now=x;
            }
        }
        res+=now;
        printf("%I64d\n",res);
    }
    return 0;
}