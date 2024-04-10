#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int a[54]={0};
        cin>>n;
        for(int i=0;i<n;i++)scanf("%d",a+i);
        int ans=0;
        for(int i=1;i<n;i++)
        {
            int maxs=max(a[i],a[i-1]),mins=min(a[i],a[i-1]);
            while(mins*2<maxs)
            {
                ans++;
                mins*=2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}