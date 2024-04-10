#include"bits/stdc++.h"
using namespace std;
int ans[105],a[105],sum[105];
int main()
{
    int n,b;
    cin>>n>>b;
    for(int i=0;i<n;i++)scanf("%d",a+i);
    int t=0,nn=0;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]%2)t++;
        else t--;
        if(t==0)
        {
            ans[nn]=abs(a[i]-a[i+1]);
            nn++;
        }
    }
    sort(ans,ans+nn);
    sum[0]=0;
    for(int i=0;i<nn;i++)
        sum[i+1]=ans[i]+sum[i];
    t=nn;
    for(;;t--)
    {
        if(sum[t]<=b)
        {
            cout<<t<<endl;
            return 0;
        }
    }

    return 0;
}