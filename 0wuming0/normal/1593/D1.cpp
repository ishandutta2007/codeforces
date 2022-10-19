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
        int k;
        scanf("%d",&k);
        n--;
        int ans=0;
        while(n--)
        {
            int u;
            scanf("%d",&u);
            ans=__gcd(u-k,ans);
        }
        ans=abs(ans);
        if(ans==0)ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}