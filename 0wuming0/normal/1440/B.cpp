#include"bits/stdc++.h"
using namespace std;
long long ans=0;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;ans=0;
        cin>>n>>k;
        int c=(n+2)/2;
        for(int i=0;i<n*k;i++)
        {
            int q;
            scanf("%d",&q);
            if(n*k-c*k<=i&&(n*k-i)%c==0)
            {
                ans=ans+q;
                //cout<<i<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}