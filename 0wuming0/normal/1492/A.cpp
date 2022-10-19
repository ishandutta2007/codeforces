#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long a,b,c,d,ans;
        cin>>a>>b>>c>>d;
        ans=b-(a-1)%b-1;
        ans=min(c-(a-1)%c-1,ans);
        ans=min(d-(a-1)%d-1,ans);
        cout<<ans<<endl;
    }
    return 0;
}