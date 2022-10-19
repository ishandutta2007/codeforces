#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int z;
        cin>>z;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            ans=max(ans,a|z);
        }
        cout<<ans<<endl;
    }
    return 0;
}