#include"bits/stdc++.h"
using namespace std;
int a[400035];
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)

    {
        int n;
        cin>>n;
        int c;
        for(int i=0;i<=2*n+10;i++)a[i]=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&c);
            a[c-i+n+2]++;
        }
        ll ans=0;
        for(int i=0;i<=2*n+10;i++)
        {
            ans+=a[i]*(ll)(a[i]-1)/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}