#include"bits/stdc++.h"
using namespace std;
#define ll long long
int a[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
        }
        sort(a,a+n);
        int ans=a[0];
        for(int i=1;i<n;i++)ans=max(a[i]-a[i-1],ans);
        cout<<ans<<endl;
    }
    return 0;
}