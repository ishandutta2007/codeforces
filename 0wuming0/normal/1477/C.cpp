#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll x[6005],y[6005];
int ans[6005];
void check(int k)
{
    if(k==1)return;
    ll x1,x2,y1,y2;
    x1=x[ans[k-1]]-x[ans[k]];
    x2=x[ans[k+1]]-x[ans[k]];
    y1=y[ans[k-1]]-y[ans[k]];
    y2=y[ans[k+1]]-y[ans[k]];
    if(x1*x2+y1*y2<=0)
    {
        swap(ans[k],ans[k-1]);
    }
    check(k-1);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld%lld",x+i,y+i);
        ans[i]=i;
    }
    for(int i=1;i<n;i++)
    {
        check(i);
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d%c",ans[i]," \n"[i==n]);
    }
    return 0;
}