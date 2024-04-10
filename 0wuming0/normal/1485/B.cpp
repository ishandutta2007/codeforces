#include"bits/stdc++.h"
using namespace std;
int a[100005];
int ans[100005];
int main()
{
    int n,q,k;
    cin>>n>>q>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
    }
    a[n+1]=k;
    for(int i=1;i<=n;i++)ans[i]=a[i+1]-a[i-1]-2;//for(int i=1;i<=n;i++)printf("%d%c",ans[i]," \n"[i==n]);
    for(int i=1;i<=n;i++)ans[i]+=ans[i-1];
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        long long anss=0;
        if(l==r)anss=k-1;
        else
        {
            anss=k-a[r-1]-1;
            anss+=a[l+1]-2;
            anss+=ans[r-1]-ans[l];
        }
        printf("%lld\n",anss);
    }
    return 0;
}