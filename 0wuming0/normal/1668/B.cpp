#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int maxs=0,mins=1e9+100;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            int a;
            scanf("%d",&a);
            sum+=a;
            maxs=max(maxs,a);
            mins=min(mins,a);
        }
        if(n+sum+maxs-mins>m)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}