#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll a[200005];
ll b[200005];
int n;
bool solve(ll ans)
{
    for(int i=0;i<n;i++)b[i]=a[i];
    for(int i=n-1;i>=2;i--)
    {
        if(b[i]>=ans)
        {
            b[i-1]+=min(b[i]-ans,a[i])/3;
            b[i-2]+=min(b[i]-ans,a[i])/3*2;
        }
        else return 0;
    }
    if(b[1]<ans)return 0;
    if(b[0]<ans)return 0;
    return 1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%lld",a+i);
        int l=0,r=1e9+7;
        while(l+1!=r)
        {
            int x=l+r;
            x/=2;
            if(solve(x))l=x;
            else r=x;
        }
        printf("%d\n",l);
    }
    return 0;
}