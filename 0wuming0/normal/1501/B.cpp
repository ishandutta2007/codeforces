#include"bits/stdc++.h"
using namespace std;
int a[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
        }
        int now=0;
        for(int i=n;i>=1;i--)
        {
            now--;
            now=max(now,a[i]);
            a[i]=now;
        }
        for(int i=1;i<=n;i++)if(a[i])a[i]=1;
        for(int i=1;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
    }
    return 0;
}