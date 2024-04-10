#include"bits/stdc++.h"
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c
           ,d,e,f;
        cin>>a>>b>>c>>d>>e>>f;
        int q=min(c,e);
        int ans=0;
        ans+=2*q;
        c-=q;e-=q;
        q=min(a,f);
        a-=q;
        f-=q;
        q=min(c,f);
        c-=q;
        f-=q;
        ans-=2*f;
        cout<<ans<<endl;
    }
    return 0;
}