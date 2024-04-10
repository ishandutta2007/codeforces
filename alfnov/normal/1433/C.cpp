#include<bits/stdc++.h>
using namespace std;
int a[300005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)a[i]=0;
        a[0]=a[n+1]=INT_MAX;
        int mn=INT_MAX,mx=INT_MIN,w;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            mn=min(mn,a[i]);
            mx=max(mx,a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i]==mx&&(a[i]>a[i-1]||a[i]>a[i+1]))w=i;
        }
        if(mn==mx)puts("-1");
        else printf("%d\n",w);
    }
    return 0;
}