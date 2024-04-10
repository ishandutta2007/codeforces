#include"bits/stdc++.h"
using namespace std;
#define ll long long
int a[100005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        ll ans=n*(ll)(n-1)-200*n;
        for(int i=n;i>=1;i--)for(int j=i-1;j>=1;j--)
        {
            if(i*(ll)j<ans)break;
            ans=max(ans,i*(ll)j-k*(a[i]|a[j]));
        }
        printf("%lld\n",ans);
    }
    return 0;
}