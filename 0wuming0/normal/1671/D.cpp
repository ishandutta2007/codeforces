#include"bits/stdc++.h"
using namespace std;
int a[201005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long ans=0;
        int n,x;
        scanf("%d%d",&n,&x);
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        int l=2e5+7,r=0;
        for(int i=2;i<=n;i++)ans+=abs(a[i]-a[i-1]);
        for(int i=1;i<=n;i++)
        {
            l=min(l,a[i]);
            r=max(r,a[i]);
        }
        if(l>=1)
        {
            int add=min(abs(a[1]-1),abs(a[n]-1));
            for(int i=1;i<n;i++)
            {
                add=min(abs(a[i]-1)+abs(a[i+1]-1)-abs(a[i]-a[i+1]),add);
            }
            ans+=add;
        }
        if(r<=x)
        {
            int add=min(abs(a[1]-x),abs(a[n]-x));
            for(int i=1;i<n;i++)
            {
                add=min(abs(a[i]-x)+abs(a[i+1]-x)-abs(a[i]-a[i+1]),add);
            }
            ans+=add;
        }
        cout<<ans<<endl;
    }
    return 0;
}