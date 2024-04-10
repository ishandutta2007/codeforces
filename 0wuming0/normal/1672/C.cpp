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
        int l=1e9,r=-1;
        for(int i=1;i<=n;i++)scanf("%d",a+i);
        for(int i=2;i<=n;i++)
        {
            if(a[i]==a[i-1])
            {
                l=min(l,i);
                r=max(r,i);
            }
        }
        if(r==-1)r=l;
        int ans=r-l;
        if(ans>=2)ans--;
        cout<<ans<<endl;
    }
    return 0;
}