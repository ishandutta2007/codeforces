#include"bits/stdc++.h"
using namespace std;
int a[100005];
int up[100005];
int dn[100005];
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    int last;
    last=n;up[n]=n;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]>a[i+1])last=i,up[i]=i;
        else up[i]=last;
    }
    last=n;dn[n]=n;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]<a[i+1])last=i,dn[i]=i;
        else dn[i]=last;
    }
    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if(dn[up[l]]>=r)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}