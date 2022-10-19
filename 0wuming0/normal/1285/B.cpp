#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[100007];
ll b[100007];
ll c[100007];
int main()
{
    int n;
    int T;
    cin>>T;
    while(T--)
    {
        int flag=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld",a+i);
        }
        b[0]=a[0];
        if(b[0]<=0)flag=1;
        for(int i=1;i<n-1;i++)
        {
            b[i]=b[i-1]+a[i];
            if(b[i]<=0)flag=1;
        }
        c[n-1]=a[n-1];if(c[n-1]<=0)flag=1;
        for(int i=n-2;i>0;i--)
        {
            c[i]=c[i+1]+a[i];
            if(c[i]<=0)flag=1;
        }
        if(flag)printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
/*
*/