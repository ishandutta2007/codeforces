#include"bits/stdc++.h"
using namespace std;
int a[1005];
int nn;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            scanf("%d",a+i);
        }
        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }
        int ans=1e9;
        for(int l=0;l<n;l++)for(int r=l+1;r<n;r++)
        {
            int d=a[r]-a[l],e=r-l;
            int now=0;
            for(int i=0;i<n;i++)
            {
                if(a[i]*e+(l-i)*d!=a[l]*e)now++;
            }
            ans=min(ans,now);
        }
        cout<<ans<<endl;
    }
    return 0;
}