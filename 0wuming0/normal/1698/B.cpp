#include"bits/stdc++.h"
using namespace std;
int a[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
        }
        if(k==1)
        {
            cout<<(n-1)/2<<endl;
            continue;
        }
        int ans=0;
        for(int i=2;i<n;i++)if(a[i]>a[i-1]+a[i+1])ans++;
        cout<<ans<<endl;
    }
    return 0;
}