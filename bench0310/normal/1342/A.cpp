#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll x,y,a,b;
        scanf("%I64d%I64d%I64d%I64d",&x,&y,&a,&b);
        ll res=0;
        res+=min(x,y)*min(b,2*a);
        res+=(max(x,y)-min(x,y))*a;
        printf("%I64d\n",res);
    }
    return 0;
}